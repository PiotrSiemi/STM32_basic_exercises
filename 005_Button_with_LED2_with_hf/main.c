	/***
	Program for the interaction of the built-in button with the built-in LED (PA5 pin).
  	  No interaction with the button - the LED is off.
  	  Button pressed - the LED is on.

	Program for MCU STM32F411RE.
	- Using self-made header file "main.h"
	***/

#include <stdint.h>
#include "main.h"

int main(void)
{

	RCC_AHB1ENR_t  volatile *const pClockControlRegister = ADDR_AHB1ENR_REG; 			// Clock
	GPIOx_MODE_t   volatile *const pPortModeRegister_A 	 = ADDR_GPIOA_MODE_REG;			// Mode register GPIOA
	GPIOx_ODR_t    volatile *const pPortOutputRegister_A = ADDR_GPIOA_OUT_REG; 			// ODR register GPIOA
	GPIOx_MODE_t   volatile *const pPortModeRegister_C 	 = ADDR_GPIOC_MODE_REG;			// Mode register GPIOC
	GPIOx_ODR_t    volatile *const pPortInputRegister_C  = ADDR_GPIOC_IN_REG;			// IDR register GPIOC
	GPIOx_PUPDR_t  volatile *const pPullUpDownRegister_C = ADDR_GPIOC_PUD_REG;			// PUD register GPIOC
	GPIOx_OTYPER_t volatile *const pOtyper_GPIO_A  		 = ADDR_GPIOA_OTYPE_REG;		// Otype register GPIOA

	pClockControlRegister->gpioa_en = 1;												//GPIOA clock initialization
	pClockControlRegister->gpioc_en = 1;												//GPIOC clock initialization

	pPortModeRegister_A->pin_5 = 1;														// PA5 as output
	pOtyper_GPIO_A->pin_5 = 0; 															// Push-pull LED

	pPortModeRegister_C->pin_13 = 0;													// PC13 as input

	pPullUpDownRegister_C->pin_13 = 1;													// PC13 PUDR

	while (1) {
	  uint32_t idr_val = pPortInputRegister_C->pin_13;									//Pin read
	  if (idr_val){
	    pPortOutputRegister_A->pin_5 = 0;
	  }else{
	    pPortOutputRegister_A->pin_5 = 1;
	  }
	}
}
