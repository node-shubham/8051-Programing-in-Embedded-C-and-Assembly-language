#include<reg51.h>
#include<intrins.h>
#include<serial.h>
//#include<lcd1.h>
bit ack;
sbit sda=P2^0;
sbit scl=P2^1;
void start()
{
	sda=1;
	scl=1;
	_nop_();
	_nop_();
	sda=0;
	scl=0;
}
void stop()
{
	sda=0;
	scl=1;
	_nop_();
	_nop_();
	sda=1;
	scl=0;
}
void acknowledge()
{
	scl=1;
	_nop_();
	_nop_();
	scl=0;
}
void send_byte(unsigned char value)
{
	unsigned int i;
	unsigned char send;
	send=value;
	for(i=0;i<8;i++)
	{
		sda=send/128;
		send=send<<1;
		scl=1;
		_nop_();
		_nop_();
		scl=0;
	}
	ack=sda;
	sda=0;
}
unsigned char read_byte()
{
	unsigned int i;
	unsigned char reead=0; sda=1;
	for(i=0;i<8;i++)
	{
		reead=reead<<1;
		scl=1;
		_nop_();
		_nop_();
		if(sda==1)
			reead++;
		scl=0;
	}
	sda=0;
	return reead;
}
void save(char *s)
{	 int i;
	start();
	send_byte(0xA0);
	acknowledge();
	send_byte(0x00);
	acknowledge();
	for(i=0;s[i]!='\0';i++)
	{
		send_byte(s[i]);
		acknowledge();
	 }
	 stop();
	 acknowledge();
}
void Read()
{
	int i;
	char c;
	//LCDCommand(0xc0);
	start();
	send_byte(0xA0);
	acknowledge();
	send_byte(0x00);
	acknowledge();
	start();
	send_byte(0xA1);
	acknowledge();
	for(i=0;i<20;i++)
	{
		c=read_byte();
		//LCDData(c);
		tx(c);
		acknowledge();
		if(c=='*')break;
	}
	stop();
	acknowledge();
}

void xputs(char *s)
{
	int i;
		for(i=0;s[i]!='\0';i++)tx(s[i]);
	}
void main()
{
	int temp;
	char c;
	char buffer[60];
	int i;
	//LCDInit();
	init();
	temp=0;
	while(1)
	{
		tx(10);tx(13);
		xputs("Select the option");
		tx(10);tx(13);
		xputs("1)Save data");
		tx(10);tx(13);
		xputs("2)Read data");
		tx(10);tx(13);
		xputs("3)Exit");
		tx(10);tx(13);
	 //}
	 c=rx();
	 if(c=='1')
	 {
	 	xputs("Enter the data [* to Stop]");
		for(i=0;i<20;i++)
		{
			temp++;
				if(temp>16)
				{
					tx(10);tx(13);
					temp=0;
				
			c=rx();
			tx(c);
			buffer[i]=c;
			if(c=='*')
			{
			
				buffer[++i]=0;
				break;
			}
		}
		save(buffer);
	}
	 }
	 if(c=='2')Read();
	 if(c=='3')break;
} }