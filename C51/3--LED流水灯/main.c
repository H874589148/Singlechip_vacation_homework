#include<reg52.h>
#include<intrins.h>

typedef unsigned char u8;
typedef unsigned int u16;

#define led P0

void delay(u16 i)
{
	while(i--);
}

void main()
{
	u8 i;
	led=0x01;
	delay(50000);
	while(1)
	{
		/*for(i=0;i<8;i++)
		{
			 led=(0x01<<i);
			 delay(50000); 
		}*/

		for(i=0;i<7;i++)
		{
			led=_crol_(led,1);
			delay(50000);
		}

		for(i=0;i<7;i++)
		{
			led=_cror_(led,1);
			delay(50000);
		}
	}
}