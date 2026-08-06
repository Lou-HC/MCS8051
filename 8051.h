/*-----------------------------------------------------------------------------
  REG51ATLPRB2.H

Header file for Atmel AT89LP51RB2\RC2\IC2 and AT89LP51RD2\ED2\ID2 devices.
Copyright (c) 2012 ARM Ltd and ARM Germnay GmbH.
All rights reserved.
-----------------------------------------------------------------------------*/

#ifndef __AT89LP51RD2_H__
#define __AT89LP51RD2_H__

/* Byte Registers */
__sfr __at (0x80)P0;            /* Port 0 Latch                           */
__sfr __at (0x81) SP;            /* Stack Pointer                          */
__sfr __at (0x82) DPL;            /* Data Pointer Low                       */
__sfr __at (0x83) DPH;            /* Data Pointer High                      */
__sfr __at (0x85) CKSEL;            /* Clock Selection Register               */
__sfr __at (0x86) OSCCON;            /* Oscillator Contro l Register           */
__sfr __at (0x87) PCON;            /* Power Control                          */
__sfr __at (0x88) TCON;            /* Timer/Counter 0 and 1 Control          */
__sfr __at (0x89) TMOD;            /* Timer/Counter 0 and 1 Modes            */
__sfr __at (0x8A) TL0;            /* Timer/Counter 0 Low Byte               */
__sfr __at (0x8B) TL1;            /* Timer/Counter 1 Low Byte               */
__sfr __at (0x8C) TH0;            /* Timer/Counter 0 High Byte              */
__sfr __at (0x8D) TH1;            /* Timer/Counter 1 High Byte              */
__sfr __at (0x8E) AUXR;            /* Auxiliary Register 0                   */
__sfr __at (0x8F) CKCON0;            /* Clock Control Register 0               */
__sfr __at (0x90) P1;            /* Port 1 Latch                           */
__sfr __at (0x91) TCONB;            /* Timer/Counter 0 and 1 Mode B           */
__sfr __at (0x92) BMSEL;            /* Bank memory selection                  */
__sfr __at (0x93) SSCON;            /* Synchronous Serial Control             */
__sfr __at (0x94)SSCS;            /* Synchronous Serial Status              */
__sfr __at (0x95)SSDAT;            /* Synchronous Serial Data                */
__sfr __at (0x96)SSADR;            /* Synchronous Serial Address             */
__sfr __at (0x97)CKRL;            /* Clock Reload Register                  */
__sfr __at (0x98)SCON;            /* Serial Control                         */
__sfr __at (0x99)SBUF;            /* Serial Data Buffer                     */
__sfr __at (0x9A)BRL;            /* Baud Rate Reload                       */
__sfr __at (0x9B)BDRCON;            /* Baud Rate Control                      */
__sfr __at (0x9C)KBLS;            /* Keyboard Level Selector                */
__sfr __at (0x9D)KBE;            /* Keyboard Input Enable                  */
__sfr __at (0x9E)KBF;            /* Keyboard Flag Register                 */
__sfr __at (0x9F)KBMOD;            /* Keyboard Mode Register                 */
__sfr __at (0xA0)P2;            /* Port 2 Latch                           */
__sfr __at (0xA1)DPCF;            /* Datapointer Config Register            */
__sfr __at (0xA2)AUXR1;            /* Auxiliary Register 1                   */
__sfr __at (0xA3)ACSRA;            /* Comparator A Control Register          */
__sfr __at (0xA4)DADC;            /* DAC/ADC Control Register               */
__sfr __at (0xA5)DADI;            /* DAC/ADC Input Register                 */
__sfr __at (0xA6)WDTRST;            /* WatchDog Timer Reset                   */
__sfr __at (0xA7)WDTPRG;            /* WatchDog Timer Program                 */
__sfr __at (0xA8)IEN0;            /* Interrupt Enable Control 0             */
__sfr __at (0xA9)SADDR;            /* Slave Address                          */
__sfr __at (0xAB)ACSRB;            /* Comparator B Control Register          */
__sfr __at (0xAC)DADL;            /* DAC/ADC Data Low Register              */
__sfr __at (0xAD)DADH;            /* DAC/ADC Data High Register             */
__sfr __at (0xAE)CLKREG;            /* Clock Register                         */
__sfr __at (0xAF)CKCON1;            /* Clock Control Register 1               */
__sfr __at (0xB0)P3;            /* Port 3 Latch                           */
__sfr __at (0xB1)IEN1;            /* Interrupt Enable Control 1             */
__sfr __at (0xB2)IPL1;            /* Interrupt Priority Control Low 1       */
__sfr __at (0xB3)IPH1;            /* Interrupt Priority Control High 1      */
__sfr __at (0xB7)IPH0;            /* Interrupt Priority Control High 0      */
__sfr __at (0xB8)IPL0;            /* Interrupt Priority Control Low 0       */
__sfr __at (0xB9)SADEN;            /* Slave Address Mask                     */
__sfr __at (0xBD)AREF;            /* Comparator Reference Register          */
__sfr __at (0xBE)P4M0;            /* Port 4 Mode 0                          */
__sfr __at (0xBF)P4M1;            /* Port 4 Mode 1                          */
__sfr __at (0xC0)P4;            /* Port 4 Latch                           */
__sfr __at (0xC3)SPCON;            /* SPI Control                            */
__sfr __at (0xC4)SPSTA;            /* SPI Status                             */
__sfr __at (0xC5)SPDAT;            /* SPI Data                               */
__sfr __at (0xC6)P3M0;            /* Port 3 Mode 0                          */
__sfr __at (0xC7)P3M1;            /* Port 3 Mode 1                          */
__sfr __at (0xC8)T2CON;            /* Timer/Counter 2 control                */
__sfr __at (0xC9)T2MOD;            /* Timer/C ounter 2 Mode                  */
__sfr __at (0xCA)RCAP2L;            /* Timer/Counter 2 Reload/Capture Low B.  */
__sfr __at (0xCB)RCAP2H;            /* Timer/Counter 2 Reload/Capture High B. */
__sfr __at (0xCC)TL2;            /* Timer/Counter 2 Low Byte               */
__sfr __at (0xCD)TH2;            /* Timer/Counter 2 High Byte              */
__sfr __at (0xCE)P2M0;            /* Port 2 Mode 0                          */
__sfr __at (0xCF)P2M1;            /* Port 2 Mode 1                          */
__sfr __at (0xD0)PSW;            /* Program Status Word                    */
__sfr __at (0xD1)FCON;            /* Flash Control Register                 */
__sfr __at (0xD2)EECON;            /* EEPROM Control Register                */
__sfr __at (0xD4)DPLB;            /* Alternate Data Pointer Low Byte        */
__sfr __at (0xD5)DPHB;            /* Alternate Data Pointer High Byte       */
__sfr __at (0xD6)P1M0;            /* Port 1 Mode 0                          */
__sfr __at (0xD7)P1M1;            /* Port 1 Mode 1                          */
__sfr __at (0xD8)CCON;            /* PCA Timer/Counter Control              */
__sfr __at (0xD9)CMOD;            /* PCA Timer/Counter Mode                 */
__sfr __at (0xDA)CCAPM0;            /* PCA Timer/Counter Mode 0               */
__sfr __at (0xDB)CCAPM1;            /* PCA Timer/Counter Mode 1               */
__sfr __at (0xDC)CCAPM2;            /* PCA Timer/Counter Mode 2               */
__sfr __at (0xDD)CCAPM3;            /* PCA Timer/Counter Mode 3               */
__sfr __at (0xDE)CCAPM4;            /* PCA Timer/Counter Mode 4               */
__sfr __at (0xE0)ACC;            /* Accumulator                            */
__sfr __at (0xE1)AX;            /* Extended Accumulator                   */
__sfr __at (0xE2)DSPR;            /* DSP Control Register                   */
__sfr __at (0xE3)FIRD;            /* FIFO Depth                             */
__sfr __at (0xE4)MACL;            /* MAC Low Byte                           */
__sfr __at (0xE5)MACH;            /* MAC High Byte                          */
__sfr __at (0xE6)P0M0;            /* Port 0 Mode 0                          */
__sfr __at (0xE7)P0M1;            /* Port 0 Mode 1                          */
__sfr __at (0xE9)CL;            /* PCA Timer/Counter Low Byte             */
__sfr __at (0xEA)CCAP0L;            /* PCA Compare Capture Module 0 L         */
__sfr __at (0xEB)CCAP1L;            /* PCA Compare Capture Module 1 L         */
__sfr __at (0xEC)CCAP2L;            /* PCA Compare Capture Module 2 L         */
__sfr __at (0xED)CCAP3L;            /* PCA Compare Capture Module 3 L         */
__sfr __at (0xEE)CCAP4L;            /* PCA Compare Capture Module 4 L         */
__sfr __at (0xEF)SPX;            /* Extended Stack Pointer                 */
__sfr __at (0xF0)B;            /* B Register                             */
__sfr __at (0xF2)RL0;            /* Timer/Counter 0 Reload Low             */
__sfr __at (0xF3)RL1;            /* Timer/Counter 1 Reload Low             */
__sfr __at (0xF4)RH0;            /* Timer/Counter 0 Reload High            */
__sfr __at (0xF5)RH1;            /* Timer/Counter 1 Reload High            */
__sfr __at (0xF6)PAGE;            /* ERAM Page Register                     */
__sfr __at (0xF7)BX;            /* Extended B Register                    */
__sfr __at (0xF9)CH;            /* PCA Timer/Counter High Byte            */
__sfr __at (0xFA)CCAP0H;            /* PCA Compare Capture Module 0 H         */
__sfr __at (0xFB)CCAP1H;            /* PCA Compare Capture Module 1 H         */
__sfr __at (0xFC)CCAP2H;            /* PCA Compare Capture Module 2 H         */
__sfr __at (0xFD)CCAP3H;            /* PCA Compare Capture Module 3 H         */
__sfr __at (0xFE)CCAP4H;            /* PCA Compare Capture Module 4 H         */

