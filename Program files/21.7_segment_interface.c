#include<reg51.h>
#include "delay_ms.h"
#define seg P2
sbit sel_1 = P3^0;
sbit sel_2 = P3^1;

code char LUT[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90}; 
main()
{
	unsigned char i;
	sel_1 = 0;
	while(1)
	{
			for(i=0;LUT[i];i++)
			{
					seg = LUT[i];
					delay_ms(700);
			}
	}		
}