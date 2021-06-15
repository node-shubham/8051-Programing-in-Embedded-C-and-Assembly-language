#include<reg51.h>
#include"uart.h"
main()
{
char ch;
uart_init();
while(1)
{
ch=uart_rxchar();
uart_txchar(ch);
}
}