/* 16-bit Register definitions */
__sfr __at (0x82)DP;            /* Data Pointer                           */
__sfr __at (0xB2)IP1;            /* Interrupt 1 priority control           */
__sfr __at (0xB7)IP2;            /* Interrupt 2 priority control           */
__sfr __at (0xCA)RCAP2;            /* Timer/Counter 2 Reload/Capture         */
__sfr __at (0xCC)T2;            /* Timer 2                                */
__sfr __at (0xD4)DPB;            /* Alternate datapointer                  */
__sfr __at (0xE4)MAC;            /* MAC Register                           */

/* Bit Definitions */
/* P0 0x80 */
__sbit __at (0x87)P0_7;              /* Port 0 Bit 7                           */
__sbit __at (0x86)P0_6;              /* Port 0 Bit 6                           */
__sbit __at (0x85)P0_5;              /* Port 0 Bit 5                           */
__sbit __at (0x84)P0_4;              /* Port 0 Bit 4                           */
__sbit __at (0x83)P0_3;              /* Port 0 Bit 3                           */
__sbit __at (0x82)P0_2;              /* Port 0 Bit 2                           */
__sbit __at (0x81)P0_1;              /* Port 0 Bit 1                           */
__sbit __at (0x80)P0_0;              /* Port 0 Bit 0                           */

