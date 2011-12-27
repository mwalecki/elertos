#include "InOut.h"
																				 
void prvOUT1_ON(void)		{GPIO_SetBits(OUT1_GPIO, OUT1_PIN);}
void prvOUT1_OFF(void)		{GPIO_ResetBits(OUT1_GPIO, OUT1_PIN);}
void prvOUT2_ON(void)		{GPIO_SetBits(OUT2_GPIO, OUT2_PIN);}
void prvOUT2_OFF(void)		{GPIO_ResetBits(OUT2_GPIO, OUT2_PIN);}
void prvOUT3_ON(void)		{GPIO_SetBits(OUT3_GPIO, OUT3_PIN);}
void prvOUT3_OFF(void)		{GPIO_ResetBits(OUT3_GPIO, OUT3_PIN);}
void prvOUT4_ON(void)		{GPIO_SetBits(OUT4_GPIO, OUT4_PIN);}
void prvOUT4_OFF(void)		{GPIO_ResetBits(OUT4_GPIO, OUT4_PIN);}
void prvOUT5_ON(void)		{GPIO_SetBits(OUT5_GPIO, OUT5_PIN);}
void prvOUT5_OFF(void)		{GPIO_ResetBits(OUT5_GPIO, OUT5_PIN);}
void prvOUT6_ON(void)		{GPIO_SetBits(OUT6_GPIO, OUT6_PIN);}
void prvOUT6_OFF(void)		{GPIO_ResetBits(OUT6_GPIO, OUT6_PIN);}
void prvOUT7_ON(void)		{GPIO_SetBits(OUT7_GPIO, OUT7_PIN);}
void prvOUT7_OFF(void)		{GPIO_ResetBits(OUT7_GPIO, OUT7_PIN);}
//void prvOUT8_ON(void)		{GPIO_SetBits(OUT8_GPIO, OUT8_PIN);}
//void prvOUT8_OFF(void)	{GPIO_ResetBits(OUT8_GPIO, OUT8_PIN);}

void vInOutInitialize(void){
	GPIO_InitTypeDef GPIO_InitStructure;

	// Outputs
	// IO Clocks Enable
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE, ENABLE);
	/*	PORT B Push-Pull 10MHz Outputs:	*\
		PB.1	OUT1					
		PB.2	OUT2					*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	/*	PORT E Push-Pull 10MHz Outputs:	*\
		PE.7	OUT3					
		PE.8	OUT4					
		PE.9	OUT5					
		PE.10	OUT6					
		PE.11	OUT7					*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	// Status LED
	// IO Clocks Enable
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	/*	PORT C Push-Pull 10MHz Outputs:	*\
		PC.13	LED1					*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void vInOutSetOutputs(u8 set){
	if(set & (1<<0)) prvOUT1_ON();	else prvOUT1_OFF();
	if(set & (1<<1)) prvOUT2_ON();	else prvOUT2_OFF();
	if(set & (1<<2)) prvOUT3_ON();	else prvOUT3_OFF();
	if(set & (1<<3)) prvOUT4_ON();	else prvOUT4_OFF();
	if(set & (1<<4)) prvOUT5_ON();	else prvOUT5_OFF();
	if(set & (1<<5)) prvOUT6_ON();	else prvOUT6_OFF();
	if(set & (1<<6)) prvOUT7_ON();	else prvOUT7_OFF();
//	if(set & (1<<7)) prvOUT8_ON();	else prvOUT8_OFF();
}

u8		prvLED1_isON(void)		{return(GPIO_ReadOutputDataBit(LED1_GPIO, LED1_PIN)!=0);}
void	vInOutLED1_ON(void)		{GPIO_SetBits(LED1_GPIO, LED1_PIN);}
void	vInOutLED1_OFF(void)	{GPIO_ResetBits(LED1_GPIO, LED1_PIN);}
void	vInOutLED1_TOGGLE(void)	{if(prvLED1_isON()) vInOutLED1_OFF(); else vInOutLED1_ON();}

void vInOutStatusLEDTask(void *pvParameters)
{
	portTickType xLastWakeTime;
	const portTickType xFrequency = 500;
	xLastWakeTime=xTaskGetTickCount();
	    while(1)
	    {
	    	vInOutLED1_TOGGLE();
	        vTaskDelayUntil(&xLastWakeTime,xFrequency);
	    }
}
