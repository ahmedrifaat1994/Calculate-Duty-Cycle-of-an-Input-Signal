/*
 * timer1.c
 *
 *  Created on: 6 Jun 2021
 *      Author: A.Rifaat
 */

#include"timer1.h"

void TIMER1_init(void){
	TCCR1A |= (1<<FOC1A) | (1<<FOC1B); /*Enable overflow mode*/
	TCCR1B = 0; /*Stop timer1*/
	/*
	 * Timer1 is 16 bit equals to 65535 in decimal,
	 * to count 500 Hz, so every cycle equal to 2000 cycle f-cpu.
	 * 65535 / 2000 = 32.7, so we need to make this number even to remove any fractions
	 * so 64000 / 2000 = 32, we remove 1535 from 65535 to become 64000.
	 * */
	TCNT1 = 1535;
}

void TIMER1_start(void){
	TCCR1B |= (1<<CS10); /*Clock with no pre-scaler*/
}

uint16 TIMER1_read (void){
	return TCNT1 - 1535;
}

void TIMER1_stop(void){
	TCCR1B = 0;
}
