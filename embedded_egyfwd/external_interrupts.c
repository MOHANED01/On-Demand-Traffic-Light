
#include"external_interrupts.h"
#include"std_types.h"
#include"avr/io.h"
#include"avr/interrupt.h"
static volatile void (*g_callBackPtr_int0)(void) = NULL_PTR;
static volatile void (*g_callBackPtr_int1)(void) = NULL_PTR;
static volatile void (*g_callBackPtr_int2)(void) = NULL_PTR;
INTERRUPT_state init_interrupt(set_interrupt *interrupt)
{
	INTERRUPT_state state;
	if((interrupt->number)>2||(interrupt->number)<0)
	{
		 state=INT_NOT_OK;
	}
	else
	{
		state=INT_OK;
		switch(interrupt->number)
		{
		case 0 :
			MCUCR|=interrupt->EDGE; /*enable edge needed*/
			GICR|=(1<<INT0);/*set module interrupt enable*/
			break;
		case 1:
			MCUCR|=interrupt->EDGE; /*enable edge needed*/
			GICR|=(1<<INT1);/*set module interrupt enable*/
			break;
		case 2:
			if(interrupt->EDGE==FALLING_EDGE)
			{
				MCUCSR&=~(1<<ISC2);
			}
			else if(interrupt->EDGE==RISING_EDGE)
			{
				MCUCSR|=(1<<ISC2);
			}
			else
			{
				state=INT_NOT_OK;
			}
			GICR|=(1<<INT2);/*set module interrupt enable*/
			break;

		}

	}
	return state;

}
void int0_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr_int0=a_ptr;

}
void int1_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr_int1=a_ptr;
}
void int2_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr_int2=a_ptr;
}


ISR(INT0_vect)
{
	if(g_callBackPtr_int0 != NULL_PTR)
		{
			(*g_callBackPtr_int0)();
		}
}
ISR(INT1_vect)
{
	if(g_callBackPtr_int1 != NULL_PTR)
		{
			(*g_callBackPtr_int1)();
		}
}
ISR(INT2_vect)
{
	if(g_callBackPtr_int2 != NULL_PTR)
		{
			(*g_callBackPtr_int2)();
		}
}




