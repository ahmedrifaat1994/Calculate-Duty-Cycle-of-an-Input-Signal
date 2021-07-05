/*
 * main.c
 *
 *  Created on: 6 Jun 2021
 *      Author: A.Rifaat
 */

#include "timer1.h"
#include "interrupt.h"
#include "lcd.h"

volatile uint16 read1 = 0;
volatile uint16 read2 = 0;
volatile uint16 read3 = 0;
volatile uint8 count = 0;
volatile uint8 start = 0;
volatile uint32 read = 0;

ISR(INT0_vect){
	if(start == 0){
		TIMER1_start();
		start = 1;
	}

	if (count == 0){
		count = 1;
	}
	else if(count == 1){
		read1 = TIMER1_read();
		count = 2;
	}
	else if(count == 2){
		read2 = TIMER1_read();
		count = 3;
	}
	else if(count == 3){
		read3 = TIMER1_read();
		count = 4;
	}
	//Toggle interrupt on falling edge and on rising edge
	MCUCR ^= (1<<ISC00);

}


int main(){
	uint16 read = 0;
	uint16 buffer[16];

	MCUCR = (1<<ISC01) | (1<<ISC00);
	DDRC = 0xff; /*Port C output*/

	DDRD = 0x0f; /*First 4 bits of port D input and last 4 bits output*/

	LCD_init();
	TIMER1_init();
	INT0_init();

	while(1){

		if(count == 4){
			TIMER1_stop();
			INT0_stop();
			read = ((float) (read3 - read2) / (read3 - read1)) * 100;
			itoa(read,buffer,10);
			LCD_displayStringRowColumn(0,0,buffer);
			LCD_displayString("%   ");
		}
	}
}

