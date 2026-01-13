#include "main.h"
#include <stdio.h>

extern void USART2_Init(void);
extern void USART2_GPIO_Init(void);
extern void ADC_Init(void);
extern void ADC_GPIO_Init(void);
extern void SystemClockConfig(void);

char buffer[32];
uint16_t volatile ADC_Data = 0;

int main()
{
	SystemClockConfig();
	ADC_GPIO_Init();
	ADC_Init();
	USART2_GPIO_Init();
	USART2_Init();

	while(1)
	{

		while(!(ADC1->SR & (1<<1))); //Wait to conversion is complete
		ADC_Data = ADC1->DR;

		float voltaje_medido = (ADC_Data/4095.0) * 3.3;
		float aceleración_g = (voltaje_medido - 1.61) / 0.3;

		int i = 0;

		sprintf(buffer, "Aceleration_x: %.2f\r\n", aceleración_g);
		while(buffer[i] != '\0')
		{
			while(!(USART2->SR & (1<<7)));
			USART2->DR = buffer[i];
			i++;
		}

		while(!(USART2->SR & (1<<6))); // Waiting until transmission is complete
		for(volatile int j = 0; j<1000000; j++);
	}
	return 0;
}
