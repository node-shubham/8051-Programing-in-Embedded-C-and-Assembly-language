#include<reg52.h>
#include "delay_ms.h"
#define RLED P3
#define CLED P1
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
	int row=0, col=0;
	C1= C2= C3= C4= 1; 
	R1= R2= R3= R4= 0;
	while(C1&C2&C3&C4); //checking switch is pressed or not.
	while(1)
	{
			if(C1==0)
				col=1;
			else if(C2==0)
				col=2;
			else if(C3==0)
				col=3;
			else
				col=4;
			
			R1= R2= R3= R4= 1;
			C1= C2= C3= C4= 0;
			
			if(R1==0)
				{row=1;break;}
			else if(R2==0)
				{row=2;break;}
			else if(R3==0)
				{row=3;break;}
			else
				row=4;
			
			while(!(R1&R2&R3&R4)); // WAIT FOR RELEASE
			RLED=row;
			CLED=col;
			delay_ms(100);
	}	
}