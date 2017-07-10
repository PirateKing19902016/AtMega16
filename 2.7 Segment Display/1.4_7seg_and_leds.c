#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 80000000UL
#define stop 250
int main()
{
	char zero_to_nine[10] = {0x3f,0x06,0x5B,0x4f,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
	int i;
	DDRC=0xff;
	DDRD=0xff;
	DDRA=0xff;
	
	PORTA=0x00;
	PORTD=0x00;

	for(;;)
	{
		for(i=7;i>=0;i--)
			{
				_delay_ms(stop);
				PORTC=zero_to_nine[i];
				PORTD=(1<<i);
				
			}
			PORTD=0x00;
		
		for(i=0;i<8;i++)
			{
				_delay_ms(stop);
				PORTC=zero_to_nine[i];
				PORTA=(1<<i);
				
			}
			PORTA=0x00;
			
	}
}