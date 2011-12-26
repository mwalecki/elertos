#ifndef _COMMON_H_
#define _COMMON_H_

#include "stm32f10x_conf.h"

#define MODULE_NAME			"MW1106 Sedes Main Module mw@mwalecki.pl"
#define USART_BufSz			127	 
#define USART_TxSuffix		"\r\n\n"

#define M_STOP		0
#define M_POSITION	1
#define M_CURRENT	2
#define M_PWM		3
#define M_ER_STOP	4
#define M_BOOT		5
#define M_SPEED		6
#define M_SET_PID	7

typedef struct{
	vu8 blink;
	vu8 blinkPhase;
} LED_St;	 

typedef struct{
	vu32 val;
	vu32 period;
	vu8 tick;
} STDOWNCNT_St;	

typedef struct{
	vs8 rxBuf[USART_BufSz];
	vs8 txBuf[USART_BufSz];
	vs8 tmpBuf[USART_BufSz];
	vu8 rxPt, txPt;
	vu8 rxDataReady	:1;
	vu8 txDataReady	:1;
} USART_St;	 

typedef struct{
	u8 mode;
	s8 leftSpeed, rightSpeed;
	s8 srv4;
	u16 srv1pos, srv2pos, srv3pos, srv4pos;
	u8 digiOut;
	u16 slope;
	s16 enc1, enc2;
	u16	pidP;
	u16	pidI;
	u16	pidD;
	u16 pidT;
	u16 srv1Min;
	u16 srv1Max;
	u16 srv2Min;
	u16 srv2Max;
} REFERENCE_St;

typedef struct{
	u8	mode;
	u8	computerLink	:1;
	u8	panelLink		:1;
	u8	shuttingDown	:1;
	u8	batteryLow		:1;
} MCENTRAL_St;

typedef struct{
	u8	mode;
	s8	refSpeed;
} MMOTOR_St;

#endif //_COMMON_H_
