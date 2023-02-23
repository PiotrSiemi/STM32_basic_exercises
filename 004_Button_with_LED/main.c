	/***
	Program for the interaction of the built-in button with the built-in LED (PA5 pin).
  	  No interaction with the button - the LED is off.
  	  Button pressed - the LED is on.

	Program for MCU STM32F411RE.
	- Using only bare metal C.
	- No use of header files and libraries (except <stdint.h>).
	- No macros.
	***/

#include <stdint.h>

int main(void)
{

	uint32_t volatile *const pClockControlRegister 	= (uint32_t*)0x40023830; 			// Clock
	uint32_t volatile *const pPortModeRegister_A 	= (uint32_t*)0x40020000;			// Mode register GPIOA
	uint32_t volatile *const pPortOutputRegister_A  = (uint32_t*)0x40020014; 			// ODR register GPIOA
	uint32_t volatile *const pPortModeRegister_C 	= (uint32_t*)0x40020800;			// Mode register GPIOC
	uint32_t volatile *const pPortInputRegister_C  	= (uint32_t*)0x40020810;			// IDR register GPIOC
	uint32_t volatile *const pPullUpDownRegister_C  = (uint32_t*)0x4002080C;			// PUDR register GPIOC
	uint32_t volatile *const pOtyper_GPIO_A  	= (uint32_t*)0x40020804;			// Otyper register GPIOA

	*pClockControlRegister|= (5<<0);								//GPIOA, GPIOC clock initialization


													// PA5 as output
	*pPortModeRegister_A &= ~(3 << 10);
	*pPortModeRegister_A |= (1 << 10);
	*pOtyper_GPIO_A &= ~(1 << 5); 									// Push-pull  LED


													// PC13 as input
	*pPortModeRegister_C &= ~(3 << 26);
													// PC13 PUDR
	*pPullUpDownRegister_C  &= ~(3 << 26);
	*pPullUpDownRegister_C  |= (1 << 26);

	while (1) {
	  uint32_t idr_val = (~(*pPortInputRegister_C) & (1 << 13));					//Pin read
	  if (idr_val){
	    *pPortOutputRegister_A |= (1 << 5);
	  }else{
	    *pPortOutputRegister_A &= ~(1 << 5);
	  }
	}
}
