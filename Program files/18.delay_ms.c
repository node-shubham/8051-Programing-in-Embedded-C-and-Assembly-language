#include<reg51.h>

void delay_ms(unsigned int i);
sbit pin =P2^1;
main()
{
		while(1)
		{
			pin =1;
			delay_ms(500);
			pin =0;
			delay_ms(500);
		}	
}

void delay_ms(unsigned int i)
{
		unsigned char j;
		for(;i>0;i--)
		{
				for(j=250;j>0;j--);
				for(j=204;j>0;j--);	
		}
}		