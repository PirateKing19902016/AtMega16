#include <avr/io.h>
#include <util/delay.h>

volatile uint8_t button_down;


static inline void debounce(void)
{
static uint8_t count = 0;
static uint8_t button_state = 0;

uint8_t current_state = (~PINA & ((1<<0))) != 0;
	if (current_state != button_state) 
	{
		count++;
		if (count >= 4) 
		{

			button_state = current_state;
			
			if (current_state != 0) 
				button_down = 1;
			
			count = 0;
		}
	}
	else 
		count = 0;
	
}


int main(void)
{

PORTA = PORTA|(1<<0);	//Setting PortA as 1 

DDRB = DDRB|(1<<0);
	while(1)
	{

		debounce();

		if (button_down)
		{
			button_down = 0;
			PORTB = PORTB^(1<<0);	//toggling PortB0 b/w 0 & 1
		}
		_delay_ms(10);
	}
}
