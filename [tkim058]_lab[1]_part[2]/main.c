/*
 * [tkim058]_lab[1]_part[2].c
 *	Partner(s) Name & E-mail: No partner yet
 *	Lab Section: B01
 *	Assignment: Lab #1  Exercise #2 
 *	Exercise Description: [Return available spaces]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	//DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs,
	DDRC = 0xFF; PORTC = 0x00;
	// initialize to 0s
	//unsigned char tmpB = 0x00; 	// Temporary variable to hold the value of B
	unsigned char p1 = 0x0000; // Temporary variable to hold the value of A
	unsigned char cntavail = 0;
	while(1)
	{
		
		p1 = PINA & 0x0F;
		if ((p1 == 0x01) || (p1 == 0x02) || (p1 == 0x04) || (p1 == 0x08))
		{
			cntavail = 0x03;
		}
		else if((p1 == 0x03) || (p1 == 0x05) || (p1 == 0x06) || (p1 == 0x09) || (p1 == 0x0A) || (p1 == 0x0C))
		{
			cntavail = 0x02;
		}
		else if((p1 == 0x07) || (p1 == 0x0B) || (p1 == 0x0E) || (p1 == 0x0D))
		{
			cntavail = 0x01;
		}
		else if(p1 == 0x0F)
		{
			cntavail = 0x00;
		}
		PORTC = cntavail;
	}
	return 0;
}

