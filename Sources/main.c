/* ###################################################################
**     Filename    : main.c
**     Project     : IOM_C
**     Processor   : MC9S08PA4VTJ
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2015-01-31, 11:51, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.12
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "AS1.h"
#include "Signal_Out.h"
#include "PWM_Output.h"
#include "Button_Start.h"
#include "Button_Stop.h"
#include "LED_Status.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

uint8_t UART_TXBuf[32]={0};
uint8_t UART_RXBuf[32]={0};
uint8_t TXData[20]={0};

uint8_t UT_SN=0;

void BVA_Cycles(void);
void TX_Report(uint8_t * Data, uint8_t Count);
uint8_t RX_Frame(void);
uint8_t RX_Poll(void);

#define Test_Cycle_Time 100						// Cycle time, in 10mS.
// Test_Cycles[][2] defines the test output patterns.
// Test_Cycles[][0] is the PWM output duty cycle definition: 0-> 0%, 50-> 50% and 100 (or above)-> 100%.
// Test_Cycles[][1] bits 2-0 are the Signal_Out[2]-[0].
#define Test_Cycle_Num 8
uint8_t Test_Cycles[Test_Cycle_Num][2]={
		{ 0, 0},
		{10, 1},
		{20, 2},
		{30, 3},
		{50, 4},
		{70, 5},
		{90, 6},
		{100, 7}
};

void main(void)
{
  /* Write your local variable definition here */

	
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  
  Cpu_Delay100US(100);						//Delay 10ms
  
  //Start main loop...
  
  for(;;){
	  
	  while(RX_Frame()!=ERR_OK){
		  //Check if any key pressed.
		  if(Button_Start_GetVal()==FALSE){
			  Cpu_Delay100US(50);
			  if(Button_Start_GetVal()==FALSE){
				  //Consider button pressed.
				  BVA_Cycles();								//Enter test cycles execution.
			  }
		  }
	  }
	  //Valid incoming frame got.
	  if(UART_RXBuf[9]==0x03){
		  TX_Report(TXData, 8);								//Send report frame to UART.
	  }else if(UART_RXBuf[9]==0x33){
		  TX_Report(TXData, 8);								//Send report frame to UART.
	  }else {
		  Cpu_Delay100US(10);
	  }
	  
  }
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */

//***********************************************************************
// TX_Report function
// Outcoming frame structure:
//     3 bytes "BVA" -- 1 byte sequence number -- data bytes -- 1 byte checksum
//***********************************************************************
void TX_Report(uint8_t * Data, uint8_t Count)
{
	word SentBytes;
	uint8_t i,j;
	
	if(Count > 20)return;					//Maximum payload is limited to 20 bytes.
	
	UART_TXBuf[0]='B';
	UART_TXBuf[1]='V';
	UART_TXBuf[2]='A';
	UART_TXBuf[3]=UT_SN++;
	
	//Copy payload data to UART_TXBuf[];
	for(i=4, j=0; j<Count; i++, j++){
		UART_TXBuf[i] = Data[j];
	}
	
	(void) AS1_SendBlock(UART_TXBuf, i, &SentBytes);
	
	return;
}

//***********************************************************************
// RX_Frame function
//     Receive command frame via UART
//     RX time-out check
// 
// Incoming frame structure: 3 bytes 'T'+test number.
// Example: "T32", means execute 32th test cycle in the test_cycle array. 
//    
// Return: 
//		ERR_OK: Succeeded. Valid frame received.
//		ERR_COMMON: Nothing received or something received but not valid and Ignore.
//***********************************************************************
uint8_t RX_Frame(void)
{
	uint8_t tmp;
	
	//Receive CMD byte.
	if(RX_Poll()==ERR_RXEMPTY)return ERR_COMMON;
	if(AS1_RecvChar(&tmp) != ERR_OK)return ERR_COMMON;
	if(tmp!='t'||tmp!='T')return ERR_COMMON;
	UART_RXBuf[0]=tmp;
	
	//CMD OK, receive T-num high byte.
	if(RX_Poll()==ERR_RXEMPTY)return ERR_COMMON;
	if(AS1_RecvChar(&tmp) != ERR_OK)return ERR_COMMON;
	if(tmp<'0'||tmp>'9')return ERR_COMMON;
	UART_RXBuf[1]=tmp;
	
	//CMD OK, receive T-num low byte.
	if(RX_Poll()==ERR_RXEMPTY)return ERR_COMMON;
	if(AS1_RecvChar(&tmp) != ERR_OK)return ERR_COMMON;
	if(tmp<'0'||tmp>'9')return ERR_COMMON;
	UART_RXBuf[2]=tmp;
	
	return ERR_OK;
	
}

//***********************************************************************
// Check if any bytes received. ~100uS timeout.
//***********************************************************************
uint8_t RX_Poll(void)
{
	word tmp;
	
	tmp=0;

	//Check RX until 100uS timeout.
/*	while(tmp<7){
		if(AS1_GetCharsInRxBuf()!=0)return ERR_OK;
		Timer_GetCounterValue(&tmp);
	}*/
	
	while(tmp<70){
		if(AS1_GetCharsInRxBuf()!=0)return ERR_OK;
		Cpu_Delay100US(1);
		tmp++;
	}
	
	return ERR_RXEMPTY;
}


//***********************************************************************
// Subroutine BVA_Cycle
//     Execute the test cycles per Test_Cycles[] and Test_Cycle_Time.
//     
//***********************************************************************
void BVA_Cycles(void)
{
	word i, j, k;
	word tmp;
	

	LED_Status_PutVal(0);				//Make status LED on.
	for(i=0;i<Test_Cycle_Num;i++){
		tmp=(word)Test_Cycles[i][0] * 655;
		if(Test_Cycles[i][0]>=100)tmp=65535;
		
		(void)PWM_Output_SetRatio16(tmp);				//Set the PWM output duty cycle
		
		Signal_Out_PutVal(Test_Cycles[i][1]);			//Set the Signal outputs.
		
		for(j=0,k=0;j<Test_Cycle_Time;k++){
			Cpu_Delay100US(100);						//Delay 10mS.
			if(Button_Start_GetVal()!=FALSE){
				Cpu_Delay100US(50);
				if(Button_Start_GetVal()!=FALSE){			//Stop button pressed. 
					(void) PWM_Output_SetRatio16(0);			//Set PWM duty cycle to 0.
					Signal_Out_PutVal(0);				//Set Signal outputs to 0.
					LED_Status_PutVal(1);				//Make status LED off.
					return;								//Quit.
				}
			}
			if(Button_Stop_GetVal()!=FALSE)j++;
			if(k==10){
				k=0;
				LED_Status_NegVal();					//Make status LED blinking.
			}
		}
	}
	
	(void) PWM_Output_SetRatio16(0);			//Set PWM duty cycle to 0.
	Signal_Out_PutVal(0);				//Set Signal outputs to 0.
	LED_Status_PutVal(1);				//Make status LED off.
	return ;
}




/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
