#include<reg52.h>
#include<intrins.h>

typedef unsigned char u8;
typedef unsigned int u16;

//#define GPIO_DIG P0
#define GPIO_KEY P1

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 code smgduan[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,
			  0x7c,0x39,0x5e,0x79,0x71};	   //共阴

void delay(u16 i)
{
	while(i--);
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
	P0=smgduan[j];	               //在第i位上显示j
	delay(100);			           //时间太短会乱、错
	P0=0x00;
}

u8 KeyDown()
{
	u8 KeyValue;
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)
	{
		delay(1000);
		if(GPIO_KEY!=0x0f)
		{
			switch(GPIO_KEY)
			{
				case(0x07): KeyValue=0;break;
				case(0x0b):	KeyValue=1;break;
				case(0x0d):	KeyValue=2;break;
				case(0x0e):	KeyValue=3;break;
			}
			
			GPIO_KEY=0xf0;
			switch(GPIO_KEY)
			{
				case(0x70): KeyValue=KeyValue;break;
				case(0xb0):	KeyValue=KeyValue+4;break;
				case(0xd0):	KeyValue=KeyValue+8;break;
				case(0xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<50)&&(GPIO_KEY!=0xf0))
			{
				delay(1000);
				a++;
			}
		}
	}
	return KeyValue;
}
 
void main()
{
	u8 Key,i,j,k,l,m,n;
	while(1)
	{
		P0=0x00;
		Key=KeyDown();
		if(Key=0) {i=7;DigDisplay(7,i);}
		if(Key=1) {i=8;DigDisplay(7,i);}
		if(Key=2) {i=9;DigDisplay(7,i);}
		if(Key=4) {i=4;DigDisplay(7,i);}
		if(Key=5) {i=5;DigDisplay(7,i);}
		if(Key=6) {i=6;DigDisplay(7,i);}
		if(Key=8) {i=1;DigDisplay(7,i);}
		if(Key=9) {i=2;DigDisplay(7,i);}
		if(Key=10) {i=3;DigDisplay(7,i);}
		Key=KeyDown();
		if(Key=0) {j=7;DigDisplay(8,i);}
		if(Key=1) {j=8;DigDisplay(8,i);}
		if(Key=2) {j=9;DigDisplay(8,i);}
		if(Key=4) {j=4;DigDisplay(8,i);}
		if(Key=5) {j=5;DigDisplay(8,i);}
		if(Key=6) {j=6;DigDisplay(8,i);}
		if(Key=8) {j=1;DigDisplay(8,i);}
		if(Key=9) {j=2;DigDisplay(8,i);}
		if(Key=10) {j=3;DigDisplay(8,i);}
		k=KeyDown();
		Key=KeyDown();
		if(Key=0) {l=7;DigDisplay(7,l);}
		if(Key=1) {l=8;DigDisplay(7,l);}
		if(Key=2) {l=9;DigDisplay(7,l);}
		if(Key=4) {l=4;DigDisplay(7,l);}
		if(Key=5) {l=5;DigDisplay(7,l);}
		if(Key=6) {l=6;DigDisplay(7,l);}
		if(Key=8) {l=1;DigDisplay(7,l);}
		if(Key=9) {l=2;DigDisplay(7,l);}
		if(Key=10) {l=3;DigDisplay(7,l);}
		Key=KeyDown();
		if(Key=0) {m=7;DigDisplay(8,m);}
		if(Key=1) {m=8;DigDisplay(8,m);}
		if(Key=2) {m=9;DigDisplay(8,m);}
		if(Key=4) {m=4;DigDisplay(8,m);}
		if(Key=5) {m=5;DigDisplay(8,m);}
		if(Key=6) {m=6;DigDisplay(8,m);}
		if(Key=8) {m=1;DigDisplay(8,m);}
		if(Key=9) {m=2;DigDisplay(8,m);}
		if(Key=10) {m=3;DigDisplay(8,m);}
		if(k=4)	n=(10*i+j)/(10*l+m);
		if(k=4)	n=(10*i+j)*(10*l+m);
		if(k=4)	n=(10*i+j)-(10*l+m);
		if(k=4)	n=(10*i+j)+(10*l+m);
		i=n/1000;j=(n-1000*i)/100;k=(n-1000*i-100*j)/10;l=n-1000*i-100*j-10*k;
		Key=KeyDown();
		if(Key==14)
		{
		DigDisplay(5,i);
		DigDisplay(6,j);
	    DigDisplay(7,k);
		DigDisplay(8,l);
		}
	}
}