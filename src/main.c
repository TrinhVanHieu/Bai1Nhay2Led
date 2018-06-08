
#include "hw_stm32f030_mini.h"

void delay(unsigned int timeout)
{
   unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}
/*set mode GC8 - GC9*/
void init_pin (void)
{
	write_reg(GPIOC_MODER, 0x00050000u);
}

/*ON - OFF led*/
void turn_on (unsigned char pin)
{
	write_reg(GPIOC_OBSRR, 1 << pin);
}
void turn_off (unsigned char pin)
{
	write_reg(GPIOC_OBSRR, 1 << (pin + 16));
}

#if 0
void turn_on_led3 (void)
{
	write_reg(GPIOC_OBSRR, 1 << LD3_PIN);
}
void turn_off_led3 (void)
{
	write_reg(GPIOC_OBSRR, 1 << 25);
}
/*ON - OFF led4*/
void turn_on_led4 (void)
{
	write_reg(GPIOC_OBSRR, 1 << LD4_PIN);
}
void turn_off_led4 (void)
{
	write_reg(GPIOC_OBSRR, 1 << 24);
}
#endif

void main(void)
{
	/*enable clock*/
	enabled_clk();
	/*init_pin*/
	init_pin();
  while(1)
  {
	turn_on(LD3_PIN); turn_on(LD4_PIN);
	delay(0xff);
	turn_off(LD3_PIN); turn_off(LD4_PIN);
	delay(0xff);
  }
}

void Reserved_IRQHandler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void NMI_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void HardFault_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SVC_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void PendSV_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SysTick_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}


