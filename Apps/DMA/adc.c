#include "adc.h"

#define ADC1_DR_Address    ((uint32_t)0x4001244C)
#define ADC_DMA_TransferCompleteInterrupt

void ADCwithDMA_Config(void){
	ADC_InitTypeDef ADC_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;	   
	#ifdef ADC_DMA_TransferCompleteInterrupt  
		NVIC_InitTypeDef NVIC_InitStructure;
	#endif //ADC_DMA_TransferCompleteInterrupt
	
	ADC.uVoltsPerUnit = 13702; // 24060000 / 1756;
	ADC.unitsOffset = 0;
	//	ADC.logicZeroMax_mV = 0;
	//	ADC.logicOneMin_mV = 1756;

	//DMA 
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); 
	
	/* PCLK2 is the APB2 clock */
	/* ADCCLK = PCLK2/6 = 72/6 = 12MHz*/
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	/* Enable ADC1 clock so that we can talk to it */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	/* Put everything back to power-on defaults */
	ADC_DeInit(ADC1);
	
	/* DMA1 channel1 configuration ----------------------------------------------*/
	DMA_DeInit(DMA1_Channel1);
	DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&(ADC.raw[0]);
	// Data direction: Peripheral is source
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	// Data Buffer Size
	DMA_InitStructure.DMA_BufferSize = ADC_Channels;
	// Do not increment Peripheral Address Register
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	// Do increment destination memory pointer
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	// Transport data repeatedly
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	// Memory to Memory Mode Disabled
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	// Enable DMA Channel
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);      
	#ifdef ADC_DMA_TransferCompleteInterrupt
		/* Enable DMA1 Channel Transfer Complete interrupt */
		DMA_ITConfig(DMA1_Channel1, DMA_IT_TC, ENABLE);
	#endif //ADC_DMA_TransferCompleteInterrupt
	/* Enable DMA1 channel1 */
	DMA_Cmd(DMA1_Channel1, ENABLE);

	#ifdef ADC_DMA_TransferCompleteInterrupt	
		/* Enable DMA1 channel1 IRQ Channel */
		NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel1_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
	#endif //ADC_DMA_TransferCompleteInterrupt
	 
	/* ADC1 configuration ------------------------------------------------------*/
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	// number of ADC channels that will be converted using the sequencer
	ADC_InitStructure.ADC_NbrOfChannel = ADC_Channels;
	ADC_Init(ADC1, &ADC_InitStructure);
	/* ADC1 regular channels configuration */ 
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_71Cycles5); //INP1
	ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 2, ADC_SampleTime_71Cycles5); //INP2
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 3, ADC_SampleTime_71Cycles5); //INP3
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 4, ADC_SampleTime_71Cycles5); //INP4
	ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 5, ADC_SampleTime_71Cycles5); //INP5
	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 6, ADC_SampleTime_71Cycles5); //INP6
	ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 7, ADC_SampleTime_71Cycles5); //INP7
	ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 8, ADC_SampleTime_71Cycles5); //INP8
	ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 9, ADC_SampleTime_71Cycles5); //SEN12
	ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 10, ADC_SampleTime_71Cycles5); //SEN5
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 11, ADC_SampleTime_71Cycles5); //ISEN1

	/* Enable ADC1 DMA */
	ADC_DMACmd(ADC1, ENABLE);
	
	/* Enable ADC1 */
	ADC_Cmd(ADC1, ENABLE);
	
	/* Enable ADC1 reset calibaration register */   
	ADC_ResetCalibration(ADC1);
	/* Check the end of ADC1 reset calibration register */
	while(ADC_GetResetCalibrationStatus(ADC1));
	
	/* Start ADC1 calibaration */
	ADC_StartCalibration(ADC1);
	/* Check the end of ADC1 calibration */
	while(ADC_GetCalibrationStatus(ADC1));
	
	/* Start ADC1 Software Conversion */ 
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

void DMA1_Channel1_IRQHandler(void)
{
	uint8_t i;
	s16 raw;

	for(i=0; i<ADC_Channels; i++){
		raw = ADC.raw[i] - ADC.unitsOffset;
		if(raw < 0)
			raw = 0;

		ADC.milivolt[i] = raw * ADC.uVoltsPerUnit / 1000;
		ADC.volt[i] = ADC.milivolt[i] / 1000;

		/*
		if(ADC.milivolt[i] <= ADC.logicZeroMax_mV)
			ADC.digital[i/8] &= ~(1 << (i%8));
		else if(ADC.milivolt[i] >= ADC.logicOneMin_mV)
			ADC.digital[i/8] |= (1 << (i%8));
		 */
	}

	DMA_ClearITPendingBit(DMA1_IT_TC1);
}


