#include "main.h"

void ADC_Init(void)
{
	RCC->APB2ENR |= (1 << 8); //ADC1 clock enable

	ADC1->CR2 &= ~(1<<11); // Right Alignment
	ADC1->CR1 &= ~(3<<24); // 12 bit resolution (15 ADCCLK cycles)
	ADC1->CR2 |= (1<<1); // Continuous conversion mode
	ADC1->SQR1 &= ~(0xF<<20);
	ADC1->SQR1 |= (0<<20); // 1 conversion L = 0
	ADC1->SQR3 &= ~(0x1F<<0);
	ADC1->SQR3 |= (0<<0); //1st conversion in regular sequence
	ADC1->SMPR2 &= ~(7<<0); //24 cycles in CH0
	ADC1->SMPR2 |= (2<<0); //24 cycles in CH0
	ADC->CCR &= ~(3<<16); //Clean bits 17:16
	ADC->CCR |= (1<<16); //PCLK2 divided by 4
	ADC1->CR2 |= (1<<0); //A/D converter ON
	for(volatile int h = 0; h < 1000; h++); // Delay (~1-2us)
	ADC1->CR2 |= (1<<30); //Starts conversion of regular channels
}
