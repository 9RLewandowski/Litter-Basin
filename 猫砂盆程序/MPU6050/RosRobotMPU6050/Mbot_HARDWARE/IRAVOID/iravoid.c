#include "iravoid.h"



void IRAvoid_GPIO_Init ()
{
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;


	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = Iravoid_Pin;	
	/*设置引脚模式为上拉输入�*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*调用库函数，初始化Servo_J4_PORT*/
  	GPIO_Init(Iravoid_Port, &GPIO_InitStructure);		
}

void GetIRavoid(int *a)
{
	*a = GPIO_ReadInputDataBit(Iravoid_Port,Iravoid_Pin);
}
