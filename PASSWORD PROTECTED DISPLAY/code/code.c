#include<reg51.h>

sbit C4 = P2^0;     // Connecting keypad to Port 1
sbit C3 = P2^1;
sbit C2 = P2^2;
sbit C1 = P2^3;
sbit R4 = P2^4;
sbit R3 = P2^5;
sbit R2 = P2^6;
sbit R1 = P2^7;
void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}

char row_finder1() //Function for finding the row for column 1
{
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;

if(R1==0)return('1');
if(R2==0)return('4');
if(R3==0)return('7');
if(R4==0)return('*');
}
char row_finder2() //Function for finding the row for column 2
{

R1=R2=R3=R4=1;
C1=C2=C3=C4=0;
if(R1==0)return('2');
if(R2==0)return('5');
if(R3==0)return('8');
if(R4==0)return('0');
}
char row_finder3() //Function for finding the row for column 3
{
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;
if(R1==0)return('3');
if(R2==0)return('6');
if(R3==0)return('9');
if(R4==0)return('#');
}
char row_finder4() //Function for finding the row for column 4
{
R1=R2=R3=R4=1;
C1=C2=C3=C4=0;
if(R1==0)return('A');
if(R2==0)return('B');
if(R3==0)return('C');
if(R4==0)return('D');
}
 void init()
   {
     TMOD=0x20;
	 SCON=0x50;
	 TH1=0xfd;
	 TR1=1;
   }
  void tx(char c)
   {
      SBUF=c;
	  while(TI==0);
	  TI=0;
   }
void main()
{
    char c;

    init();
	while(1)
    {    
        msdelay(30); 
       
	    P2=0x0f;
		while(P2==0x0f);
        if(C1==0)      c=row_finder1();
        else if(C2==0) c=row_finder2();
        else if(C3==0) c=row_finder3();
        else if(C4==0) c=row_finder4();
		tx(c);
    }
}