/*
 * led.h
 *
 *  Created on: Nov 14, 2022
 *      Author: mohaned
 */

#ifndef LED_H_
#define LED_H_

#include"gpio.h"
#define ON LOGIC_HIGH
#define OFF LOGIC_LOW

void led_on_off(uint8 port_num, uint8 pin_num, uint8 value);

#endif /* LED_H_ */
