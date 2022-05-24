.INCLUDE "M128DEF.INC"

	LDI R16, 10 ; R16 = 10 for counter
	LDI R20, 0 ; R20 = 0
	LDI R21, 3 ; R21 = 3 for value
AGAIN: 
	ADD R20, R21 ; R20 = R20 + R21, add 3 to R20
	DEC R16 ; R16--
	BRNE AGAIN ;repeat untill COUNT = 0, zero flag

	OUT PORTB, R20 ; send sum to PORTB
