//-------------------------------------------------------------------------------------------------
// Universal KS0108 driver library
// STM32 MCU low-level driver
// (c) Rados�aw Kwiecie�, radek@dxp.pl
//-------------------------------------------------------------------------------------------------
#include "stm32f10x_conf.h"
#include "KS0108-STM32.h"

#define KS0108_RS_port	GPIOA
#define KS0108_RS_pin	GPIO_Pin_8
#define KS0108_RW_port	GPIOC
#define KS0108_RW_pin	GPIO_Pin_8
#define KS0108_EN_port	GPIOA
#define KS0108_EN_pin	GPIO_Pin_10

#define KS0108_CS1_port	GPIOD
#define KS0108_CS1_pin	GPIO_Pin_14
#define KS0108_CS2_port	GPIOD
#define KS0108_CS2_pin	GPIO_Pin_15

#define KS0108_LED_port	GPIOC
#define KS0108_LED_pin	GPIO_Pin_9

#define DISPLAY_STATUS_BUSY	0x80

extern unsigned char screen_x;
extern unsigned char screen_y;

//					DB0			DB1			DB2			DB3			DB4			DB5			DB6			DB7
GPIO_TypeDef *LCDPort[] = {	GPIOB,		GPIOE,		GPIOE,		GPIOE,		GPIOE,		GPIOD,		GPIOD,		GPIOD};
int LCDPin[] = {	GPIO_Pin_10,GPIO_Pin_15,GPIO_Pin_14,GPIO_Pin_13,GPIO_Pin_12,GPIO_Pin_11,GPIO_Pin_12,GPIO_Pin_13};

GPIO_InitTypeDef GPIO_InitStructure;

//-------------------------------------------------------------------------------------------------
// Delay function /for 8MHz/
//-------------------------------------------------------------------------------------------------
void GLCD_Delay(void)
{
	int i = 0;
	while (++i<100)
		;
	asm("nop");asm("nop");asm("nop");asm("nop");
}
//-------------------------------------------------------------------------------------------------
// Enalbe Controller (0-2)
//-------------------------------------------------------------------------------------------------
void GLCD_EnableController(unsigned char controller)
{
switch(controller){
	case 0 : GPIO_ResetBits(KS0108_CS1_port, KS0108_CS1_pin); break;
	case 1 : GPIO_ResetBits(KS0108_CS2_port, KS0108_CS2_pin); break;
	//case 2 : GPIO_ResetBits(KS0108_PORT, KS0108_CS3); break;
	}
}
//-------------------------------------------------------------------------------------------------
// Disable Controller (0-2)
//-------------------------------------------------------------------------------------------------
void GLCD_DisableController(unsigned char controller)
{
switch(controller){
	case 0 : GPIO_SetBits(KS0108_CS1_port, KS0108_CS1_pin); break;
	case 1 : GPIO_SetBits(KS0108_CS2_port, KS0108_CS2_pin); break;
	//case 2 : GPIO_SetBits(KS0108_PORT, KS0108_CS3); break;
	}
}
//-------------------------------------------------------------------------------------------------
// Read Status byte from specified controller (0-2)
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadStatus(unsigned char controller)
{
unsigned char status;

//GPIO_StructInit(&GPIO_InitStructure);
//GPIO_InitStructure.GPIO_Pin = 0xFF << KS0108_D0;
//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
//GPIO_Init(KS0108_PORT, &GPIO_InitStructure);
GLCD_configToReadData();

GPIO_SetBits(KS0108_RW_port, KS0108_RW_pin);
GPIO_ResetBits(KS0108_RS_port, KS0108_RS_pin);
GLCD_EnableController(controller);
GLCD_Delay();
GPIO_SetBits(KS0108_EN_port, KS0108_EN_pin);
GLCD_Delay();
status = GLCD_readDataBits();//((GPIO_ReadInputData(KS0108_PORT) >> KS0108_D0) & 0xFF);
GPIO_ResetBits(KS0108_EN_port, KS0108_EN_pin);
GLCD_DisableController(controller);
return status;
}
//-------------------------------------------------------------------------------------------------
// Write command to specified controller
//-------------------------------------------------------------------------------------------------
void GLCD_WriteCommand(unsigned char commandToWrite, unsigned char controller)
{
while(GLCD_ReadStatus(controller)&DISPLAY_STATUS_BUSY);
//GPIO_StructInit(&GPIO_InitStructure);
//GPIO_InitStructure.GPIO_Pin  = (0xFF << KS0108_D0);
//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//GPIO_Init(KS0108_PORT, &GPIO_InitStructure);
GLCD_configToWriteData();

GPIO_ResetBits(KS0108_RS_port, KS0108_RS_pin);
GPIO_ResetBits(KS0108_RW_port, KS0108_RW_pin);
GLCD_Delay();
GLCD_EnableController(controller);
GLCD_Delay();
//GPIO_SetBits(KS0108_PORT, (commandToWrite << KS0108_D0));
//commandToWrite ^= 0xFF;
//GPIO_ResetBits(KS0108_PORT, (commandToWrite << KS0108_D0));
GLCD_writeDataBits(commandToWrite);
GLCD_Delay();
GPIO_SetBits(KS0108_EN_port, KS0108_EN_pin);
GLCD_Delay();
GPIO_ResetBits(KS0108_EN_port, KS0108_EN_pin);
GLCD_Delay();
GLCD_DisableController(controller);
}

