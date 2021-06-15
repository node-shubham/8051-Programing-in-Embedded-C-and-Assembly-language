#include<reg51.h>


#include"uart.h"             // uart declarations


sbit sw=P1^0;
sbit led=P1^1;

sbit sw1=P3^7;

#include"lcd1.h"

#include"types.h"           // typedef for existing datatypes
#include"i2c.h"            //  i2c declarations
#include"i2c_defines.h"   // i2c defines for scl,sda
#include"delay.h"        //  delay declaration


#include"mcp3204.h"            // mcp3204 declarations
#include"mcp3204_defines.h"    // mcp3204 definitions 


#include"spi.h"            // spi declarations
#include"spi_defines.h"   //  spi definitions


#include"glcd.h"         // glcd declarations

//#include<stdio.h>

char check(char ,u8 );

main()
{
u8 s1[6]="hello",s2[6]=" ",i;
float adcvalF;
u16 cnt;
char ch;       
uart_init();
LCD_init();
while(1)
{
uart_txstr("***menu***\r\n");
uart_txstr("1.SWITCH\r\n");
uart_txstr("2.LCD\r\n");
uart_txstr("3.EEPROM\r\n");
uart_txstr("4.SPI\r\n");
uart_txstr("5.GLCD\r\n");
ch=uart_rxchar();
switch(ch)
{
case '1': cnt=4000;
          while(--cnt)
          {
		  if(sw==0)break;
          delay_ms(1);
		  }
		  uart_txstr("connect SW to P1.0\r\n");
		  uart_txstr("press now\r\n");    		   
          if(sw==0)
          {
		  uart_txstr("switch is working properly\r\n");
		  }
          else
	      {
		  uart_txstr("may be SW is not connected to P1.0\r\n");
		  uart_txstr("may be You have used active high switch instead of active low switch\r\n");
	      }
		  break;

case '2': LCD_init();
		  LCD_cmd(0x80);
 	      LCD_str("TEST OK ");
		  //LCD_char('A');
		  LCD_cmd(0xc0);
		  LCD_str("ALLpixelsworking");
		  //LCD_char('B');
		  uart_txstr("connect LCD to P0\r\n");
		  uart_txstr("connect RS,RS,EN to P3.4,P3.5,P3.6 \r\n");
		  uart_txstr("connect LCD/GLCD button to LCD mode\r\n"); 
		  uart_txstr("P3.0,P3.1 pin switches pull to ON side\r\n");   
	      uart_txstr("check whether lcd is working or not\r\n");
		  uart_txstr("press y:yes n:no\r\n");
	      while(check(uart_rxchar(),7));          
 	      break;
	   
case '3': for(i=0;s1[i];i++)
          i2cdevwrite(0xa0,i,s1[i]);
          for(i=0;s1[i];i++)
          s2[i]=i2cdevread(0xa0,i);
          delay_ms(2000);
          LCD_init();
          LCD_cmd(0x84);
          LCD_str(s2);
		  uart_txstr("connect SCL,SDA to P3.2,P3.3\r\n");
		  uart_txstr("check whether lcd is connected to P0\r\n");
		  uart_txstr("check whether EEPROM is working or not\r\n");
		  uart_txstr("press y:yes n:no\r\n");
		  while(check(uart_rxchar(),8));          
	     	                 
 	      break;

case '4': adcvalF=read1adc_mcp3204(0);  
   		  uart_txfloat(adcvalF);
          delay_ms(100);
		  uart_txstr("connect CS,MOSI(DIN),MISO(DOUT),CLK to P2.4,P2.5,P2.6,P2.7\r\n");
    	  uart_txstr("check the ADC values by connecting one end of pin to any of the channels and other end u have to connect either VDD or GND\r\n"); 
		  uart_txstr("check whether MCP3204 is working or not\r\n");
          uart_txstr("press y:yes n:no\r\n");
		  while(check(uart_rxchar(),9));          
      	                 
 	      break;
case '5': glcd_init();
	      glcd_clr(0);
	      write_cmd(0xc0);
	      glcd_char(0xb8,0x40,'1');
	      delay(150);
	      write_cmd(0xc5);
	      glcd_str(0xbd,0x47,"vector");
	      delay(150);
		  uart_txstr("connect LCD/GLCD button to GLCD mode\r\n"); 
		  uart_txstr("connect GLCD to P0");
		  uart_txstr("connect RS(D/I),RW,EN to P3.4,P3.5,P3.6\r\n");
		  uart_txstr("connect RS,CS1,CS2 to P1.2,P1.3,P1.4\r\n");
		  uart_txstr("check whether GLCD is working or not\r\n");
	      uart_txstr("press y:yes n:no\r\n");
		  while(check(uart_rxchar(),10));          
  
 	      break;
		  
default:  uart_txstr("you have entered inavlid choice\r\n");
}
}
} 

char check(char ch,u8 ty)
{
if(ch!='y'&&ch!='n')
return 1;
if(ch=='n')
{
uart_txstr("error possibilities are:\r\n");
{
 if(ty==7)    // LCD error possibilities
 {
 uart_txstr("there may be lose connection\r\n"); 
 uart_txstr("may be GLCD/LCD button not connected to LCD mode\r\n");
 uart_txstr("may be RS,RW EN  are not connected to P3.4,P3.5,P3.6 or not\r\n");
 uart_txstr("may be LCD datapins(D0....D7) are not connected to P0 or not\r\n");
 }
 else if(ty==8) // EEPROM(DS1621) error possibilities
 {
 uart_txstr("there may be lose connection\r\n"); 
 uart_txstr("may be SCL,SDA are connected  to P3.2,P3.3\r\n");
 uart_txstr("may be EEPROM(DS1621) is not working\r\n");
 }
 else if(ty==9) // MCP3201 error possibilities
 {
 uart_txstr("there may be lose connection\r\n"); 
 uart_txstr("may be  CS is not connected  to P2.4\r\n");
 uart_txstr("may be MOSI(DIN),MISO(DOUT),CLK are not connected  to P2^5,P2.6,P2.7\r\n");
 }
 else if(ty==10)
 {
 uart_txstr("there may be lose connection\r\n"); 
 uart_txstr("may be GLCD/LCD button not connected to GLCD mode\r\n");
 uart_txstr("may be  GLCD,RS(D/I),RW(R/W),EN,RS,CS2,CS1 are not connected to P0,P3.4,P.5,P3.6,P1.2,P1.3,P1.4\r\n");
 }
 else {}
}
} 
return 0;

}
        
