#include"glcd.h"


void main()
{
	glcd_init();
	glcd_clr(0);
	write_cmd(0xc0);
	glcd_char(0xb9,0x40,'1');
	delay(150);
	write_cmd(0xc5);
	glcd_str(0xbd,0x47,"vector");
	delay(150);

	while(1);
}
