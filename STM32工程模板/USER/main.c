//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//��������By��Brotherzhao@lab117-USTC
//////////////////////////////////////////////////////////////////////////////////	 
//ԭ���ߣ�����ԭ��@ALIENTEK
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////

#include "sys.h"
#include "stdio.h"
#include "delay.h"
#include "led.h"



//ʹ��keil_v5��������mian.c�����������
void assert_failed(uint8_t* file, uint32_t line)
{
 printf("Wrong parameters value: file %s on line %d\r\n", file, line);
 while(1);
}

int cycle=0;

//main����
 int main(void)
 {		
 	 //��ʼ��ϵͳ�����Լ���ʼ�������������
	 //�Լ�һЩֻ��Ҫ����һ�εĴ���
	 
	 
	 delay_init();//delay��ʼ��
	 LED_Init();//LED��ʼ��
	 
	 
	while(1){
	//�û�����
	//��Ҫ����ִ�еĶ����ȼ������еĴ���	
		
		LED1_ON();//����LED1
		LED2_OFF();//Ϩ��LED2
		delay_ms(500);
		LED1_OFF();//Ϩ��LED1
		LED2_ON();//����LED2
		delay_ms(500);
		cycle++;
		if(cycle==100)
		{
			cycle=0;
		}
	}
 }
 

