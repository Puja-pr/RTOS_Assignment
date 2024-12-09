/*
 * led.c
 *
 *  Created on: Oct 2, 2023
 *      Author: sunbeam
 */
#include"led.h"

void led_init(uint32_t pin)
{
	// enable clock for gpio D port
	RCC->AHB1ENR |= BV(GPIOD_CLK_ENB);

	// select mode of GPIO pins as output
	LED_GPIO->MODER |= BV(pin * 2);
	LED_GPIO->MODER &= ~BV(pin *2 + 1);

	// select output type as push pull
	LED_GPIO->OTYPER &= ~BV(pin);

	// select output speed as low
	LED_GPIO->OSPEEDR &= ~(BV(pin *2)| BV(pin *2 +1)) ;


	// do not select pull up / pull down resistor
	LED_GPIO->PUPDR &= ~(BV(pin * 2) | BV(pin *2 +1));

}
void led_on(uint32_t pin)
{
	// write 1 on respective bits of ODR
	LED_GPIO->ODR |= BV(pin);
}
void led_off(uint32_t pin)
{
	// write 0 on respective bits of ODR
	LED_GPIO->ODR &= ~BV(pin);
}


void led_toggle(uint32_t pin)
{
	LED_GPIO->ODR ^= BV(pin);
}
