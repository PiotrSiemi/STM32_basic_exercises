#ifndef MAIN_H_
#define MAIN_H_
#include <stdint.h>


#define ADDR_AHB1ENR_REG ((RCC_AHB1ENR_t*) 0x40023830)
#define ADDR_GPIOA_MODE_REG ((GPIOx_MODE_t*)0x40020000)
#define ADDR_GPIOA_OUT_REG ((GPIOx_ODR_t *)0x40020014)
#define ADDR_GPIOC_MODE_REG ((GPIOx_MODE_t*)0x40020800)
#define ADDR_GPIOC_IN_REG ((GPIOx_ODR_t *)0x40020810)
#define ADDR_GPIOC_PUD_REG ((GPIOx_PUPDR_t *)0x4002080C)
#define ADDR_GPIOA_OTYPE_REG ((GPIOx_OTYPER_t*)0x40020804)


typedef struct{
	uint32_t gpioa_en	:1;
	uint32_t gpiob_en	:1;
	uint32_t gpioc_en	:1;
	uint32_t gpiod_en	:1;
	uint32_t gpioe_en	:1;
	uint32_t reserved1	:2;
	uint32_t gpioh_en	:1;
	uint32_t reserved2	:4;
	uint32_t crcen		:1;
	uint32_t reserved3	:8;
	uint32_t dma1en		:1;
	uint32_t dma2en		:1;
	uint32_t reserved4	:9;
}RCC_AHB1ENR_t;

typedef struct{
	uint32_t pin_0  	:1;
	uint32_t pin_1  	:1;
	uint32_t pin_2  	:1;
	uint32_t pin_3  	:1;
	uint32_t pin_4  	:1;
	uint32_t pin_5  	:1;
	uint32_t pin_6  	:1;
	uint32_t pin_7  	:1;
	uint32_t pin_8  	:1;
	uint32_t pin_9  	:1;
	uint32_t pin_10 	:1;
	uint32_t pin_11 	:1;
	uint32_t pin_12 	:1;
	uint32_t pin_13 	:1;
	uint32_t pin_14 	:1;
	uint32_t pin_15 	:1;
	uint32_t reserved 	:16;
}GPIOx_ODR_t;

typedef struct{
	uint32_t pin_0  	:1;
	uint32_t pin_1  	:1;
	uint32_t pin_2  	:1;
	uint32_t pin_3  	:1;
	uint32_t pin_4  	:1;
	uint32_t pin_5  	:1;
	uint32_t pin_6  	:1;
	uint32_t pin_7  	:1;
	uint32_t pin_8  	:1;
	uint32_t pin_9  	:1;
	uint32_t pin_10 	:1;
	uint32_t pin_11 	:1;
	uint32_t pin_12 	:1;
	uint32_t pin_13 	:1;
	uint32_t pin_14 	:1;
	uint32_t pin_15 	:1;
	uint32_t reserved 	:16;
}GPIOx_IDR_t;

typedef struct{
	uint32_t pin_0  	:2;
	uint32_t pin_1  	:2;
	uint32_t pin_2  	:2;
	uint32_t pin_3  	:2;
	uint32_t pin_4  	:2;
	uint32_t pin_5  	:2;
	uint32_t pin_6  	:2;
	uint32_t pin_7  	:2;
	uint32_t pin_8  	:2;
	uint32_t pin_9  	:2;
	uint32_t pin_10 	:2;
	uint32_t pin_11 	:2;
	uint32_t pin_12 	:2;
	uint32_t pin_13 	:2;
	uint32_t pin_14 	:2;
	uint32_t pin_15 	:2;
}GPIOx_MODE_t;

typedef struct{
	uint32_t pin_0  	:1;
	uint32_t pin_1  	:1;
	uint32_t pin_2  	:1;
	uint32_t pin_3  	:1;
	uint32_t pin_4  	:1;
	uint32_t pin_5  	:1;
	uint32_t pin_6  	:1;
	uint32_t pin_7  	:1;
	uint32_t pin_8  	:1;
	uint32_t pin_9  	:1;
	uint32_t pin_10 	:1;
	uint32_t pin_11 	:1;
	uint32_t pin_12 	:1;
	uint32_t pin_13 	:1;
	uint32_t pin_14 	:1;
	uint32_t pin_15 	:1;
	uint32_t reserved 	:16;
}GPIOx_OTYPER_t;

typedef struct{
	uint32_t pin_0  	:2;
	uint32_t pin_1  	:2;
	uint32_t pin_2  	:2;
	uint32_t pin_3  	:2;
	uint32_t pin_4  	:2;
	uint32_t pin_5  	:2;
	uint32_t pin_6  	:2;
	uint32_t pin_7  	:2;
	uint32_t pin_8  	:2;
	uint32_t pin_9  	:2;
	uint32_t pin_10 	:2;
	uint32_t pin_11 	:2;
	uint32_t pin_12 	:2;
	uint32_t pin_13 	:2;
	uint32_t pin_14 	:2;
	uint32_t pin_15 	:2;
}GPIOx_PUPDR_t;

#endif /* MAIN_H_ */
