#ifndef _LCD_H
#define _LCD_H

#include "common.h"
#include "FreeRTOS.h"
#include "task.h"

//##                                      #### ######## ################ DEFINES:
#define LCD_XY_VOLTAGE24 0,0

//##                                      #### ######## ################ PROTOTYPES:

void vLCDTask(void *pvParameters);
void printChannelInfo(int channel);
void itoa(int n, char s[]);
void toVolt(int milivolt, char s[]);
void reverse(char s[]);

#endif