//-------------------------------------------------------------------------------------------------
// Read data from current position
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadData(void)
{
unsigned char tmp;
while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
//GPIO_StructInit(&GPIO_InitStructure);
//GPIO_InitStructure.GPIO_Pin = 0xFF << KS0108_D0;
//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
//GPIO_Init(KS0108_PORT, &GPIO_InitStructure);
GLCD_configToReadData();

GPIO_SetBits(KS0108_RS_port, KS0108_RS_pin);
GPIO_SetBits(KS0108_RW_port, KS0108_RW_pin);

GLCD_EnableController(screen_x / 64);
GLCD_Delay();
GPIO_SetBits(KS0108_EN_port, KS0108_EN_pin);
GLCD_Delay();
tmp = GLCD_readDataBits();//((GPIO_ReadInputData(KS0108_PORT) >> KS0108_D0) & 0xFF);
GPIO_ResetBits(KS0108_EN_port, KS0108_EN_pin);
GLCD_DisableController(screen_x / 64);
screen_x++;
return tmp;
}
//-------------------------------------------------------------------------------------------------
// Write data to current position
//-------------------------------------------------------------------------------------------------
void GLCD_WriteData(unsigned char dataToWrite)
{
while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
   
//GPIO_StructInit(&GPIO_InitStructure);
//GPIO_InitStructure.GPIO_Pin = (0xFF << KS0108_D0);
//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//GPIO_Init(KS0108_PORT, &GPIO_InitStructure);
GLCD_configToWriteData();

GPIO_ResetBits(KS0108_RW_port, KS0108_RW_pin);
GLCD_Delay();
GPIO_SetBits(KS0108_RS_port, KS0108_RS_pin);
GLCD_Delay();
//GPIO_SetBits(KS0108_PORT, (dataToWrite << KS0108_D0));
//dataToWrite ^= 0xFF;
//GPIO_ResetBits(KS0108_PORT, (dataToWrite << KS0108_D0));
GLCD_writeDataBits(dataToWrite);
GLCD_Delay();
GLCD_EnableController(screen_x / 64);
GLCD_Delay();
GPIO_SetBits(KS0108_EN_port, KS0108_EN_pin);
GLCD_Delay();
GPIO_ResetBits(KS0108_EN_port, KS0108_EN_pin);
GLCD_Delay();
GLCD_DisableController(screen_x / 64);
screen_x++;
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_InitializePorts(void)
{
vu32 i;

RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE, ENABLE);

GPIO_StructInit(&GPIO_InitStructure);
GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_2MHz;
GPIO_InitStructure.GPIO_Mode  =  GPIO_Mode_Out_PP;

GPIO_InitStructure.GPIO_Pin   =  KS0108_EN_pin;
GPIO_Init(KS0108_EN_port, &GPIO_InitStructure);
GPIO_InitStructure.GPIO_Pin   =  KS0108_RS_pin;
GPIO_Init(KS0108_RS_port, &GPIO_InitStructure);
GPIO_InitStructure.GPIO_Pin   =  KS0108_RW_pin;
GPIO_Init(KS0108_RW_port, &GPIO_InitStructure);
GPIO_InitStructure.GPIO_Pin   =  KS0108_CS1_pin;
GPIO_Init(KS0108_CS1_port, &GPIO_InitStructure);
GPIO_InitStructure.GPIO_Pin   =  KS0108_CS2_pin;
GPIO_Init(KS0108_CS2_port, &GPIO_InitStructure);
GPIO_InitStructure.GPIO_Pin   =  KS0108_LED_pin;
GPIO_Init(KS0108_LED_port, &GPIO_InitStructure);
for(i=0; i<8; i++){
	GPIO_InitStructure.GPIO_Pin   =  LCDPin[i];
	GPIO_Init(LCDPort[i], &GPIO_InitStructure);
}

GPIO_SetBits(KS0108_RS_port, KS0108_RS_pin);
GPIO_SetBits(KS0108_RW_port, KS0108_RW_pin);
GPIO_SetBits(KS0108_CS1_port, KS0108_CS1_pin);
GPIO_SetBits(KS0108_CS2_port, KS0108_CS2_pin);
GLCD_writeDataBits(0x00);
GLCD_writeDataBits(0xff);

GPIO_SetBits(KS0108_LED_port, KS0108_LED_pin);

//GPIO_Write(KS0108_PORT, KS0108_CS1 | KS0108_CS2 | KS0108_CS3 | KS0108_RS | KS0108_RW | (0xFF << KS0108_D0));
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadByteFromROMMemory(char * ptr)
{
  return *(ptr);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_writeDataBits(char dataToWrite)
{
	uint32_t i;

	for(i=0; i<8; i++)
	{
		char bit = dataToWrite & 1;
		GPIO_SetBits(LCDPort[i], (bit)?(LCDPin[i]):0);
		GPIO_ResetBits(LCDPort[i], (1-bit)?(LCDPin[i]):0);
		dataToWrite >>= 1;
	}
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
char GLCD_readDataBits(void)
{
	uint32_t i;
	char ret = 0;

	for(i=0; i<8; i++)
	{
		ret |= (GPIO_ReadInputDataBit(LCDPort[i], LCDPin[i]) << (i));
	}
	return ret;
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_configToWriteData(void){
	uint32_t i;

	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode  =  GPIO_Mode_Out_PP;

	for(i=0; i<8; i++){
		GPIO_InitStructure.GPIO_Pin   =  LCDPin[i];
		GPIO_Init(LCDPort[i], &GPIO_InitStructure);
	}

}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_configToReadData(void){
	uint32_t i;

	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_2MHz;
//	GPIO_InitStructure.GPIO_Mode  =  GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Mode  =  GPIO_Mode_IN_FLOATING;

	for(i=0; i<8; i++){
		GPIO_InitStructure.GPIO_Pin   =  LCDPin[i];
		GPIO_Init(LCDPort[i], &GPIO_InitStructure);
	}

}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------

