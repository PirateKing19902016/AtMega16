#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 8000000UL
			  8000000UL
int main()
{
	DDRA=0xff;

	for(;;)
	{
		PORTA=0xff;
		_delay_ms(1000);
		PORTA=0x00;
		_delay_ms(1000);
	}
}