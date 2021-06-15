#include"mcp3204.h"
#include"lcd1.h"
#include<stdio.h>
#include"delay.h"

main()
{
float adcvalF;
char temp[10];
LCD_init();
while(1)
{
adcvalF=read1adc_mcp3204(0);  //adcvalF*=100.0; // for calibration of LM325
sprintf(temp,"%f",adcvalF);
delay_ms(100);
//LCD_cmd(0x01);
LCD_cmd(0x80);
LCD_str(temp);
}
}
