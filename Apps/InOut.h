#ifndef _IO_H
#define _IO_H

#include "common.h"
#include "FreeRTOS.h"
#include "task.h"

//##                                      #### ######## ################ OUT port map:
#define OUT1_GPIO	GPIOB
#define OUT1_PIN	GPIO_Pin_1
#define OUT2_GPIO	GPIOB
#define OUT2_PIN	GPIO_Pin_2
#define OUT3_GPIO	GPIOE
#define OUT3_PIN	GPIO_Pin_7
#define OUT4_GPIO	GPIOE
#define OUT4_PIN	GPIO_Pin_8
#define OUT5_GPIO	GPIOE
#define OUT5_PIN	GPIO_Pin_9
#define OUT6_GPIO	GPIOE
#define OUT6_PIN	GPIO_Pin_10
#define OUT7_GPIO	GPIOE
#define OUT7_PIN	GPIO_Pin_11
//#define OUT8_GPIO	GPIOE
//#define OUT8_PIN	GPIO_Pin_11

//##                                      #### ######## ################ Status LED port map:
#define LED1_GPIO	GPIOC
#define LED1_PIN	GPIO_Pin_13

//##                                      #### ######## ################ PROTOTYPES:
void prvOUT1_ON(void);
void prvOUT1_OFF(void);
void prvOUT2_ON(void);
void prvOUT2_OFF(void);
void prvOUT3_ON(void);
void prvOUT3_OFF(void);
void prvOUT4_ON(void);
void prvOUT4_OFF(void);
void prvOUT5_ON(void);
void prvOUT5_OFF(void);
void prvOUT6_ON(void);
void prvOUT6_OFF(void);
void prvOUT7_ON(void);
void prvOUT7_OFF(void);
//void prvOUT8_ON(void);
//void prvOUT8_OFF(void);

void vInOutInitialize(void);
void vInOutSetOutputs(u8 set);

void vInOutStatusLEDTask(void *pvParameters);

u8 prvLED1_isON(void);
void vInOutLED1_ON(void);
void vInOutLED1_OFF(void);
void vInOutLED1_TOGGLE(void);
							
//##                                      #### ######## ################ OUT functionality:
#define vInOutREL1_ON()		prvOUT1_ON()
#define vInOutREL1_OFF()	prvOUT1_OFF()
#define vInOutREL2_ON()		prvOUT3_ON()
#define vInOutREL2_OFF()	prvOUT3_OFF()
#define vInOutREL3_ON()		prvOUT2_ON()
#define vInOutREL3_OFF()	prvOUT2_OFF()
#define vInOutREL4_ON()		prvOUT5_ON()
#define vInOutREL4_OFF()	prvOUT5_OFF()
#define vInOutPS_ON_H()		prvOUT6_ON()
#define vInOutPS_ON_L()		prvOUT6_OFF()
#define vInOutPS_EN_H()		prvOUT7_ON()
#define vInOutPS_EN_L()		prvOUT7_OFF()
#define vInOutR_OFF_H()		prvOUT4_ON()
#define vInOutR_OFF_L()		prvOUT4_OFF()

#endif //_IO_H
