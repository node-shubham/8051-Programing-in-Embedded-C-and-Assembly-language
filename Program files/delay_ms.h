#ifndef _DELAY_H_
#define _DELAY_H_

void delay_ms(unsigned int i)
{
		unsigned char j;
		for(;i>0;i--)
		{
				for(j=250;j>0;j--);
				for(j=204;j>0;j--);	
		}
}		
#endif