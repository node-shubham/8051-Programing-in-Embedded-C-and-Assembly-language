#ifndef _I2C_H_
#define _I2C_H_
#include"types.h"

/*proto types for i2c bus events*/
void i2cstart();
void i2cstop();
void i2cwrite(u8);
void i2cack();
void i2cnoack();
void i2cmasterack();
u8 i2cread();
void i2crestart();
void i2cdevwrite(u8,u8,u8); // random byte write
u8 i2cdevread(u8,u8);      // random byte read

/*void i2cdevpagewrite(u8,u8,u8 *,u8);
void i2cdevseqread(u8,u8,u8 *,u8);*/

//float readDS1621();

 


#endif
