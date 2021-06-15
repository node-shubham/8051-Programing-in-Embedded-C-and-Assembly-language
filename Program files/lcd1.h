//lcd.h
#ifndef _LCD_H
#define _LCD_H

void LCD_init();
void LCD_cmd(char);
void LCD_char(char);
void LCD_str(char *);
//extern void store_CGRAM();
//void LCD_int(int);

//extern void uart_init();
//extern char uart_rxchar();
//extern void uart_str(char *); 
#endif
