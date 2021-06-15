#include"delay.h"
#include"lcd1.h"
#include<reg51.h>

#define lcd P0

sbit rs=P3^4;
sbit rw=P3^5;
sbit en=P3^6;

//code char LUT

void LCD_disp(char ch)
{
rw=0;
lcd=ch;
en=1;
delay_ms(2);
en=0;
}

void LCD_cmd(char cmd)
{
rs=0;
LCD_disp(cmd);
}

void LCD_init()
{
delay_ms(20);
LCD_cmd(0x30);
delay_ms(8);
LCD_cmd(0x30);
delay_ms(2);
LCD_cmd(0x30);
delay_ms(2);
LCD_cmd(0x38);
LCD_cmd(0x10);
LCD_cmd(0x01);
LCD_cmd(0x06);
LCD_cmd(0x0e);
}

void LCD_char(char ch)
{
rs=1;
LCD_disp(ch);
}

void LCD_str(char *p)
{
while(*p!='\0')
LCD_char(*p++);
}


