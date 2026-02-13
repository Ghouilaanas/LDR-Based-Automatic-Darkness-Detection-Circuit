/*
 * main.h
 *
 *      Author: AnasGhouila
 */

#ifndef MAIN_H_
#define MAIN_H_

#define RCC                     (*(volatile uint32_t*)0x40021000)
#define RCC_APB2ENR             (*(volatile uint32_t*) 0x40021018)
#define GPIOA                   (*(volatile uint32_t*)0x40010800)
#define GPIOA_ODR               (*(volatile uint32_t*)0x4001080C)
#define GPIOA_IDR               (*(volatile uint32_t*)0x40010808)
#define GPIOA_MODER             (*(volatile uint32_t*)0x40010800)
#define RCC_CFGR                (*(volatile uint32_t*)0x40021004)
#define FLASH_ACR               (*(volatile uint32_t*)0x40022000)
#define RCC_CR                  (*(volatile uint32_t*)0x40021000)
#define RCC_APB2ENR_GPIOAEN     (1<<2)
#define RELAY_PIN_POS            7

#endif /* MAIN_H_ */
