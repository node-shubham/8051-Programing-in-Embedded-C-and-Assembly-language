#include<reg51.h>
#include<stdio.h>
#include "lcd.h"

#define MISO dout
#define MOSI din

typedef unsigned char u8;
typedef unsigned int u16;
		
sbit din  = P1^0;
sbit dout = P1^1;
sbit ss   = P1^2;
sbit sck  = P1^3;
		
float spi_devread(u16);
 
void main()
{   
	float spi_data;
	spi_data = spi_devread(1);		
	lcd_init();
	lcd_data(spi_data);
	while(1);	
}	  
float spi_devread(u16 channel)
{   
	float value;
	u8 i;
	u16 adc_val=0;
	bit d0,d1;
	d1 = (channel>>1)&1;
	d0 = channel&1;
	
	ss = sck = din = dout = 1; // master initialises all the bus  
	ss = 0; 					// step 2 master begins comm. session
	sck = 0; sck = 1;	// 1st clock signal to send start bit
	sck = 0; sck = 1;	// 2nd clock signal to send single ended mode bit
	sck = 0; sck = 1;	// 3rd clock signal to send don't care bit
	din = d1; 				// channel selection bit d1
	sck = 0; sck = 1;	// 4th clock signal to send channel selection bit
	din = d0; 				// channel selection bit d0
	sck = 0; sck = 1;	// 5st clock signal to send channel selectio bit
	sck = 0; sck = 1;	// 6th clock signal to continue and end sampling
	sck = 0; sck = 1;	// 7th clock signal to send null bit indicating 
										// that digital data can be read onwards 
	for(i=11;i>=0;i--)
	{
		sck = 0;
		if(dout)
			adc_val = (adc_val |(1<<i));
		sck = 1;				// 12 clock signal to fetch data		
	}	
	ss = 1; 					// end communication session	
	value = adc_val*(5.0/4096);
	return value;
}	  
	  