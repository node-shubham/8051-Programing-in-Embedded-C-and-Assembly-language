#include<reg52.h>

sbit sw = P1^7;
sbit led = P1^0;
sbit wave = P2^5;

void timer_0(void) interrupt 1
{
	wave = ~wave;
}	
main()
{
	sw=1;
	TMOD = 0x02;
	TH0 = 0xA4;
	IE = 0x82;
	TR0=1;
	while(1)
	{
		led =sw;
	}
}