#include"spi.h"
#include"types.h"


u8 spi(u8 byte)
{
u8 i,buff=0;
for(i=0;i<8;i++)
{
clk=0;
mosi=(byte>>(7-i))&1;
clk=1;
if(miso)
buff |=0x80>>i;
}
return buff;
}
