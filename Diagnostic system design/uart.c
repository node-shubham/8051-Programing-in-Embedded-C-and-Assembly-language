#include<reg51.h>


void uart_init(void)
{
SCON=0x50;
TMOD=0x20;
TH1=253;
TR1=1;
}

void uart_txchar(char ch)
{
SBUF=ch;
while(TI==0);
TI=0;
}

void uart_txstr(char *p)
{
while(*p)
uart_txchar(*(p++));
}

char uart_rxchar()
{
while(RI==0);//waiting for rxn to complete
RI=0;
return SBUF;
}


void uart_txint(int n)
{
char str[10];
int i=0;
while(n)
{
str[i++]=n%10+48;
n=n/10;
}
i--;
for(i;i>=0;i--)
uart_txchar(str[i]);
}

void uart_txfloat(float f)
{char j,str[4];
uart_txint((int)f);
f=f-(int)f+1;
uart_txchar('.');
f=f*10000;
while(j<4)
{
str[j++]=(int)f%10+48;
f/=10;
}
while(j)
uart_txchar(str[--j]);
}

