#include<avr/io.h>
#include<util/delay.h>
#include <stdbool.h>

#define F_CPU 80000000UL
int main()
{
	bool lastButton=false;
	bool ledStatus=false;
	DDRA = DDRA & (~(1<<0));	//0 As Input
	DDRA = DDRA|(1<<5);			//5 As Output
	int count=0;
	for(;;)
	{
		if(PINA & (1<<0))	//if input at pin 0 is 1 then		if(!(PINA & (1<<0)))	for PullUp Resistor
		{
			if (count %2 ==0)
				PORTA = PORTA|(1<<5);
			else
				PORTA = PORTA&(~(1<<5));
		count++;
		_delay_ms(50);
		}
	}	
}
