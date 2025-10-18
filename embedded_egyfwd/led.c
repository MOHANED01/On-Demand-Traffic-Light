/*
 * led.c
 *
 *  Created on: Nov 14, 2022
 *      Author: mohaned
 */
#include"led.h"

void led_on_off(uint8 port_num, uint8 pin_num, uint8 value)
{
		GPIO_writePin(port_num, pin_num, value);
}
