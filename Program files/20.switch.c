#include<reg51.h>
#include "delay_ms.h"
#define led P2

sbit sw = P1^0 ;

main()
{
	while(1)
	{
		while(sw==0)
		{
			led = 0x00;
			delay_ms(400);
			led = 0xff;
			delay_ms(400);
		}
	}		
}