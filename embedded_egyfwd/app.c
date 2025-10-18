


#include"app.h"
/***********************************GLOBAL VARIABLES******************/
uint8 g_ticks=0;
uint8 int0_flag=0;

/***********************************FUNCTIONS IMPLEMENTATIONS ********/
void timer1_interrupt_routine(void)
{

	if(g_ticks<24)
	{
		g_ticks++;

	}
	else
	{
		g_ticks=5;
	}
}


void interrupt0_routine(void)
{
	if(int0_flag==0)/*in case of pedestrians press more than one press*/
	{
		int0_flag=1;
	}

}


void initialize_system(void)
{
	                      /*enable interrupts */
	SREG|=(1<<7);

	                    /*initialize directions*/
	GPIO_setupPinDirection(PORTA_ID, PIN0_ID, PIN_OUTPUT);/*for LEDs*/
	GPIO_setupPinDirection(PORTA_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTD_ID, PIN2_ID, PIN_INPUT);/*for button*/

	                   /*initialize LEDs off*/
	 led_on_off(GREEN_CAR_LED_PORT,GREEN_CAR_LED_PIN, OFF);
	 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
	 led_on_off(RED_CAR_LED_PORT, RED_CAR_LED_PIN, OFF);
	 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN, OFF);
	 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);
	 led_on_off(RED_PEDESTRIAN_LED_PORT, RED_PEDESTRIAN_LED_PIN, OFF);

	                    /*start timer*/
	Timer1_ConfigType init_timer1;
	init_timer1.initial_value=0;
	init_timer1.mode=CTC;
	init_timer1.prescaler=CLK_1024; /*Ttick=1ms*/
	init_timer1.compare_value=1000;/*interrupt after 1s*/
	Timer1_init(&init_timer1);
	Timer1_setCallBack(timer1_interrupt_routine);

	               /*initialize interrupt*/
	set_interrupt init_int0;
	init_int0.number=interrupt0;
	init_int0.EDGE=FALLING_EDGE;
	init_interrupt(&init_int0);
	int0_setCallBack(interrupt0_routine);
}

void normal_mode(void)
{
	while(g_ticks<=4&&int0_flag==0)/*green car led on ...red pedestrian on*/
	{
		 led_on_off(RED_PEDESTRIAN_LED_PORT, RED_PEDESTRIAN_LED_PIN,ON);
		 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN,OFF);
		 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);

		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
		 led_on_off(RED_CAR_LED_PORT, RED_CAR_LED_PIN, OFF);
		 led_on_off(GREEN_CAR_LED_PORT, GREEN_CAR_LED_PIN, ON);
	}
	while(g_ticks==5&&int0_flag==0)/*blinking car yellow led....red pedestrian on*/
	{
		 led_on_off(RED_PEDESTRIAN_LED_PORT, RED_PEDESTRIAN_LED_PIN,ON);
		 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN,OFF);
		 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);


		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
		 led_on_off(RED_CAR_LED_PORT, RED_CAR_LED_PIN, OFF);
		 led_on_off(GREEN_CAR_LED_PORT, GREEN_CAR_LED_PIN, OFF);

	}
	while(g_ticks==6&&int0_flag==0)/*blinking car yellow led */
	{

		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);

	}
	while(g_ticks==7&&int0_flag==0)/*blinking car yellow led */
	{
		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
	}
	while(g_ticks==8&&int0_flag==0)/*blinking car yellow led */
	{

		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
	}
	while(g_ticks==9&&int0_flag==0)/*blinking car yellow led */
	{
		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
	}

	while(g_ticks<=14&&int0_flag==0)/*red car led on...green pedestrian on*/
	{
		 led_on_off(RED_PEDESTRIAN_LED_PORT, RED_PEDESTRIAN_LED_PIN,OFF);
		 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN,ON);
		 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);


		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
		 led_on_off(RED_CAR_LED_PORT, RED_CAR_LED_PIN, ON);
		 led_on_off(GREEN_CAR_LED_PORT, GREEN_CAR_LED_PIN, OFF);
	}
	while(g_ticks==15&&int0_flag==0)/*blinking car yellow led....green pedestrian on*/
	{
		 led_on_off(RED_PEDESTRIAN_LED_PORT, RED_PEDESTRIAN_LED_PIN,OFF);
		 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN,ON);
		 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);

		 led_on_off(RED_CAR_LED_PORT, RED_CAR_LED_PIN, OFF);
		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
		 led_on_off(GREEN_CAR_LED_PORT, GREEN_CAR_LED_PIN, OFF);
	}
	while(g_ticks==16&&int0_flag==0)/*blinking car yellow led */
	{
		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
	}
	while(g_ticks==17&&int0_flag==0)/*blinking car yellow led */
	{
		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
	}
	while(g_ticks==18&&int0_flag==0)/*blinking car yellow led */
	{
		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
	}
	while(g_ticks==19&&int0_flag==0)/*blinking car yellow led */
	{
		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
	}
	while(g_ticks>19&&g_ticks<=24&&int0_flag==0)/*red pedestrian on ..green car on*/
	{
		 led_on_off(RED_PEDESTRIAN_LED_PORT, RED_PEDESTRIAN_LED_PIN,ON);
		 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN,OFF);
		 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);


		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
		 led_on_off(RED_CAR_LED_PORT, RED_CAR_LED_PIN, OFF);
		 led_on_off(GREEN_CAR_LED_PORT, GREEN_CAR_LED_PIN, ON);
	}

}

