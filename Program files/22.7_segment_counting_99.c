#include<reg51.h>
#include "delay_ms.h"
#define seg P2
sbit sel_1 = P3^0;
sbit sel_2 = P3^1;

code char LUT[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90}; 
main()
{
	unsigned char i,j;
	sel_1 = sel_2 = 1; //  both segments are OFF
	while(1)
	{
			for(i=0;LUT[i];i++)
			{
					
					for(j=0;LUT[j];j++)
					{
							sel_1 = 0;
							seg = LUT[i];
							delay_ms(50);
							sel_1 = 1;
						
							sel_2 = 0;
							seg = LUT[j];
							delay_ms(50);
							sel_2 = 1;
					}
			}
	}		
}