#include"types.h"
#include"spi.h"
#include"mcp3204_defines.h"
#include"spi_defines.h"
#include"mcp3204.h"


FLT read1adc_mcp3204(u8 channelno)
{
int i;
u16 adcval=0;
bit d0,d1;
float temp;
d1=(channelno>>1)&1;
d0=channelno&&1;
cs=dout=din=clk=1;
cs=0;  // begin communication session
clk=0; clk=1;  // master issues start bit(1) & slave reads start bit
clk=0; clk=1; //  master issues single ended  bit(1) & slave reads that bit
clk=0; clk=1; //  master reads that bit, issues don't care  bit(d2) & slave reads that bit
din=d1;
clk=0; clk=1; //  master issues d1 channel select  bit & slave reads that bit
din=d0;
clk=0; clk=1; //  master issues d0 channel select  bit & slave reads that bit & initiates sampling 
clk=0; clk=1; // and continues and end sampling
clk=0; clk=1; // for s to issue NULL bit (0)

for(i=0;i<12;i++)
{
clk=0;
if(dout)
adcval|=(1<<(11-i));
clk=1;
}
cs=1; // end of communication session
temp=(adcval*(5.0/4096));
return temp;
}


/*FLT read2adc_mcp3204(u8 channelNo)
{
u8 mbyte,lbyte;
u16 adcvalue=0;
float temp;
_cs=dout=din=clk=1;
_cs=0;
spi(0x06);
mbyte=spi(channelNo<<6);
lbyte=spi(0x00);
00_cs=1;
adcvalue=((mbyte&0x0f)<<8)|lbyte;
temp=(adcvalue*(5/4096));
return temp;
}*/


