#include "main.h"

void ADC_GPIO_Init(void)
{
	RCC->AHB1ENR |= (1<<0); //IO port A clock enable
	GPIOA->MODER &= ~(3<<0); // Clean PA0
	GPIOA->MODER |= (3<<0); // PA0 as analog mode
}



void USART2_GPIO_Init(void)
{
	RCC->AHB1ENR |= (1<<0); // IO port A clock enable
	GPIOA->MODER &= ~((3<<4) | (3<<6)); //Clean PA2 and PA3
	GPIOA->MODER |= ((2<<4) | (2<<6)); // Set up PA2 and PA3 as AF
	GPIOA->OTYPER &= ~((1<<2) | (1<<3)); // Push-Pull
	GPIOA->OSPEEDR |= ((2<<4) | (2<<6)); // High Speed
	GPIOA->AFR[0] &= ~((0xF<<8) | (0xF<<12)); //Clean AF2 and AF3
	GPIOA->AFR[0] |= ((7<<8) | (7<<12)); // Set up AF2 and AF3

}
