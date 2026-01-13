#include "main.h"

void SystemClockConfig(void)
{

	RCC->CR |= RCC_CR_HSION;
	while(!(RCC->CR & RCC_CR_HSIRDY));

	FLASH->ACR = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_2WS;

	RCC->PLLCFGR = (16 << 0)   // PLLM = 16
		           | (168 << 6)  // PLLN = 168 (84 MHz)
		           | (0 << 16)   // PLLP = 2
		           | (0 << 22)   // PLLSRC HSI
		           | (7 << 24);  // PLLQ para USB

	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));

	RCC->CFGR = RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_PPRE2_DIV1;

	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}
