#include<reg52.h>
#include "delay_ms.h"
sbit led = P0^0;
main()
{
	while(1)
	{
		led =1;
		delay_ms(500);
		led =0;
		delay_ms(500);
	}	
}