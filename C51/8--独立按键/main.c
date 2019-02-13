#include<reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

sbit led=P0^0;
sbit k1=P1^0;

void delay(u16 i)
{
	while(i--);
}

void keypros()
{
	if(k1==0)
	{
		delay(1000);
		if(k1==0)
		{
			led=~led;
		}
		while(!k1);
	}
}

void main()
{
	led=0;
	while(1)
	{
		keypros();
	}
}