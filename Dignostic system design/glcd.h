#ifndef _GLCD_H_
#define _GLCD_H_

void glcd_init();
void write_cmd(unsigned char cmd);
void glcd_clr(unsigned char val);
void delay(unsigned int t);
void write_dat(unsigned char dat);

void glcd_str(unsigned char page, unsigned char hposi, unsigned char *ch);
void glcd_char(unsigned char page, unsigned char hposi, unsigned char ch);


#endif
