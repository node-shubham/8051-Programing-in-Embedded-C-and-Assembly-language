#include<reg52.h>  // not working properly
#include "delay_ms.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit scl = P3^6;	// tx  
sbit sda = P3^7;	// rx

sbit led = P3^5; // led connected

void i2c_start(void);
void i2c_stop(void);
void i2c_restart(void); 
void i2c_write(u8);
u8 i2c_read(void);
void i2c_ack(void);
void i2c_noack(void);
//void i2c_masterack(void);

void i2c_devwrite(u8, u8, u8);
u8 i2c_devread(u8, u8);
void main()
{
	u8 temp;
	i2c_devwrite(0xa0,0x00,'#');
	temp = i2c_devread(0xa0,0x00);
	delay_ms(2000);
	while(temp=='#')
	{
		led = ~led;
		delay_ms(700);
	}
}
void i2c_start(void)  // scl: always high; sda : transition
{
	sda = 1; 
	scl = 1;
	sda = 0;
}
void i2c_stop(void)
{
	scl = 0;    // slave making it low
	sda = 0;	
	scl = 1;
	sda = 1; 
}	
void i2c_restart(void)
{
	scl = 0;
	sda = 1;
	scl = 1;
	sda = 0;
}

void i2c_write(u8 val)
{
	u8 i;
	scl = 0;
	for(i=7;i>=0;i++)
	{
		sda = (val>>i)&1;
	}	
	scl = 1;
}
u8 i2c_read(void)
{
	u8 i,buff=0;
	scl = 1;
	for(i=7;i>=0;i++)
	{
		if(sda)
			buff |= 0x80>>i ;
	}
	return buff;	
}
void i2c_ack(void)
{
	scl = 0;
	sda = 1;
	scl = 1;
	while(sda);
}	

void i2c_noack(void)
{
	scl = 0;
	sda = 1;
	scl = 1;
}	
//void i2c_masterack(void){}
	
void i2c_devwrite(u8 slaveaddr,u8 buffaddr,u8 val)
{
	i2c_start();
	i2c_write(slaveaddr);
	i2c_ack();
	i2c_write(buffaddr);
	i2c_ack();
	i2c_write(val);
	i2c_ack();
	i2c_stop();
}
u8 i2c_devread(u8 slaveaddr, u8 buffaddr)
{
	u8 buff;
	i2c_start();
	i2c_ack();
	i2c_write(slaveaddr);
	i2c_ack();
	i2c_write(buffaddr);
	i2c_ack();
	i2c_restart();
	i2c_write(slaveaddr|1);
	i2c_ack();
	buff = i2c_read();
	i2c_noack();
	i2c_stop();
	return buff;
}	