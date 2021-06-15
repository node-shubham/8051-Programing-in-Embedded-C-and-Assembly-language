#include"i2c.h"
#include"types.h"
#include<string.h>
#include<reg51.h>

//sbit led=P3^5;

#include"delay.h"

#include"lcd1.h"

main()
{

u8 s1[6]="hello",s2[6]=" ",i;
LCD_init();

for(i=0;i<5;i++)
i2cdevwrite(0xa0,i,s1[i]);
LCD_cmd(0x80);
for(i=0;i<5;i++)
s2[i]=i2cdevread(0xa0,i);
delay_ms(2000);
while(1)
{
LCD_cmd(0x80);
LCD_str(s2);
/*if(strcmp(s1,s2)==0)
led=~led;*/
}
}

