	/***
 	The program that reads the state of the pin (PA0).
   	   If the state is high (VCC applied) - bright up the built-in diode.
   	   If the status is low - the LED remains off.

	Program for MCU STM32F411RE.
	- Using only bare metal C.
	- No use of header files and libraries (except <stdint.h>).
	- No macros.
	 ***/

#include <stdint.h>


int main(void)
{

	uint32_t volatile *pClockControlRegister  = (uint32_t*)0x40023830; 			// Clock register
	uint32_t volatile *pPortModeRegister_A 	  = (uint32_t*)0x40020000; 			// Mode register
	uint32_t volatile *pPortOutputRegister_A  = (uint32_t*)0x40020014; 			// ODR register
	uint32_t volatile *pPortModeRegister_A0   = (uint32_t*)0x40020000; 			// Mode register (doubled for A0)
	uint32_t volatile *pPortInputRegister_A0  = (uint32_t*)0x40020010; 			// IDR register


	*pClockControlRegister|= (1<<0);							//Clock initialization

												//PA5 as output
	*pPortModeRegister_A &= ~(3 << 10);
	*pPortModeRegister_A |= (1 << 10);



												//PA0 as input
	*pPortModeRegister_A0 &= ~(3 << 0);



while(1)
	{
	uint8_t volatile  A0_pin_status = (uint8_t) (*pPortInputRegister_A0 & 0x1); 		//Read the PA0 pin status
		if(A0_pin_status)
		{
		*pPortOutputRegister_A |= (1 << 5);
		}else{
		*pPortOutputRegister_A &= ~(1 << 5);
		}
	}
}
