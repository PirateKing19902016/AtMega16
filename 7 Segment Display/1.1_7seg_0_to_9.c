#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 80000000UL
int main()
{
	char zero_to_nine[10] = {0x3f,0x06,0x5B,0x4f,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
	char i;
	DDRD=0xff;

	for(;;)
	{
		for(i=0;i<10;i++)
			{
				_delay_ms(1000);
				PORTD=zero_to_nine[i];
				_delay_ms(1000);
			}
		PORTD=0x00;
	}
}