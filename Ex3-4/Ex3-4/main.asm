; Write a program to determine if RAM location 0x200 contains the value 0.
; If so, put 0x55 into it

.INCLUDE "m128def.inc"
.EQU MYLOC= 0x200 ; define

	LDS R30, MYLOC
	TST R30 ; set the flag
	BRNE NEXT ; branch if R30 is not 0(zero)
	LDI R30, 0x55 ; put 0x55 if R30 has zero value
	STS MYLOC, R30

NEXT:
	JMP NEXT