/* TCON 0x88 */
__sbit __at (0x8F)TF1;            /* Timer 1 Overflow Flag                  */
__sbit __at (0x8E)TR1;            /* Timer 1 On/Off Control                 */
__sbit __at (0x8D)TF0;            /* Timer 0 Overflow Flag                  */
__sbit __at (0x8C)TR0;            /* Timer 0 On/Off Control                 */
__sbit __at (0x8B)IE1;            /* Ext. Interrupt 1 Edge Flag             */
__sbit __at (0x8A)IT1;            /* Ext. Interrupt 1 Type                  */
__sbit __at (0x89)IE0;            /* Ext. Interrupt 0 Edge Flag             */
__sbit __at (0x88)IT0;            /* Ext. Interrupt 0 Type                  */

/* P1 0x90 */
__sbit __at (0x97)P1_7;              /* Port 1 Bit 7                           */
__sbit __at (0x96)P1_6;              /* Port 1 Bit 6                           */
__sbit __at (0x95)P1_5;              /* Port 1 Bit 5                           */
__sbit __at (0x94)P1_4;              /* Port 1 Bit 4                           */
__sbit __at (0x93)P1_3;              /* Port 1 Bit 3                           */
__sbit __at (0x92)P1_2;              /* Port 1 Bit 2                           */
__sbit __at (0x91)P1_1;              /* Port 1 Bit 1                           */
__sbit __at (0x90)P1_0;              /* Port 1 Bit 0                           */

