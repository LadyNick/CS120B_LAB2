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
	DDRA = 0x00; PINA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PINB = 0xFF;
	DDRC = 0x00; PINC = 0xFF; // Configure port D's 8 pins as outputs, initialize to 0s
	DDRD = 0XFF; PORTD = 0x00;
	unsigned char total = 0x00;
while(1) {	
		total = PINA + PINB + PINC;
		total = total >> 2;


		PORTD = total;

		if((PINC - PINA) > 80){
			PORTD = PORTD | (0x01 << 1);	
		}
		else{
			PORTD = PORTD & ~(0x01 << 1);
		}
		if((PINA + PINB + PINC) > 0x8C){
			PORTD = PORTD | (0x01 << 0);
		}
		else{
			PORTD = PORTD & ~(0x01 << 0);
		}
	}
	return 0;
}
