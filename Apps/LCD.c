#include "LCD.h"
#include "KS0108/KS0108.h"
#include "stdio.h"
#include "stdlib.h"
#include "DMA/adc.h"
#include "string.h"

void vLCDTask(void *pvParameters)
{
	GLCD_Initialize();
	GLCD_ClearScreen();

	GLCD_GoTo(0,0);	GLCD_WriteString("+--Voltage Control--+");
	GLCD_GoTo(0,7);	GLCD_WriteString("+-------------------+");

	int i;
	for(i = 0; i < ADC_Channels; i++) {
		printChannelInfo(i);
	}

	while(1)
	{
		portTickType xLastWakeTime;
		const portTickType xTimeIncrement_ms = 500;
		xLastWakeTime=xTaskGetTickCount();
        vTaskDelayUntil(&xLastWakeTime,xTimeIncrement_ms);
	}
}

void printChannelInfo(int channel) {
	vu16 milivolt = ADC.milivolt[channel];
	char tempBuf[2];
	char tempBuf2[5];

	// channel number
	GLCD_GoTo((channel < 6) ? 6 : 12*6, channel%6+1);
	itoa(channel,tempBuf);
	GLCD_WriteString(tempBuf);

	// voltage
	GLCD_GoTo((channel < 6) ? 3*6 : 15*6, channel%6+1);
	itoa(milivolt,tempBuf2);
	GLCD_WriteString(tempBuf2);

	if(ADC.overTreshold[channel] == 1) {
		GLCD_GoTo((channel < 6) ? 0 : 11*6, channel%6+1);
		GLCD_WriteString("!");
	}
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
    int i;

    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */

    s[i] = '\0';
    reverse(s);
}
