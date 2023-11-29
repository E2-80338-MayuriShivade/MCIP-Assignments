/*
 * led.c
 *
 *  Created on: Oct 2, 2023
 *      Author: mayuri
 */

#include "led.h"

void led_init(void)
{
	//enable clock for gpio D port
	RCC->AHB1ENR |= BV(GPIOD_CLK_ENB);

	//SELECT MODE OF GPIO PINS AS O/P
	LED_GPIO->MODER |=   BV(24) | BV(26) | BV(28) | BV(30);
    LED_GPIO->MODER &= ~(BV(25) | BV(27) | BV(29) | BV(31));

    //SELECT O/P TYPE AS A PUSH PULL
    LED_GPIO->OTYPER &= ~(BV(12) | BV(13) | BV(14) | BV(15));

    //SELECT O/P SPEED AS LOW
    LED_GPIO->OSPEEDR &= ~(BV(24) | BV(25) | BV(26) | BV(27) |BV(28) | BV(29) | BV(30) | BV(31));

    //DO NOT SELECT PULL UP/PULL DOWN RESISTOR
    LED_GPIO->PUPDR  &= ~(BV(24) | BV(25) | BV(26) | BV(27) |BV(28) | BV(29) | BV(30) | BV(31));

}
void led_on(void)
{
	//write 1 on respective bit
   	LED_GPIO->ODR |= BV(LED_GREEN) | BV(LED_ORANGE) | BV(LED_RED) | BV(LED_BLUE);
}

void led_off(void)
{
	//write 0 on respective bits of ODR
	LED_GPIO->ODR &= ~(BV(LED_GREEN) | BV(LED_ORANGE) | BV(LED_RED) | BV(LED_BLUE));
}
