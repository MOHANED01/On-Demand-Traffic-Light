
#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_
#include"std_types.h"
/*******************************************************************************
 *                              typedefs                                       *
 *******************************************************************************/
typedef enum
{
	LOW_LEVEL,ANY_CHANGE,FALLING_EDGE,RISING_EDGE
}set_edge;
typedef enum
{
	INT_OK,INT_NOT_OK
}INTERRUPT_state;
typedef enum
{
	interrupt0,interrupt1,interrupt2
}inerrupt_number;
typedef struct
{
	set_edge EDGE;
	inerrupt_number number;
}set_interrupt;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
INTERRUPT_state init_interrupt(set_interrupt *interrupt);
void int0_setCallBack(void(*a_ptr)(void));
void int1_setCallBack(void(*a_ptr)(void));
void int2_setCallBack(void(*a_ptr)(void));


#endif /* EXTERNAL_INTERRUPTS_H_ */
