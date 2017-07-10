//10 ms Delay

#include <avr/io.h>
#define F_CPU 8000000UL

void timer0_delay();

int main(void)
{
	DDRC = 0xFF;		//PortC output
	PORTC=0x00;			//Set as 0
	timer0_delay();
    while(1)
    {
		if (TCNT0 >= 77)
		{
			PORTC ^= (1 << PC0);    // toggles the output
			TCNT0 = 0;            // reset counter
		}	
    }
}

void timer0_delay()
{
	TCCR0 = (1<<CS02) | (1<<CS00);	 	//1024 PreScale Mode
	TCNT0 = 0;							//Load 0
	while(!(TCNT0 >= 77));  			// Wait for TCNT0 to exceed 77
	TCNT0 = 0;
}
  
