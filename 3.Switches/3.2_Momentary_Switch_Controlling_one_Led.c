#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 80000000UL
int main()
{
	DDRA = DDRA & (~(1<<0));	//0 As Input
	DDRA = DDRA|(1<<5);			//5 As Output
	for(;;)
	{
		if(PINA & (1<<0))	//if input at pin 0 is 1 then		if!(PINA & (1<<0))	PullUp Switch
			PORTA = PORTA|(1<<5);
		else
			PORTA = PORTA&~((1<<5));	
	}	
}