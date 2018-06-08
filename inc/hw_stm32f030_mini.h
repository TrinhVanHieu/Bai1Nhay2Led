
#ifndef __HW_STM32F030_MINI_H__
#define __HW_STM32F030_MINI_H__


#define write_reg(addr, value)    *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)      *((unsigned long int *)(addr)) & (mask)

/*RCC - Clock*/
#define BASE_ADDRESS_RCC          0x40021000u

#define RCC_AHBENR                BASE_ADDRESS_RCC + 0x14
#define RCC_AHBENR_IOPCEN         0x00080000u //clock port C

#define enabled_clk()       do { \
                              unsigned long int tmpreg; \
                              tmpreg = read_reg(RCC_AHBENR, ~RCC_AHBENR_IOPCEN);\
                              tmpreg = tmpreg | RCC_AHBENR_IOPCEN; \
                              write_reg(RCC_AHBENR, tmpreg);\
                              delay(10); \
                            } while(0U)
/*GPIO - PORTC*/
#define BASE_ADDRESS_GPIOC 	0x48000800u			//Adress GPIOC 

#define GPIOC_MODER			(BASE_ADDRESS_GPIOC + 0x00u)  //MODER

#define GPIOC_IDR 			(BASE_ADDRESS_GPIOC + 0x10u) //Input
#define GPIOC_ODR 			(BASE_ADDRESS_GPIOC + 0x14u) //output ODR
#define GPIOC_OBSRR			(BASE_ADDRESS_GPIOC + 0x18u) //output BSRR

#define GPIO_MODE_INPUT 	0x00u 
#define GPIO_MODER_OUTPUT 	0x01u 

#define GPIO_MODER_ALT	 	0x02u
#define GPIO_MODER_ANALOG 	0x03u
/*User LD3 - PC9*/
#define LD3_PIN 			9

/*User LD4 - PC8*/
#define LD4_PIN 			8

/* end file */
#endif /* __HW_STM32F030_MINI_H__ */

