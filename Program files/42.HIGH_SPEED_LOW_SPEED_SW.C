#include<reg52.h>

sbit sw= P1^7;
char *p1,*p2 = "Normal Speed: 28.8k\n";
char *q1,*q2 = "High Speed: 57.6k\n";

main()
{
	TMOD = 0X20;
	TH1  = 0XFE;		// default: high speed
	SCON = 0X50;
	PCON = 0X80;
	TR1=1;		//TIMER RUNNING
	while(1)
	{
		if(sw==0)
		{
			q1=q2;
			TH1 =0XFE;	//   normal speed
			while(*p1!='\0')
			{
				SBUF = *p1;
				while(TI==0);
						TI=0;
				p1++;
			}
		}	
		if(sw==1)
		{
			p1=p2;
			TH1 =0XFF;
			while(*q1!='\0')
			{
				SBUF = *q1;
				while(TI==0);
						TI=0;
				q1++;
			}
		}	
	}
}