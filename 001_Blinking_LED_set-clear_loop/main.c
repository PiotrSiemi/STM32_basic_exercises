	/***
	Program for blinking the built-in diode (PA5 pin).

	Program for STM32F411RE MCU.
	- Using only bare-metal C.
	- No use of header files and libraries (apart from <stdint.h>).
	- No macros.
	***/

#include <stdint.h>

void Delay(void);

int main(void)
{

	uint32_t volatile *const pClockControlRegister  = (uint32_t*)0x40023830; 		//Clock register
	uint32_t volatile *const pPortModeRegister_A 	= (uint32_t*)0x40020000; 		//Mode register
	uint32_t volatile *const pPortOutputRegister_A  = (uint32_t*)0x40020014; 		//ODR register



	*pClockControlRegister|= (1); 								//Clock initialization

												//PA5 as an output
	*pPortModeRegister_A &= ~(3 << 10); 							//10 and 11 bit as zeros
	*pPortModeRegister_A |= (1 << 10); 							//10 bit as 1


	while(1) 										//LED blinking loop (set-clear)
	{
	*pPortOutputRegister_A |= (1 << 5);
	Delay();
	*pPortOutputRegister_A &= ~(1 << 5);
	Delay();
	}

}

void Delay(void)
{
	for(uint32_t i = 0; i < 300000; i++);							//150ms delay
}
