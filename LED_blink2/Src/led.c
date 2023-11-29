/*
 * led.c
 *
 *  Created on: Oct 2, 2023
 *      Author: mayuri
 */

#include "led.h"

void led_init(uint16_t pin)
{
	//enable clock for gpio D port
	RCC->AHB1ENR |= BV(GPIOD_CLK_ENB);

	//SELECT MODE OF GPIO PINS AS O/P
	LED_GPIO->MODER |=   BV(2 * pin);
    LED_GPIO->MODER &= ~BV(2 * pin + 1);

    //SELECT O/P TYPE AS A PUSH PULL
    LED_GPIO->OTYPER &= ~BV(pin);

    //SELECT O/P SPEED AS LOW
    LED_GPIO->OSPEEDR &= ~(BV(2 * pin) | BV(2 * pin + 1));

    //DO NOT SELECT PULL UP/PULL DOWN RESISTOR
    LED_GPIO->PUPDR &= ~(BV(2 * pin) | BV(2 * pin + 1));
}
void led_on(uint16_t pin)
{
	//write 1 on respective bit
   	LED_GPIO->ODR |= BV(pin);
}

void led_off(uint16_t pin)
{
	//write 0 on respective bits of ODR
	LED_GPIO->ODR &= ~BV(pin);
}
void led_toogle(uint16_t pin)
{
	LED_GPIO->ODR ^=BV(pin);
}
