#include<reg52.h>
#include<intrins.h>

typedef unsigned char u8;
typedef unsigned int u16;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 a=2,b=2,c=2,d=6,e=0,f=3,g=0,h=0;

u8 code smgduan[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,
			  0x7c,0x39,0x5e,0x79,0x71};	   //共阴

void delay(u16 i)
{
	while(i--);
}

void delay100us(void)                       //误差 0us	   延时1毫秒
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=47;a>0;a--);
}

void DigDisplay(u8 i,u8 j)					//增强可读性
{
	switch(i)
		{
			case 0:
				LSA=0;LSB=0;LSC=0;break;
			case 1:
				LSA=1;LSB=0;LSC=0;break;
			case 2:
				LSA=0;LSB=1;LSC=0;break;
			case 3:
				LSA=1;LSB=1;LSC=0;break;
			case 4:
				LSA=0;LSB=0;LSC=1;break;
			case 5:
				LSA=1;LSB=0;LSC=1;break;
			case 6:
				LSA=0;LSB=1;LSC=1;break;
			case 7:
				LSA=1;LSB=1;LSC=1;break;
		}
		P0=smgduan[j];	       //在第i位显示j
		delay(100);			   //时间太短会乱、错
		P0=0x00;
}

void Print(u8 a,u8 b,u8 c,u8 d,u8 e,u8 f,u8 g,u8 h)
{
	DigDisplay(0,a);
	DigDisplay(1,b);
	DigDisplay(2,c);
	DigDisplay(3,d);
	DigDisplay(4,e);
	DigDisplay(5,f);
	DigDisplay(6,g);
	DigDisplay(7,h);
}

void main()
{
	while(1)
	{
		for(;h++;h<10)
		{
			delay100us();
			delay100us();
			if(h==9) {g++;h=0;}
			if(g==9) {f++;g=0;}
			if(f==9) {e++;f=0;}
			if(e==6) {d++;e=0;}
			if(d==9) {c++;d=0;}
			if(c==6) {b++;c=0;}
			if(b==9) {a++;b=0;}
		Print(a,b,c,d,e,f,g,h);	
		}
//		Print(a,b,c,d,e,f,g,h);
	} 
}