#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 80000000UL
#define stop 10
int main()
{
	char zero_to_nine[10] = {0x3f,0x06,0x5B,0x4f,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
	char i,j,k,l;
	DDRD=0xff;
	DDRC=0xff;
	DDRB=0xff;
	DDRA=0xff;
	
	
	for(;;)
	{
		for(i=0;i<6;i++)
			{
				
				PORTA=zero_to_nine[i];
				_delay_ms(stop);
				for(j=0;j<10;j++)
				{
					
					PORTB=zero_to_nine[j];
					_delay_ms(stop);
					for(k=0;k<6;k++)
					{
						
						PORTC=zero_to_nine[k];
						_delay_ms(stop);
						for(l=1;l<10;l++)
						{
							
							PORTD=zero_to_nine[l];
							_delay_ms(stop);
						}
						PORTD=0x3f;
					}
					PORTC=0x3f;
				}
				PORTB=0x3f;
			}
		
		PORTA=0x3f;
		//else there is delay when changing
	}
}