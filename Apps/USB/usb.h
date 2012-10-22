#ifndef MYUSB_H
#define MYUSB_H

#include "usb_lib.h"
#include "usb_desc.h"
#include "hw_config.h"
#include "usb_pwr.h"

//#define USB_CONNECT_PORT 	GPIOC
//#define USB_CONNECT_PIN 	GPIO_Pin_9
//#define USB_CONNECT_APB		RCC_APB2Periph_GPIOC

void USB_Config(void);			  
void USB_SendNBytes(uint8_t* buf, uint16_t cnt);
uint8_t USB_ReadOneByte(void);
uint8_t USB_RxBufNotEmpty(void);

#endif //MYUSB_H
