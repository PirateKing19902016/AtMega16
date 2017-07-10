#include <avr/io.h>	

#define F_CPU		8000000UL




void usart_init(void);
void usart_tx(char x);
char usart_rx(void);
void usart_msg(char *c);

char tx_data;

int main(void)
{
	usart_init();
	//usart_msg("INITIALIZING USART");
	usart_tx(0x0d);
    while(1)
    {
		 //usart_msg("<<");
         tx_data = usart_rx();
		 //usart_tx(0x0d);
		 //usart_msg(">>");
		 usart_tx(tx_data);
		 //usart_tx(0x0d);
    }
}

//--- Proto Type Declaration ---//

void usart_init()
{
	UBRRH = 0x00;						//--- Initialize UBRR value for Baud Rate
	UBRRL = 0x33;						//--- Baud Rate Set as 9600 by Data Sheet
	UCSRB = (1<<TXEN) | (1<<RXEN);		//--- Transmit and Receive Enable
	UCSRC = (1<<URSEL) | (3<<UCSZ0);	//--- 8 bit data and UCSRC is selected
}

void usart_tx(char x)
{
	UDR = x;							//--- Move data to UDR Data Reg
	while (!(UCSRA & (1<<UDRE)));		//--- Check whether UDR is empty
}

char usart_rx()
{
	while (!(UCSRA & (1<<RXC)));		//--- Check whether Receive is complete
	return(UDR);						//--- Return Data from UDR
}

void usart_msg(char *c)
{
	while (*c != 0)						//--- Check for null
		usart_tx(*c++);					//--- Increment the pointer 
}
