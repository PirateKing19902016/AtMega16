#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 80000000UL
#define stop 350
int main()
{
	char zero_to_nine[10] = {0x3f,0x06,0x5B,0x4f,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
	char i,j;
	DDRD=0xff;
	DDRC=0xff;
	
	for(;;)
	{
		for(i=0;i<10;i++)
			{
				
				PORTC=zero_to_nine[i];
				_delay_ms(stop);
				for(j=1;j<10;j++)
				{
					
					PORTD=zero_to_nine[j];
					_delay_ms(stop);
				}
				PORTD=0x3f;
			}
		
		PORTC=0x3f;
		//else there is delay when changing
	}
}
