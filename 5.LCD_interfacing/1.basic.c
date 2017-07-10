#include<avr/io.h>
#define	F_CPU	1000000
#include<util/delay.h>
#include<avr/lcd.h>	// copy to C:\WinAVR-20100110\avr\include\avr\lcd.h

#define		LCD_DATA_PORT		PORTB
#define 	LCD_CONT_PORT		PORTD

#define 	LCD_RS 		PD0
#define 	LCD_RW 		PD1
#define 	LCD_EN 		PD2



int main(void)
{
	DDRB=0xff;	// PortB as output 
	DDRD=0x07;	// LSB PortD as Output
	
	char first_row_lcd_display[]="ABLab Solutions", second_row_lcd_display[]="www.ablab.in";
	
	lcd_init();
	lcd_string_write(first_row_lcd_display);
	lcd_command_write(0xc0);
	lcd_string_write(second_row_lcd_display);
	
}


