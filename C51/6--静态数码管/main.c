#include<reg52.h>
#include<intrins.h>

typedef unsigned char u8;
typedef unsigned int u16;

u8 code smgduan[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,
			  0x7c,0x39,0x5e,0x79,0x71};	   //π≤“ı

void delay(u16 i)
{
	while(i--);
}

void main()
{
	int i;
	while(1)
	{
		for(i=0;i<=15;i++){
			P0=~smgduan[i];	
			delay(250000);
		}
	}
}