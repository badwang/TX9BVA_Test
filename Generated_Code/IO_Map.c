/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : IO_Map.c
**     Project     : TX9BVA_Test
**     Processor   : MC9S08PA4VTG
**     Component   : IO_Map
**     Version     : Driver 01.07
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2015-03-13, 22:02, # CodeGen: 0
**     Abstract    :
**         IO_Map.h - implements an IO device's mapping. 
**         This module contains symbol definitions of all peripheral 
**         registers and bits. 
**     Settings    :
**
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file IO_Map.c
** @version 01.07
** @brief
**         IO_Map.h - implements an IO device's mapping. 
**         This module contains symbol definitions of all peripheral 
**         registers and bits. 
*/         
/*!
**  @addtogroup IO_Map_module IO_Map module documentation
**  @{
*/         
/* Based on CPU DB MC9S08PA4_16, version 3.00.000 (RegistersPrg V2.33) */
/* DataSheet : MC9S08PA4RM Rev. 0 Draft B, 10/2011 */

#include "PE_Types.h"
#include "IO_Map.h"

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PORT_PTADSTR _PORT_PTAD;                          /* Port A Data Register; 0x00000000 */
volatile PORT_PTBDSTR _PORT_PTBD;                          /* Port B Data Register; 0x00000001 */
volatile PORT_PTCDSTR _PORT_PTCD;                          /* Port C Data Register; 0x00000002 */
volatile ADC_SC1STR _ADC_SC1;                              /* Status and Control Register 1; 0x00000010 */
volatile ADC_SC2STR _ADC_SC2;                              /* Status and Control Register 2; 0x00000011 */
volatile ADC_SC3STR _ADC_SC3;                              /* Status and Control Register 3; 0x00000012 */
volatile ADC_SC4STR _ADC_SC4;                              /* Status and Control Register 4; 0x00000013 */
volatile FTM0_SCSTR _FTM0_SC;                              /* Status and Control; 0x00000020 */
volatile FTM0_C0SCSTR _FTM0_C0SC;                          /* Channel Status and Control; 0x00000025 */
volatile FTM0_C1SCSTR _FTM0_C1SC;                          /* Channel Status and Control; 0x00000028 */
volatile ACMP_CSSTR _ACMP_CS;                              /* ACMP Control and Status Register; 0x0000002C */
volatile ACMP_C0STR _ACMP_C0;                              /* ACMP Control Register 0; 0x0000002D */
volatile ACMP_C1STR _ACMP_C1;                              /* ACMP Control Register 1; 0x0000002E */
volatile ACMP_C2STR _ACMP_C2;                              /* ACMP Control Register 2; 0x0000002F */
volatile FTM1_SCSTR _FTM1_SC;                              /* Status and Control; 0x00000030 */
volatile FTM1_C0SCSTR _FTM1_C0SC;                          /* Channel Status and Control; 0x00000035 */
volatile FTM1_C1SCSTR _FTM1_C1SC;                          /* Channel Status and Control; 0x00000038 */
volatile IRQ_SCSTR _IRQ_SC;                                /* Interrupt Pin Request Status and Control Register; 0x0000003B */
volatile KBI0_SCSTR _KBI0_SC;                              /* KBI Status and Control Register; 0x0000003C */
volatile IPC_SCSTR _IPC_SC;                                /* IPC Status and Control Register; 0x0000003E */
volatile IPC_IPMPSSTR _IPC_IPMPS;                          /* Interrupt Priority Mask Pseudo Stack Register; 0x0000003F */
volatile SYS_SRSSTR _SYS_SRS;                              /* System Reset Status Register; 0x00003000 */
volatile SYS_SBDFRSTR _SYS_SBDFR;                          /* System Background Debug Force Reset Register; 0x00003001 */
volatile SYS_SOPT1STR _SYS_SOPT1;                          /* System Options Register 1; 0x00003004 */
volatile SYS_SOPT2STR _SYS_SOPT2;                          /* System Options Register 2; 0x00003005 */
volatile SYS_SOPT3STR _SYS_SOPT3;                          /* System Options Register 3; 0x00003006 */
volatile SCG_C1STR _SCG_C1;                                /* System Clock Gating Control 1 Register; 0x0000300C */
volatile SCG_C2STR _SCG_C2;                                /* System Clock Gating Control 2 Register; 0x0000300D */
volatile SCG_C3STR _SCG_C3;                                /* System Clock Gating Control 3 Register; 0x0000300E */
volatile SCG_C4STR _SCG_C4;                                /* System Clock Gating Control 4 Register; 0x0000300F */
volatile DBG_CAHSTR _DBG_CAH;                              /* Debug Comparator A High Register; 0x00003010 */
volatile DBG_CALSTR _DBG_CAL;                              /* Debug Comparator A Low Register; 0x00003011 */
volatile DBG_CBHSTR _DBG_CBH;                              /* Debug Comparator B High Register; 0x00003012 */
volatile DBG_CBLSTR _DBG_CBL;                              /* Debug Comparator B Low Register; 0x00003013 */
volatile DBG_CCHSTR _DBG_CCH;                              /* Debug Comparator C High Register; 0x00003014 */
volatile DBG_CCLSTR _DBG_CCL;                              /* Debug Comparator C Low Register; 0x00003015 */
volatile DBG_FHSTR _DBG_FH;                                /* Debug FIFO High Register; 0x00003016 */
volatile DBG_FLSTR _DBG_FL;                                /* Debug FIFO Low Register; 0x00003017 */
volatile DBG_CAXSTR _DBG_CAX;                              /* Debug Comparator A Extension Register; 0x00003018 */
volatile DBG_CBXSTR _DBG_CBX;                              /* Debug Comparator B Extension Register; 0x00003019 */
volatile DBG_CCXSTR _DBG_CCX;                              /* Debug Comparator C Extension Register; 0x0000301A */
volatile DBG_FXSTR _DBG_FX;                                /* Debug FIFO Extended Information Register; 0x0000301B */
volatile DBG_CSTR _DBG_C;                                  /* Debug Control Register; 0x0000301C */
volatile DBG_TSTR _DBG_T;                                  /* Debug Trigger Register; 0x0000301D */
volatile DBG_SSTR _DBG_S;                                  /* Debug Status Register; 0x0000301E */
volatile DBG_CNTSTR _DBG_CNT;                              /* Debug Count Status Register; 0x0000301F */
volatile NVM_FCLKDIVSTR _NVM_FCLKDIV;                      /* Flash Clock Divider Register; 0x00003020 */
volatile NVM_FSECSTR _NVM_FSEC;                            /* Flash Security Register; 0x00003021 */
volatile NVM_FCCOBIXSTR _NVM_FCCOBIX;                      /* Flash CCOB Index Register; 0x00003022 */
volatile NVM_FCNFGSTR _NVM_FCNFG;                          /* Flash Configuration Register; 0x00003024 */
volatile NVM_FERCNFGSTR _NVM_FERCNFG;                      /* Flash Error Configuration Register; 0x00003025 */
volatile NVM_FSTATSTR _NVM_FSTAT;                          /* Flash Status Register; 0x00003026 */
volatile NVM_FERSTATSTR _NVM_FERSTAT;                      /* Flash Error Status Register; 0x00003027 */
volatile NVM_FPROTSTR _NVM_FPROT;                          /* Flash Protection Register; 0x00003028 */
volatile NVM_EEPROTSTR _NVM_EEPROT;                        /* EEPROM Protection Register; 0x00003029 */
volatile NVM_FOPTSTR _NVM_FOPT;                            /* Flash Option Register; 0x0000302C */
volatile WDOG_CS1STR _WDOG_CS1;                            /* Watchdog Control and Status Register 1; 0x00003030 */
volatile WDOG_CS2STR _WDOG_CS2;                            /* Watchdog Control and Status Register 2; 0x00003031 */
volatile ICS_C1STR _ICS_C1;                                /* ICS Control Register 1; 0x00003038 */
volatile ICS_C2STR _ICS_C2;                                /* ICS Control Register 2; 0x00003039 */
volatile ICS_C3STR _ICS_C3;                                /* ICS Control Register 3; 0x0000303A */
volatile ICS_C4STR _ICS_C4;                                /* ICS Control Register 4; 0x0000303B */
volatile ICS_SSTR _ICS_S;                                  /* ICS Status Register; 0x0000303C */
volatile ICS_OSCSCSTR _ICS_OSCSC;                          /* OSC Status and Control Register; 0x0000303E */
volatile PMC_SPMSC1STR _PMC_SPMSC1;                        /* System Power Management Status and Control 1 Register; 0x00003040 */
volatile PMC_SPMSC2STR _PMC_SPMSC2;                        /* System Power Management Status and Control 2 Register; 0x00003041 */
volatile SYS_ILLAHSTR _SYS_ILLAH;                          /* Illegal Address Register: High; 0x0000304A */
volatile SYS_ILLALSTR _SYS_ILLAL;                          /* Illegal Address Register: Low; 0x0000304B */
volatile IPC_ILRS0STR _IPC_ILRS0;                          /* Interrupt Level Setting Registers n; 0x00003050 */
volatile IPC_ILRS1STR _IPC_ILRS1;                          /* Interrupt Level Setting Registers n; 0x00003051 */
volatile IPC_ILRS2STR _IPC_ILRS2;                          /* Interrupt Level Setting Registers n; 0x00003052 */
volatile IPC_ILRS3STR _IPC_ILRS3;                          /* Interrupt Level Setting Registers n; 0x00003053 */
volatile IPC_ILRS4STR _IPC_ILRS4;                          /* Interrupt Level Setting Registers n; 0x00003054 */
volatile IPC_ILRS5STR _IPC_ILRS5;                          /* Interrupt Level Setting Registers n; 0x00003055 */
volatile IPC_ILRS6STR _IPC_ILRS6;                          /* Interrupt Level Setting Registers n; 0x00003056 */
volatile IPC_ILRS7STR _IPC_ILRS7;                          /* Interrupt Level Setting Registers n; 0x00003057 */
volatile IPC_ILRS8STR _IPC_ILRS8;                          /* Interrupt Level Setting Registers n; 0x00003058 */
volatile IPC_ILRS9STR _IPC_ILRS9;                          /* Interrupt Level Setting Registers n; 0x00003059 */
volatile RTC_SC1STR _RTC_SC1;                              /* RTC Status and Control Register 1; 0x0000306A */
volatile RTC_SC2STR _RTC_SC2;                              /* RTC Status and Control Register 2; 0x0000306B */
volatile KBI0_PESTR _KBI0_PE;                              /* KBIx Pin Enable Register; 0x0000307C */
volatile KBI0_ESSTR _KBI0_ES;                              /* KBIx Edge Select Register; 0x0000307D */
volatile SCI0_C1STR _SCI0_C1;                              /* SCI Control Register 1; 0x00003082 */
volatile SCI0_C2STR _SCI0_C2;                              /* SCI Control Register 2; 0x00003083 */
volatile SCI0_S1STR _SCI0_S1;                              /* SCI Status Register 1; 0x00003084 */
volatile SCI0_S2STR _SCI0_S2;                              /* SCI Status Register 2; 0x00003085 */
volatile SCI0_C3STR _SCI0_C3;                              /* SCI Control Register 3; 0x00003086 */
volatile SCI0_DSTR _SCI0_D;                                /* SCI Data Register; 0x00003087 */
volatile ADC_APCTL1STR _ADC_APCTL1;                        /* Pin Control 1 Register; 0x000030AC */
volatile PORT_HDRVESTR _PORT_HDRVE;                        /* Port High Drive Enable Register; 0x000030AF */
volatile PORT_PTAOESTR _PORT_PTAOE;                        /* Port A Output Enable Register; 0x000030B0 */
volatile PORT_PTBOESTR _PORT_PTBOE;                        /* Port B Output Enable Register; 0x000030B1 */
volatile PORT_PTCOESTR _PORT_PTCOE;                        /* Port C Output Enable Register; 0x000030B2 */
volatile PORT_PTAIESTR _PORT_PTAIE;                        /* Port A Input Enable Register; 0x000030B8 */
volatile PORT_PTBIESTR _PORT_PTBIE;                        /* Port B Input Enable Register; 0x000030B9 */
volatile PORT_PTCIESTR _PORT_PTCIE;                        /* Port C Input Enable Register; 0x000030BA */
volatile PORT_IOFLT0STR _PORT_IOFLT0;                      /* Port Filter Register 0; 0x000030EC */
volatile PORT_IOFLT2STR _PORT_IOFLT2;                      /* Port Filter Register 2; 0x000030EE */
volatile PORT_FCLKDIVSTR _PORT_FCLKDIV;                    /* Port Clock Division Register; 0x000030EF */
volatile PORT_PTAPESTR _PORT_PTAPE;                        /* Port A Pullup Enable Register; 0x000030F0 */
volatile PORT_PTBPESTR _PORT_PTBPE;                        /* Port B Pullup Enable Register; 0x000030F1 */
volatile PORT_PTCPESTR _PORT_PTCPE;                        /* Port C Pullup Enable Register; 0x000030F2 */
volatile SYS_UUID1STR _SYS_UUID1;                          /* Universally Unique Identifier Register 1; 0x000030F8 */
volatile SYS_UUID2STR _SYS_UUID2;                          /* Universally Unique Identifier Register 2; 0x000030F9 */
volatile SYS_UUID3STR _SYS_UUID3;                          /* Universally Unique Identifier Register 3; 0x000030FA */
volatile SYS_UUID4STR _SYS_UUID4;                          /* Universally Unique Identifier Register 4; 0x000030FB */
volatile SYS_UUID5STR _SYS_UUID5;                          /* Universally Unique Identifier Register 5; 0x000030FC */
volatile SYS_UUID6STR _SYS_UUID6;                          /* Universally Unique Identifier Register 6; 0x000030FD */
volatile SYS_UUID7STR _SYS_UUID7;                          /* Universally Unique Identifier Register 7; 0x000030FE */
volatile SYS_UUID8STR _SYS_UUID8;                          /* Universally Unique Identifier Register 8; 0x000030FF */
/* NV_BACKKEY0 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF70 */
/* NV_BACKKEY1 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF71 */
/* NV_BACKKEY2 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF72 */
/* NV_BACKKEY3 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF73 */
/* NV_BACKKEY4 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF74 */
/* NV_BACKKEY5 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF75 */
/* NV_BACKKEY6 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF76 */
/* NV_BACKKEY7 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF77 */
/* NV_FPROT - macro for reading non volatile register      Flash Protection Register; 0x0000FF7C */
/* NV_EEPROT - macro for reading non volatile register     EEPROM Protection Register; 0x0000FF7D */
/* NV_FOPT - macro for reading non volatile register       Flash Option Register; 0x0000FF7E */
/* NV_FSEC - macro for reading non volatile register       Flash Security Register; 0x0000FF7F */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile ADC_RSTR _ADC_R;                                  /* Data Result Register; 0x00000014 */
volatile ADC_CVSTR _ADC_CV;                                /* Compare Value Register; 0x00000016 */
volatile FTM0_CNTSTR _FTM0_CNT;                            /* FTM0 Timer Counter Register; 0x00000021 */
volatile FTM0_MODSTR _FTM0_MOD;                            /* FTM0 Timer Counter Modulo Register; 0x00000023 */
volatile FTM0_C0VSTR _FTM0_C0V;                            /* FTM0 Timer Channel 0 Value Register; 0x00000026 */
volatile FTM0_C1VSTR _FTM0_C1V;                            /* FTM0 Timer Channel 1 Value Register; 0x00000029 */
volatile FTM1_CNTSTR _FTM1_CNT;                            /* FTM1 Timer Counter Register; 0x00000031 */
volatile FTM1_MODSTR _FTM1_MOD;                            /* FTM1 Timer Counter Modulo Register; 0x00000033 */
volatile FTM1_C0VSTR _FTM1_C0V;                            /* FTM1 Timer Channel 0 Value Register; 0x00000036 */
volatile FTM1_C1VSTR _FTM1_C1V;                            /* FTM1 Timer Channel 1 Value Register; 0x00000039 */
volatile SYS_SDIDSTR _SYS_SDID;                            /* System Device Identification Register; 0x00003002 */
volatile NVM_FCCOBSTR _NVM_FCCOB;                          /* Flash Common Command Object Register; 0x0000302A */
volatile WDOG_CNTSTR _WDOG_CNT;                            /* Watchdog Counter Register; 0x00003032 */
volatile WDOG_TOVALSTR _WDOG_TOVAL;                        /* Watchdog Timer Register; 0x00003034 */
volatile WDOG_WINSTR _WDOG_WIN;                            /* Watchdog Window Register; 0x00003036 */
volatile RTC_MODSTR _RTC_MOD;                              /* RTC Modulo Register; 0x0000306C */
volatile RTC_CNTSTR _RTC_CNT;                              /* RTC Counter Register; 0x0000306E */
volatile SCI0_BDSTR _SCI0_BD;                              /* SCI0 Baud Rate Register; 0x00003080 */

/*lint -restore */

/* EOF */
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
