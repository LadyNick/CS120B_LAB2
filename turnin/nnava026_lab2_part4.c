/*	Author: lab
 *  Partner(s) Name: N/A
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #Before the exercises
 *	Exercise Description: [optional - include for your own benefit]
 *	This is part of the lab manual that comes before any of the exercises.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF; // Configure port D's 8 pins as outputs, initialize to 0s
	DDRD = 0XFF; PORTD = 0x00;
	unsigned char total = 0x00;
while(1) {	
		total = PORTA + PORTB + PORTC;
		total = total << 5;
		PORTD = total;

		if((PORTA - PORTC) > 0x50){
			PORTD = PORTD | (0x01 << 1);	
		}
		if((PORTA + PORB + PORC) > 0x80){
			PORTD = PORTD | (0x01 << 0);
		}
	}
	return 0;
}
