; Write a program to (a) load the PORTB register with the value Ox55, and (b) complement Port b 700 times

; General purpose resiter is 8bit -- > max number is 255
; so, We sue nest loop
;700 times loop --> 1st loop 10 * 2nd loop 70

.INCLUDE "m128def.inc"
.ORG 0

	LDI R16, 0x55 ; R16 = 0x55
	OUT PORTB, R16 ; PORTB = 0x55
	LDI R20, 10 ; Outer loop counter
LOOP_1:
	LDI R21, 70 ; Inner loop counter
LOOP_2: 
	COM R16 ; complement
	DEC R21 ; decrease R21(Inner loop)
	OUT PORTB, R16
	BRNE LOOP_2 ; repeat 70times

	DEC R20 ; decrease R20(Outer loop)
	BRNE LOOP_1 ; repeat 10times
