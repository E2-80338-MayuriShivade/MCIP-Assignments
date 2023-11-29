/*
 * switch.c
 *
 *  Created on: Oct 2, 2023
 *      Author: mayuri
 */

#include"switch.h"

void switch_init(uint16_t pin)
{
	RCC->AHB1ENR |= BV(GPIOA_CLK_ENB);

	SWITCH_GPIO->MODER &= ~(BV(pin*2) | BV(pin*2+1));

	SWITCH_GPIO->PUPDR &= ~(BV(pin*2) | BV(pin*2+1));

}
uint16_t switch_status(uint16_t pin)
{
	return SWITCH_GPIO->IDR & BV(pin) ? 1 : 0;
}
