.INCLUDE "m128def.inc"

	LDI	R20, 0xFF	
	OUT	DDRB, R20	;make PORTD an output port
REP1:
	
	SBI	PORTB,0		;set bit PD0
	CALL	DELAY		;delay before next one
	SBI	PORTB,1		;turn on PD1
	CALL	DELAY		;delay before next one
	SBI	PORTB,2		;turn on PD2
	CALL	DELAY	
	SBI	PORTB,3		
	CALL	DELAY	
	SBI	PORTB,4	
	CALL	DELAY	
	SBI	PORTB,5	
	CALL	DELAY	
	SBI	PORTB,6	
	CALL	DELAY	
	SBI	PORTB,7	
	CALL	DELAY
	LDI	R20, 0x00	
	OUT	PORTB, R20
	RJMP REP1


DELAY:
	LDI	R20,32
L1:	LDI	R21,200
L2:	LDI	R22,250 ; 8Mhz   1/(8*1,000,000)  s  
L3:	
	NOP
	NOP
	DEC	R22
	BRNE	L3
	DEC	R21
	BRNE	L2
	DEC	R20
	BRNE	L1
	RET