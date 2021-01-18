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
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char cntavail = 0x00; // Temporary variable to hold the value of C
	unsigned char tmpA0 = 0x00; //Car space 0
	unsigned char tmpA1 = 0x00; //Car space 1
	unsigned char tmpA2 = 0x00; //Car space 2
	unsigned char tmpA3 = 0x00; //Car space 3
while(1) {
		// 1) Read input
		tmpA0 = PINA & 0x01; //This gets the first bit, LSB
                tmpA1 = (PINA & 0x02) >> 1; //This gets the second bit,
	        tmpA2 = (PINA & 0x04) >> 2; //Gets 3rd
		tmpA3 = (PINA & 0x08) >> 3; //Gets 4th
		// 2) Perform computation
		//Where each pin is a parking space, PORTC should output binary number of available spots
		
		cntavail = 0x04 - tmpA0 - tmpA1 - tmpA2 - tmpA3;
		cntavail = cntavail & ~(0x01 << 4);
		cntavail = cntavail & ~(0x01 << 5);
		cntavail = cntavail & ~(0x01 << 6);
	
		if(cntavail == 0x00){
			cntavail = (cntavail | 0x01 << 7); 
		}	
		
		// 3) Write output
		PORTC = cntavail;
	}
	return 0;
}
