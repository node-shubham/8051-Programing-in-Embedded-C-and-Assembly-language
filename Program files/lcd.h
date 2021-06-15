#include "delay_ms.h"
#ifndef _LCD_H_
#define _LCD_H_

#define LCD P2

sbit RS = P1^5;
sbit RW = P1^6;
sbit EN = P1^7;

void lcd_init(void);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_write(unsigned char ch);
void lcd_str(unsigned char *p);
void lcd_num(unsigned int i);

void lcd_init(void)
{
		lcd_cmd(0x38); // 8 bit, 5*7 pix selected
		lcd_cmd(0x01); // clear screen
		lcd_cmd(0x0c); // disp: ON, cursor: OFF, blink: OFF
		lcd_cmd(0x06); // shift cursor right side
		lcd_cmd(0x80); // move cursor to display : 1st position
}
void lcd_cmd(unsigned char ch)
{
		RS = 0;				 // command mode
		lcd_write(ch);
}
void lcd_write(unsigned char ch)
{
		LCD = ch;
		RW = 0;				 // write mode
		EN = 1;				 // high to low pulse
		delay_ms(5);
		EN = 0;
}
void lcd_data(unsigned char ch)
{
		RS = 1; 			// data mode
		lcd_write(ch);
}
void lcd_str(unsigned char *p)
{
		while(*p != '\0')
		{	
			lcd_data(*p++);
		}
}
void lcd_num(unsigned int i)
{
	int rem,sum=0;
	while(i)
	{
		sum =sum*10 + i%10;
		i= i/10;
	}
	i=sum;
	while(i)
	{
		rem = i%10;
		i=i/10;
		lcd_data(rem+48);	
	}	
}
#endif