void  pedestrian_mode(void)
{
	uint8 i;
	i=g_ticks; /*to store last case */
	Timer1_deInit();/*stop timer*/

	if(g_ticks>9&&g_ticks<=14) /*when red car led is on*/
	{
		g_ticks=0;
		initialize_system();/*to reset all leds and start timer again  */
		while(g_ticks<=4) /*green led pedestrian on ...red led car on  */
		{
			 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN,ON);
			 led_on_off(RED_CAR_LED_PORT, RED_CAR_LED_PIN, ON);
			 led_on_off(GREEN_CAR_LED_PORT, GREEN_CAR_LED_PIN, OFF);
		}
		while(g_ticks==5) /* toggle at the end of the state..red led car off ..green pedestrian on*/
		{
			 led_on_off(RED_CAR_LED_PORT, RED_CAR_LED_PIN, OFF);
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, ON);
			 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN,ON);
		}
		while(g_ticks==6)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);
		}

		while(g_ticks==7)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, ON);
		}

		while(g_ticks==8)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);
		}

		while(g_ticks==9)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, ON);
		}
		/*after 5s ...green led pedestrian off...red led pedestrian on ..green led car on*/
		 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN,OFF);
		 led_on_off(GREEN_CAR_LED_PORT, GREEN_CAR_LED_PIN,ON);
		 led_on_off(RED_PEDESTRIAN_LED_PORT, RED_PEDESTRIAN_LED_PIN,ON);
		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
		 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);


		g_ticks=i; /*to return normal mode again*/
	}

	else if(g_ticks<=4||(g_ticks>19&&g_ticks<=24)||(g_ticks>4&&g_ticks<10)||(g_ticks>14&&g_ticks<20))
		/*when green car led is on or yellow car led blinking  */
	{
		g_ticks=0;
		initialize_system();/*to reset all leds and start timer again  */
		while(g_ticks==0)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, ON);
			 led_on_off(RED_PEDESTRIAN_LED_PORT, RED_PEDESTRIAN_LED_PIN,ON);
		}
		while(g_ticks==1)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);
		}

		while(g_ticks==2)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, ON);
		}

		while(g_ticks==3)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);
		}

		while(g_ticks==4)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, ON);

		}
		while(g_ticks<=10) /*green pedestrian on.....red car on*/
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);
			 led_on_off(RED_PEDESTRIAN_LED_PORT, RED_PEDESTRIAN_LED_PIN,OFF);

			 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN,ON);
			 led_on_off(RED_CAR_LED_PORT, RED_CAR_LED_PIN,ON);
		}
		while(g_ticks==11) /* toggle at the end of the state..red led car off ..green pedestrian on*/
		{
			 led_on_off(RED_CAR_LED_PORT, RED_CAR_LED_PIN, OFF);
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, ON);
			 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN,ON);
		}
		while(g_ticks==12)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);
		}

		while(g_ticks==13)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, ON);
		}

		while(g_ticks==14)
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);
		}

		while(g_ticks==15) /* toggle at the end of the state*/
		{
			 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, ON);
			 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, ON);

		}

		/*after 5s ...green led pedestrian off...red led pedestrian on ..green led car on*/
		 led_on_off(GREEN_PEDESTRIAN_LED_PORT, GREEN_PEDESTRIAN_LED_PIN,OFF);
		 led_on_off(GREEN_CAR_LED_PORT, GREEN_CAR_LED_PIN,ON);
		 led_on_off(RED_PEDESTRIAN_LED_PORT, RED_PEDESTRIAN_LED_PIN,ON);
		 led_on_off(YELLOW_CAR_LED_PORT, YELLOW_CAR_LED_PIN, OFF);
		 led_on_off(YELLOW_PEDESTRIAN_LED_PORT, YELLOW_PEDESTRIAN_LED_PIN, OFF);

		g_ticks=i; /*to return normal mode again*/


	}

}
void APP_start(void)
{

	initialize_system();
	while(1)
	{
		normal_mode();
		if(int0_flag==1)
		{
			pedestrian_mode();
			int0_flag=0;
		}


	}




}
