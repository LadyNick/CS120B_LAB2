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
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA0 = 0x00; //Door sensor
	unsigned char tmpA1 = 0x00; //Light sensor
while(1) {
		// 1) Read input
		tmpA0 = PINA & 0x01; //This gets the first bit, LSB
                tmpA1 = PINA & 0x02; //This gets the second bit, 
		// 2) Perform computation
		//only when PA0 == 1, && PA1 == 0, will tmpB be 1
		
		if((tmpA0 == 1) && (tmpA1 == 0)){
			tmpB = 1;
		}
		else{
			tmpB = 0;
		}	
		
		// 3) Write output
		PORTB = tmpB;
	}
	return 0;
}
