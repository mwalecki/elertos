/*
 * KS0108-STM32.h
 *
 *  Created on: 09-08-2012
 *      Author: wacek
 */

#ifndef KS0108_STM32_H_
#define KS0108_STM32_H_

void GLCD_Delay(void);
void GLCD_EnableController(unsigned char controller);
void GLCD_DisableController(unsigned char controller);
unsigned char GLCD_ReadStatus(unsigned char controller);
void GLCD_WriteCommand(unsigned char commandToWrite, unsigned char controller);
unsigned char GLCD_ReadData(void);
void GLCD_WriteData(unsigned char dataToWrite);
void GLCD_InitializePorts(void);
unsigned char GLCD_ReadByteFromROMMemory(char * ptr);
void GLCD_writeDataBits(char dataToWrite);
char GLCD_readDataBits(void);
void GLCD_configToWriteData(void);
void GLCD_configToReadData(void);

#endif /* KS0108_STM32_H_ */
