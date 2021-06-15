#include<reg51.h>
void uart_init();
void uart_txchar(char);
void uart_txstring(char *);
main()
{
uart_init();
//uart_txchar('A');
while(1)
{
uart_txstring("laxmi");
//while(1);
}
}

void uart_init()
{
SCON=0x40;
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
void uart_txstring(char *p)
{
while(*p)
uart_txchar(*p++);
}

/*char uart_rxchar()                                                                                                                                           uart_rxchar()
{
while(RI==0);//waiting for rxn to complete
RI=0;
return(SBUF);
}*/

/*void uart_rxstr()
{
unsigned char a[15],i=0,ch;
while(1)
{
ch=uart_rxchar();
if(ch==0x0d)
{
a[i]='\0';
LCD_cmd(0x01);
break;
}
else
a[i++]=ch;
}
LCD_cmd(0x80);
LCD_str(a);
}

main()
{
uart_init();
LCD_init();
while(1)
{
uart_str("laxmi narasimha");
uart_rxstr();
}
}*/
