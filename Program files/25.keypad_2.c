#include<reg52.h>
#include "delay_ms.h"

sbit C1 = P2^0;
sbit C2 = P2^1;
sbit C3 = P2^2;
sbit C4 = P2^3;
sbit R1 = P2^4;
sbit R2 = P2^5;
sbit R3 = P2^6;
sbit R4 = P2^7;

void main()
{
		int row=0,col=0;
		while(1)
		{	
				P2 = 0X0F; 	 // P2.7-P2.4=0 ; P2.3-P2.0=1 
				while(C1&C2&C3&C4); // WAIT TILL PRESS
				if(P1==0X0E) // OR C1=0
					col=1;
				if(P1==0X0D) // OR C2=0
					col=2;
				if(P1==0X0B) // OR C3=0
					col=3;
				if(P1==0X07) // OR C4=0
					col=4;
				delay_ms(10);
				
				P2 = 0XF0;
				if(P1==0XE0) // OR R1=0
					row=1;
				if(P1==0XD0) // OR R2=0
					row=2;
				if(P1==0XB0) // OR R3=0
					row=3;
				if(P1==0X70) // OR R4=0
					row=4;
				delay_ms(10);
				while(R1&R2&R3&R4); // WAIT TILL RELEASE
			}
}		