/* SCON 0x98 */
__sbit __at (0x9F)SM0;            /* Serial Port Mode Bit 0                 */
__sbit __at (0x9E)SM1;            /* Serial Port Mode Bit 1                 */
__sbit __at (0x9D)SM2;            /* Multiprocessor Communication Enable    */
__sbit __at (0x9C)REN;            /* Serial Reception Enable                */
__sbit __at (0x9B)TB8;            /* Transmitter Bit 8                      */
__sbit __at (0x9A)RB8;            /* Receiver Bit 8                         */
__sbit __at (0x99)TI;            /* Transmit Interrupt Flag                */
__sbit __at (0x98)RI;            /* Receive Interrupt Flag                 */

/* P2 0xA0 */
__sbit __at (0xA7)P2_7;              /* Port 2 Bit 7                           */
__sbit __at (0xA6)P2_6;              /* Port 2 Bit 6                           */
__sbit __at (0xA5)P2_5;              /* Port 2 Bit 5                           */
__sbit __at (0xA4)P2_4;              /* Port 2 Bit 4                           */
__sbit __at (0xA3)P2_3;              /* Port 2 Bit 3                           */
__sbit __at (0xA2)P2_2;              /* Port 2 Bit 2                           */
__sbit __at (0xA1)P2_1;              /* Port 2 Bit 1                           */
__sbit __at (0xA0)P2_0;              /* Port 2 Bit 0                           */

/* IEN0 0xA8 */
__sbit __at (0xAF)EA;            /* Global Interrupt Enable                */
__sbit __at (0xAE)EC;            /* PCA Interrpt Enable                    */
__sbit __at (0xAD)ET2;            /* Timer 2 Interrupt Enable               */
__sbit __at (0xAC)ES;            /* Serial Port Interrupt Enable           */
__sbit __at (0xAB)ET1;            /* Timer 1 Interrupt Enable               */
__sbit __at (0xAA)EX1;            /* External Interrupt 1 Enable            */
__sbit __at (0xA9)ET0;            /* Timer 0 Interrupt Enable               */
__sbit __at (0xA8)EX0;            /* External Interrupt 0 Enable            */

/* P3 0xB0 */
__sbit __at (0xB7)P3_7;              /* Port 3 Bit 7                           */
__sbit __at (0xB6)P3_6;              /* Port 3 Bit 6                           */
__sbit __at (0xB5)P3_5;              /* Port 3 Bit 5                           */
__sbit __at (0xB4)P3_4;              /* Port 3 Bit 4                           */
__sbit __at (0xB3)P3_3;              /* Port 3 Bit 3                           */
__sbit __at (0xB2)P3_2;              /* Port 3 Bit 2                           */
__sbit __at (0xB1)P3_1;              /* Port 3 Bit 1                           */
__sbit __at (0xB0)P3_0;              /* Port 3 Bit 0                           */

/* IPL0 0xB8 */
//__sbit __at (IPL0^7)IP0DIS;            /* Interrupt Level 0 Disable              */
//__sbit __at (IPL0^6)PPCL;            /* PCA Interrupt Priority Low             */
//__sbit __at (IPL0^5)PT2L;            /* Timer 2 Interrupt Priority Low         */
//__sbit __at (IPL0^4)PSL;            /* Serial Port Interrupt Priority Low     */
//__sbit __at (IPL0^3)PT1L;            /* Timer 1 Interrupt Priority Low         */
//__sbit __at (IPL0^2)PX1L;            /* External Interrupt 1 Priority Low      */
//__sbit __at (IPL0^1)PT0L;            /* Timer 0 Interrupt Priority Low         */
//__sbit __at (IPL0^0)PX0L;            /* External Interrupt 0 Priority  Low     */

