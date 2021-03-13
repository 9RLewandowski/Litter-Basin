#include "sys.h"

//====================�Լ������ͷ�ļ�===============================
#include "delay.h"
#include "led.h"
#include "usart3.h"

#include "ioi2c.h"
#include "mpu6050.h"

#include "iravoid.h"

#include "motor.h"
#include "pwm.h"

#include "control.h"
#include "myexti.h"
#include <stdio.h>
//===================================================================

/*===================================================================
�����ܣ�MPU6050 DMP���ݶ�ȡ
�����д�����ںţ�С��ѧ�ƶ�������
����    ������Դ������κ����ʣ�����˽��С�࣬һ����ظ��ġ�
=====================================================================
------------------��ע���ںţ���ø�����Ȥ�ķ���---------------------
===================================================================*/

int main(void)
{ 

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//����JTAG ���� SWD
	
	MY_NVIC_PriorityGroupConfig(2);	//=====�����жϷ���
	
	delay_init();	    	        //=====��ʱ������ʼ��
	LED_Init();                     //=====LED��ʼ��    �����
	usart3_init(9600);              //=====����3��ʼ��  ����

  IIC_Init();                     //=====IIC��ʼ��    ��ȡMPU6050����
	MPU6050_initialize();           //=====MPU6050��ʼ��	
	DMP_Init();                     //=====��ʼ��DMP 
	
	MBOT_EXTI_Init();               //=====MPU6050 5ms��ʱ�жϳ�ʼ��
	IRAvoid_GPIO_Init();
	Motor_Init(7199,0);             //=====��ʼ��PWM 10KHZ������������� �����ʼ���������ӿ�


	while(1)
	{
		int a = 0;
		GetIRavoid(&a);
		if(a == 0)                  //�����⵽è
		{
			printf("cat is in");
			while(1)                  //һֱ�ȴ���ֱ��è�뿪
			{
				GetIRavoid(&a);
				if(a == 1)
				{
					break;
				}
			}
			
			while(1)
		{
			getAngle(&yaw,&yaw_acc_error);      //��ȡ�Ƕ�
			Set_Pwm(1000,1000);
			printf("%d\r\n",(int)yaw);
			if((int)yaw==3)                     //ת��Ԥ��ǶȺ�ֹͣ
			{
				Set_Pwm(0,0);
				break;
			}
		}
	  }
		__set_FAULTMASK(1);
		NVIC_SystemReset();
		
	} 
}


