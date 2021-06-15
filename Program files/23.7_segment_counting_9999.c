#include<reg51.h>
#include "delay_ms.h"
#define seg P2
sbit sel_1 = P3^0;
sbit sel_2 = P3^1;
sbit sel_3 = P3^2;
sbit sel_4 = P3^3;
code char LUT[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90}; 
main()
{
	unsigned char i,j,k,l;
	sel_1= sel_2= sel_3= sel_4= 1; //all segments are OFF
	while(1)
	{
			for(i=0;LUT[i];i++)
				for(j=0;LUT[j];j++)
					for(k=0;LUT[k];k++)
						for(l=0;LUT[l];l++)
						{
							sel_1 = 0;  // seg 1 ON
							seg = LUT[i];
							delay_ms(50);
							sel_1 = 1;	// seg 1 OFF					
							
							sel_2 = 0;	// seg 2 ON
							seg = LUT[j];
							delay_ms(50);
							sel_2 = 1;	// seg 2 OFF
							
							sel_3 = 0;	// seg 3 ON
							seg = LUT[k];
							delay_ms(50);
							sel_3 = 1;	// seg 3 OFF
							
							sel_4 = 0;	// seg 4 ON
							seg = LUT[l];
							delay_ms(50);
							sel_4 = 1;	// seg 4 OFF
						}
	}		
}