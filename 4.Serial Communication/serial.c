#include <avr/io.h>		
#define F_CPU		8000000UL	
#define BAUD RATE	9600

//--- Proto Type Declaration ---//
void usart_init(void);	
void usart_tx(unsigned char x);

char tx_data=0x20;
int main(void)
{
	usart_init();	
    while(1)
    {
		usart_tx(tx_data);
		usart_tx('A');
    }
}


void usart_init()
{

	UBRRL = 0x33;
	UCSRB = (1<<TXEN);
	UCSRC = (1<<URSEL) | (1<<UCSZ1)| (1<<UCSZ0);
}

void usart_tx(unsigned char x)
{
	UDR = x;
	while (!(UCSRA & (1<<TXC)));

}
