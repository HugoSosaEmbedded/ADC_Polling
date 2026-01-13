#include "main.h"

void USART2_Init(void)
{
	RCC->APB1ENR |=(1<<17); //USART2 clock enable
	USART2->CR1 &= ~(1<<12); // Word length is configured as 8 bit
	USART2->CR2 &= ~((1<<12) | (1<<13)); // 1 Stop bit
	USART2->CR1 &= ~(1<<15); // Oversamoling by 16
	USART2->BRR = 0x16C; // Baud Rate 115200
	USART2->CR1 |= (1<<3); // Transmitter is enabled
	USART2->CR1 |= (1<<13); // USART enabled

}


