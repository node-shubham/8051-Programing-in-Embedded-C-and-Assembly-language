#include<reg51.h>
#define LCDPort P1 //PORT 1 connected to 7-14 OF LCD
sbit RS=P0^0; //pin 39 0f 8051
sbit RW=P0^1; //pin 38 0f 8051
sbit EN=P0^2; //pin 37 0f 8051


void delay(int t)
{
 		int i;
		while(t>0)
		{
			i=1275;
			while(i >0) i--;
			t--;
		}
}
// this func will send a command to lcd
void LCDCommand(char c)
{
	RS=0; //RS=0 means we are sending command
	RW=0;//RW=0 MEANS , WE ARE USING LCD in write mode
   LCDPort=c; // copy value of c (command ) into lcd
   EN=1;//SET EN pin high				  .....
   delay(2); // wait for 2ms			   ...	 generate high to low pulse
   EN=0; // reset EN pin to low			   ......
}

void LCDdata(char c)
{
	RS=1; //RS=1 means we are sending command
	RW=0;//RW=0 MEANS , WE ARE USING LCD in write mode
   LCDPort=c; // copy value of c (command ) into lcd
   EN=1;//SET EN pin high				  .....
   delay(2); // wait for 2ms			   ...	 generate high to low pulse
   EN=0; // reset EN pin to low			   ......

}
void LCDInit()
{
	LCDCommand(0x38);// 8 bit mode
	LCDCommand(0x06);//display from left
	LCDCommand(0x0c);// display on ,cursor
   	LCDCommand(0x01);  // clear lcd
}

void LCDputs(char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		LCDdata(s[i]);
	}
}
void LCDSetCursor(int col, int Li)
{
	if(Li==0) LCDCommand(0x80+col);
	if(Li==1) LCDCommand(0xc0+col);
}