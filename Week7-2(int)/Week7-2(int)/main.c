/*
 * Week7-2(int).c
 *
 * Created: 2022-04-12 오후 3:04:51
 * Author : imchanyang
 */ 

#include <avr/io.h>
#include "_main.h"

void delay(unsigned int i) {
	while(i--);
}

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

int main(void)
{
    DDRB = 0xff;
    while (1) 
    {
		PORTB = 0x00;
		// delay(0x100); clock 14.7456 Mhz 65535/14745600 sec So, fast
		_delay_ms(500);
		PORTB = 0xff;
		// delay(0x100);
		_delay_ms(500);
		PB_Lshift();
		_delay_ms(500);
		PB_Rshift();
    }
	
}

