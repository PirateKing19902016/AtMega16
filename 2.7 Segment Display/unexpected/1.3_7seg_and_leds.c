#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 80000000UL
#define stop 250
int main()
{
	unsigned char zero_to_nine[10] = {0x3f,0x06,0x5B,0x4f,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
	unsigned char i;
	DDRC=0xff;

	while(1)
	{
		//PORTC=0xff;
		for(i=9;i>=0;i--)
			{
				_delay_ms(stop);
				PORTC=zero_to_nine[i];
				
			}

		//PORTC=0x00;
	}
}
