#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 80000000UL
int main()
{
	int i=0;
	DDRA=0xff;

	for(;;)
	{
		for(i=0;i<8;i++)
		{	
			_delay_ms(1000);
			PORTA=PORTA|(1<<i);
			_delay_ms(1000);
			
		}
		PORTA=PORTA&(0x00);
	}
}