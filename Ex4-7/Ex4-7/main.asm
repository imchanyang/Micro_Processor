.INCLUDE "m128def.inc"

	LDI R16, 0x00
	OUT DDRD, R16
	LDI R16, 0xff
	OUT DDRB, R16
L1:
	IN R20, PIND
	OUT PORTB, R20
	RJMP L1