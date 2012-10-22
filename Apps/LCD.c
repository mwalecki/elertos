#include "LCD.h"
#include "KS0108/KS0108.h"
#include "stdio.h"
#include "DMA/adc.h"

extern ADC_St				ADC;

void vLCDTask(void *pvParameters)
{
	char tempBuf[50];
	char tempBuf2[50];
	sprintf(tempBuf,"+version %11s+", __DATE__);
	sprintf(tempBuf2,"+test 5V: %d+", ADC.milivolt[1]);

	GLCD_Initialize();
	GLCD_ClearScreen();

	GLCD_GoTo(0,0);	GLCD_WriteString("+-------------------+");
	GLCD_GoTo(0,1);	GLCD_WriteString("|                   |");
	GLCD_GoTo(0,2);	GLCD_WriteString("| nie wiem...       |");
	GLCD_GoTo(0,3);	GLCD_WriteString("|                   |");
	GLCD_GoTo(0,4);	GLCD_WriteString("| tako rzecze Slon! |");
	GLCD_GoTo(0,5);	GLCD_WriteString("|                   |");
	GLCD_GoTo(0,6);	GLCD_WriteString("|                   |");
	GLCD_GoTo(0,7);	GLCD_WriteString(tempBuf);

	while(1)
	{
	//	GLCD_GoTo(LCD_XY_VOLTAGE24);
	//	GLCD_WriteString("dupa");


		portTickType xLastWakeTime;
		const portTickType xTimeIncrement_ms = 500;
		xLastWakeTime=xTaskGetTickCount();
        vTaskDelayUntil(&xLastWakeTime,xTimeIncrement_ms);
	}
}
