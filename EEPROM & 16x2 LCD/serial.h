#include<reg51.h>
void init()
{
	TMOD=0x20;
	SCON=0x50;
	TH1=0xfd;
	TR1=1;
}

char rx()
{
	char c;
	while(RI==0);
	c=SBUF;
	RI=0;
	return c;
}

void tx(char c)
{
	SBUF=c;
	while(TI==0);
	TI=0;
}