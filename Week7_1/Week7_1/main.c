/*
 * Week7_1.c
 *
 * Created: 2022-04-11 오후 2:33:32
 * Author : imcha
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>


char count;

SIGNAL(INT0_vect) {
	count++;
}

void Interrupt_init(void) {
	EICRA = 0x02;
	EIMSK = 0x01;
	DDRD = 0x00;
	SREG |= 0x80;
}


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		Interrupt_init();
		DDRB = 0xFF;
		DDRD = 0x00;
		count = 0;
		while(1) {
			PORTB = ~count;
			if(count >= 255) count = 0;
		}
    }
	
	return 0;
}

