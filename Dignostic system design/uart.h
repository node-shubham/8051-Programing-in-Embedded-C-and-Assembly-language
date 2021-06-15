#ifndef _UART_H_
#define _UART_H_

void uart_init();
void uart_txchar(char ch);
void uart_txstr(char *);
char uart_rxchar();
void uart_txint(int n);
void uart_txfloat(float f);



#endif

