#include"i2c.h"
#include"i2c_defines.h"
#include"delay.h"

void i2cstart()
{
sda=1;
scl=1;
sda=0;
}

void i2cwrite(u8 dat)
{
u8 i;
for(i=0;i<8;i++)
{
scl=0;
sda=(dat>>(7-i))&1;
scl=1;
}
}

u8 i2cread()
{
u8 i,buff=0;
for(i=0;i<8;i++)
{
scl=0;
scl=1;
if(sda)
buff|=0x80>>i;
}
return buff;
}

void i2cack()
{
scl=0;
sda=1;
scl=1;
while(sda);
}

void i2cnoack()
{
scl=0;
sda=1;
scl=1;
}

/*void i2cmasterack()
{
scl=0; //slave can release sda=1
sda=0; //master pull down sda
scl=1; //for slave to validate sda is 0
scl=0; //master to release sda
sda=1; //sda=1 by master 
}*/

void i2crestart()
{
scl=0;
sda=1;
scl=1;
sda=0;
}

void i2cdevwrite(u8 slaveaddr,u8 buffaddr,u8 dat)
{
i2cstart();
i2cwrite(slaveaddr);
i2cack();
i2cwrite(buffaddr);
i2cack();
i2cwrite(dat);
i2cack();
i2cstop();
delay_ms(10);
}

void i2cstop()
{
scl=0;
sda=0;
scl=1;
sda=1;
}

u8 i2cdevread(u8 slaveaddr,u8 buffaddr)
{
u8 buff;
i2cstart();
i2cwrite(slaveaddr);
i2cack();
i2cwrite(buffaddr);
i2cack();
i2crestart();
i2cwrite(slaveaddr|1);
i2cack();
buff=i2cread();
i2cnoack();
i2cstop();
return buff;
}


