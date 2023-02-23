	/***
	Program for toggling the built-in diode (PA5 pin) in different way (XOR operator)

	Program for STM32F411RE MCU.
	- Using self-made header file "main.h"
	***/

#include <stdint.h>
#include "main.h"

void Delay(void);

int main(void)
{

	RCC_AHB1ENR_t volatile *const pClockControlRegister = ADDR_AHB1ENR_REG; 	//Clock register
	GPIOx_MODE_t  volatile *const pPortModeRegister_A 	= ADDR_GPIOA_MODE_REG; 	//Mode register
	GPIOx_ODR_t   volatile *const pPortOutputRegister_A = ADDR_GPIOA_OUT_REG; 	//ODR register


	pClockControlRegister->gpioa_en = 1;										//Clock initialization

	pPortModeRegister_A->pin_5 = 1;												//PA5 as output

	while(1) 																	//LED blinking loop (XOR)
	{
	pPortOutputRegister_A->pin_5 ^= 1;
	Delay();
	}

}

void Delay(void)
{
	for(uint32_t i = 0; i < 300000; i++);										//150ms delay
}

