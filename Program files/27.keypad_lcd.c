#include<reg52.h>
#include "delay_ms.h"
#include "lcd.h"

sbit C1 = P2^0;
sbit C2 = P2^1;
sbit C3 = P2^2;
sbit C4 = P2^3;
sbit R1 = P2^4;
sbit R2 = P2^5;
sbit R3 = P2^6;
sbit R4 = P2^7;

char keypad[4][4]= {{'1','2','3','4'},{'5','6','7','8'},{'9','0','A','B'},{'C','D','E','F'}};
void main()
{
		int row,col;
		lcd_init();
		while(1)
		{	
				P2 = 0X0F; // P2.7-P2.4 =0 P2.3-P2.0 =1 
				while(C1&C2&C3&C4); // WAIT TILL PRESS
				delay_ms(10);
				if(P2==0X0E) // OR C1=0
					col=0;
				if(P2==0X0D) // OR C2=0
					col=1;
				if(P2==0X0B) // OR C3=0
					col=2;
				if(P2==0X07) // OR C4=0
					col=3;
								
				P2 = 0XF0;
				delay_ms(10);
				if(P2==0XE0) // OR R1=0
					row=0;
				if(P2==0XD0) // OR R2=0
					row=1;
				if(P2==0XB0) // OR R3=0
					row=2;
				if(P2==0X70) // OR R4=0
					row=3;
				
				while(!(R1&R2&R3&R4)); // WAIT TILL RELEASE
				lcd_data(keypad[row][col]);	
				delay_ms(200);
		}
}		