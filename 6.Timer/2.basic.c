//10 ms Delay

#include <avr/io.h>
#define F_CPU 8000000UL

void timer0_delay();

int main(void)
{
	DDRC = 0xFF;		//PortC output
	PORTC=0x00;			//Set as 0
    	while(1)
    	{
			PORTC ^= (1 << PC0);
			timer0_delay();
    	}
}

void timer0_delay()
{
	TCCR0 = (1<<CS02) | (1<<CS00);	 	//1024 PreScale Mode
	TCNT0 = 178;//TCNT0 = 0xB2;  						//Load 178
	while((TIFR&0x01)==0);  			// Wait for TOV0 to roll over
	TCCR0 = 0;
	TIFR = 0x1;  						//Clear TOV0 flag
}
