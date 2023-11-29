/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include<stm32f407xx.h>

#define BV(n)(1 << (n))

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void gpio_init(void);
void gpio_led_on(void);
void gpio_led_off(void);

int main(void)
{
	gpio_init();
	while(1)
	{
		gpio_led_on();
		DelayMs(1000);
		gpio_led_off();
		DelayMs(1000);

	}
}
void gpio_init(void){
	//enable clock
	RCC->AHB1ENR |= BV(3);

	//set gpio mode
	GPIOD->MODER &= ~(BV(25)| BV(27) | BV(29) | BV(31));
	GPIOD->MODER |= (BV(24) | BV(26) | BV(28) | BV(30));

	//SET TYPE AS PUSH PULL

	GPIOD->OTYPER &= ~(BV(12) | BV(13) | BV(14) | BV(15));

	//SET SPEED AS LOW SPEED

	GPIOD->OSPEEDR &= ~(BV(25) | BV(27) | BV(29) | BV(31));
	GPIOD->OSPEEDR &= ~(BV(24) | BV(26) | BV(28) | BV(30));

	//DISABLE PULL UP/PULL DOWN RESISTOR
	GPIOD->PUPDR &= ~(BV(25) | BV(27) | BV(29) | BV(31));
	GPIOD->PUPDR &= ~(BV(24) | BV(26) | BV(28) | BV(30));
}
void gpio_led_on(void){
	GPIOD->ODR |= BV(15) ;
	DelayMs(500);
	GPIOD->ODR |= BV(14) ;
	DelayMs(700);
	GPIOD->ODR |= BV(13) ;
	DelayMs(600);
	GPIOD->ODR |= BV(12) ;
	DelayMs(800);
}
void gpio_led_off(void){
	GPIOD->ODR &= BV(15);
	DelayMs(1200);
	GPIOD->ODR &= BV(14);
	DelayMs(1300);
	GPIOD->ODR &= BV(13);
	DelayMs(1400);
	GPIOD->ODR &= BV(12);
	DelayMs(1500);
}