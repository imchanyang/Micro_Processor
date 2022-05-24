/*
 * Week7-3(another_interrupt).c
 *
 * Created: 2022-04-12 오후 3:40:30
 * Author : imchanyang
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "_main.h" // headerfile about interrupt
#define F_CPU 14745600UL
// when interrupt led switch
char Direction;
SIGNAL(INT0_vect) 
{
	Direction = ~Direction;
} // external interrupt 

void PB_Lshift(void) {
	char LED;
	LED = 0xfe; // 1111_1110
	for(int i = 0; i < 8; i++) {
		_delay_ms(500);
		PORTB = LED;
		LED = (LED << 1) | 0x01; // 0000_0001
	}
}

void PB_Rshift(void) {
	char LED;
	LED = 0x7f; // 0111_1111
	for(int i = 0; i < 8; i++) {
		_delay_ms(500);
		PORTB = LED;
		LED = (LED >> 1) | 0x80; // 1000_0000
	}
}

void interrupt_init(void) {
	EICRA = 0x02; //0000_0010 control register : falling edge setting
	EIMSK = 0x01;//0000_0001 0th interrupt(int0) use setting
	DDRD = 0x00; // d port : input 
	SREG |= 0x80; // 1000_0000 
}

int main(void)
{
    DDRB = 0xff;
	
	PORTB = 0x0f; // 0000_1111
	Direction = 0;
	
    while (1) 
    {	interrupt_init();
		if(Direction != 0) {
			PB_Lshift();
		}
		else {
			PB_Rshift();
		}
		
    }
}

