#include<reg51f.h>	//---Including Reg file----

#define lcd P0			//---Assigning Port0 as a variable lcd 
	
		sbit rs = P0^0;	//-----Register Select pin of LCD
		sbit en = P0^1;	//-----Enable pin of LCD
		
//-----Proto-Type-------//
	void lcd_init();		//----LCD Initializing Function
	void toggle();		//----Latching function of LCD
	void lcd_cmd_hf(char v1);	//----Function to send half byte command to LCD
	void lcd_cmd(char v2);//----Function to send Command to LCD
	void lcd_dwr(char v3);//----Function to send data to LCD
	void lcd_msg(char *c);//----Function to Send String to LCD
	void delay(int ms);	//----Delay function
	void lcd_lef_sh();	//----Left Shifting Function
	void lcd_rig_sh();	//----Right Shifting Function
//----------------------//

//----Main Program-------//
	void main()
	{
			P0 = 0x00;	//---P0 as Output
			lcd_init();//---LCD initialize
			lcd_msg("CODE-N-LOGIC");
			lcd_cmd(0xC0);
			lcd_msg("Vignesh");
			while(1);
	}
//----End of Main Program----//
	
	void toggle()
	{
		en = 1;				//-----Latching data in to LCD data register using High to Low signal
		delay(1);
		en = 0;
	}
	
	void lcd_cmd_hf(char v1)
	{
		rs = 0; 							//----Selecting register as Command register
		lcd &= 0x0F;					//----clearing the Higher 4 bits
		lcd |= (v1 & 0xF0);		//----Masking higher 4 bits and sending to LCD
		toggle();					
	}
	
	void lcd_cmd(char v2)
	{
		rs = 0;								//----Selecting register as command register
		lcd &= 0x0F;					//----clearing the Higher 4 bits
		lcd |= (v2 & 0xF0);		//----Masking higher 4 bits and sending to LCD
		toggle();
		
		lcd &= 0x0F;						//----clearing the Higher 4 bits
		lcd |= ((v2 & 0x0F)<<4);	//----Masking lower 4 bits and sending to LCD
		toggle();
	}
	
	void lcd_dwr(char v3)
	{
		rs = 1;									//----Selecting register as command register
		lcd &= 0x0F;						//----clearing the Higher 4 bits
		lcd |= (v3 & 0xF0);		//----Masking higher 4 bits and sending to LCD
		toggle();
		
		lcd &= 0x0F;						//----clearing the Higher 4 bits
		lcd |= ((v3 & 0x0F)<<4);	//----Masking lower 4 bits and sending to LCD
		toggle();
	}
	
	void lcd_init()
	{
		lcd_cmd_hf(0x30);		//-----Sequence for initializing LCD
		lcd_cmd_hf(0x30);		//-----		"			 "				"				"
		lcd_cmd_hf(0x20);		//-----		"			 "				"				"
		lcd_cmd(0x28);			//-----Selecting 16 x 2 LCD in 4Bit mode 
		lcd_cmd(0x0C);			//-----Display ON Cursor OFF
		lcd_cmd(0x01);			//-----Clear display 
		lcd_cmd(0x06);			//-----Cursor Auto Increment
		lcd_cmd(0x80);			//-----1st line 1st location of LCD
	}
	
	void delay(int ms)
	{
		int i,j;
		for(i=0;i<=ms;i++)
			for(j=0;j<=120;j++);
	}
	
	void lcd_msg(char *c)
	{
		while(*c != 0)		//----Wait till all String are passed to LCD
			lcd_dwr(*c++);	//----Send the String to LCD
	}
	
	void lcd_rig_sh()
	{
		lcd_cmd(0x1C);		//----Command for right Shift
		delay(100);
	}
	
	void lcd_lef_sh()
	{
		lcd_cmd(0x18);		//----Command for Left Shift
		delay(100);
	}