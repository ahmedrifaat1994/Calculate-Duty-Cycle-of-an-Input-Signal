/*
 * interrupt.c
 *
 *  Created on: 6 Jun 2021
 *      Author: A.Rifaat
 */

#include "interrupt.h"

void INT0_init(void){
	SREG |= (1<<7);
	MCUCR = (1<<ISC00) | (1<<ISC01); /*Enable interrupt on rising edge*/
	GICR |= (1<<INT0); /*Enable interrupt 0*/
}

void INT0_stop(void){
	SREG &= ~(1<<7);
}