/* P4 0xB0 */
__sbit __at (0xC7)P4_7;              /* Port 4 Bit 7                           */
__sbit __at (0xC6)P4_6;              /* Port 4 Bit 6                           */
__sbit __at (0xC5)P4_5;              /* Port 4 Bit 5                           */
__sbit __at (0xC4)P4_4;              /* Port 4 Bit 4                           */
__sbit __at (0xC3)P4_3;              /* Port 4 Bit 3                           */
__sbit __at (0xC2)P4_2;              /* Port 4 Bit 2                           */
__sbit __at (0xC1)P4_1;              /* Port 4 Bit 1                           */
__sbit __at (0xC0)P4_0;              /* Port 4 Bit 0                           */

/* T2CON 0xC8 */
//__sbit __at (T2CON^7)TF2;           /* Timer 2 Overflow Flag                  */
//__sbit __at (T2CON^6)EXF2;           /* Timer 2 External Flag                  */
//__sbit __at (T2CON^5)RCLK;           /* Receive Clock Enable                   */
//__sbit __at (T2CON^4)TCLK;           /* Transmit Clock Enable                  */
//__sbit __at (T2CON^3)EXEN2;           /* Timer 2 Split Mode Enable              */
//__sbit __at (T2CON^2)TR2;           /* Timer 2 Run Control                    */
//__sbit __at (T2CON^1)C;           /* Timer/Counter select 2                 */
//__sbit __at (T2CON^0)CP;           /* Capture/Reload Select                  */

/* PSW 0xD0 */
__sbit __at (0xD7)CY;             /* Carry Flag                             */
__sbit __at (0xD6)AC;             /* Auxiliary Carry Flag                   */
__sbit __at (0xD5)F0;             /* User Flag 0                            */
__sbit __at (0xD4)RS1;             /* Register Bank Select 1                 */
__sbit __at (0xD3)RS0;             /* Register Bank Select 0                 */
__sbit __at (0xD2)OV;             /* Overflow Flag                          */
__sbit __at (0xD1)F1;             /* User Flag 1                            */
__sbit __at (0xD0)P;             /* Accumulator Parity Flag                */

/* CCON 0xD8 */
//__sbit __at (CCON^7)CF;            /* PCA  Counter Overflow Flag             */
//__sbit __at (CCON^6)CR;            /* PCA  Counter Run Control Bit           */
                                   /* Not used                               */
//__sbit __at (CCON^4)CCF4;            /* PCA  Module 4 Interrupt Flag           */
//__sbit __at (CCON^3)CCF3;            /* PCA  Module 3 Interrupt Flag           */
//__sbit __at (CCON^2)CCF2;            /* PCA  Module 2 Interrupt Flag           */
//__sbit __at (CCON^1)CCF1;            /* PCA  Module 1 Interrupt Flag           */
//__sbit __at (CCON^0)CCF0;            /* PCA  Module 0 Interrupt Flag           */

/* BIT definitions for bits that are not directly accessible */
/* PCON bits */
/*#define IDL             0x01
#define PD              0x02
#define GF0             0x04
#define GF1             0x08
#define SMOD            0x80*/

/* TMOD bits */
/*#define T0_M0           0x01
#define T0_M1           0x02
#define T0_CT           0x04
#define T0_GATE         0x08
#define T1_M0           0x10
#define T1_M1           0x20
#define T1_CT           0x40
#define T1_GATE         0x80

#define T0_MASK         0x0F
#define T1_MASK         0xF0*/

/* Interrupt numbers: address = (number * 8) + 3 */
#define IE0_VECTOR      0       /* 0x03 external interrupt 0 */
#define TF0_VECTOR      1       /* 0x0b timer 0 */
#define IE1_VECTOR      2       /* 0x13 external interrupt 1 */
#define TF1_VECTOR      3       /* 0x1b timer 1 */
#define SI0_VECTOR      4       /* 0x23 serial port 0 */

#endif                                /* #define __AT89LP51RD2_H__          */
