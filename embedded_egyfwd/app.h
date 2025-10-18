/*
 * app.h
 *
 *  Created on: Nov 9, 2022
 *      Author: mohaned
 */

#ifndef APP_H_
#define APP_H_

/**********************************PREPROCCESORS***********************************/
#include"external_interrupts.h"
#include"gpio.h"
#include"std_types.h"
#include"timer1.h"
#include"led.h"
#include"common_macros.h"
#include<avr/interrupt.h>
#include<avr/io.h>

/*car leds*/
#define GREEN_CAR_LED_PORT PORTA_ID
#define YELLOW_CAR_LED_PORT PORTA_ID
#define RED_CAR_LED_PORT PORTA_ID
#define GREEN_CAR_LED_PIN PIN0_ID
#define YELLOW_CAR_LED_PIN PIN1_ID
#define RED_CAR_LED_PIN PIN2_ID

/*pedestrian leds*/
#define GREEN_PEDESTRIAN_LED_PORT PORTB_ID
#define YELLOW_PEDESTRIAN_LED_PORT PORTB_ID
#define RED_PEDESTRIAN_LED_PORT PORTB_ID
#define GREEN_PEDESTRIAN_LED_PIN PIN2_ID
#define YELLOW_PEDESTRIAN_LED_PIN PIN1_ID
#define RED_PEDESTRIAN_LED_PIN PIN0_ID

/**********************************FUNCTIONS PROTOTYPE***********************************/
/*ISR callback function of timer1 in each interrupt go to this function */
void timer1_interrupt_routine(void);
/*ISR callback function of interrupt0 in each interrupt go to this function */
void interrupt0_routine(void);
/*this function define all directions,initialize all leds to be off,
 *  put settings of timer1 and interrupt0 and start timer1 to count
 *   */
void initialize_system(void);
/*this is the normal mode of turning all leds on and off*/
void normal_mode(void);
/*when pedestrian press on the button*/
void  pedestrian_mode(void);
/*start application*/
void APP_start(void);



#endif /* APP_H_ */
