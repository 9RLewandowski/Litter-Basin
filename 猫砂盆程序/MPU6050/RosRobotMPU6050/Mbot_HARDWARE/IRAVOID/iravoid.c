#include "iravoid.h"



void IRAvoid_GPIO_Init ()
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;


	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = Iravoid_Pin;	
	/*��������ģʽΪ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��Servo_J4_PORT*/
  	GPIO_Init(Iravoid_Port, &GPIO_InitStructure);		
}

void GetIRavoid(int *a)
{
	*a = GPIO_ReadInputDataBit(Iravoid_Port,Iravoid_Pin);
}
