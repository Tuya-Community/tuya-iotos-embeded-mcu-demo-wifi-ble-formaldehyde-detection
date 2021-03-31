#include "TIM.h"
#include "IO.h"
#include "USART.h"


void TIM3_Init(uint16_t arr,uint16_t psc)//VICE���ڳ�ʱ
{
	RCC->APBENR1 |= 1<<1;
	TIM3->ARR = arr;
	TIM3->PSC = psc;
	TIM3->DIER |= 1<<0;//ʹ�ܸ����ж�
	TIM3->CR1 |= 1<<0;//ʹ�ܼ�����
	NVIC_SetPriority(TIM3_IRQn, 1); 
	NVIC_EnableIRQ(TIM3_IRQn);
}
void TIM3_Start(void)
{
	TIM3->CR1 |=1<<0;//ʹ�ܼ�����
}
void TIM3_Stop(void)
{
	TIM3->CR1 &=~(1<<0);	//��ֹ������
	TIM3->CNT =0;//��������
}
void TIM3_Continue(void)
{
	TIM3->CR1 |=1<<0;//ʹ�ܼ�����
	TIM3->CNT =0;//��������
}
void TIM3_IRQHandler(void)
{
	if ((TIM3->SR & 1) == 1) /* Check ARR match */ 
	{	
		TIM3->SR &= ~(1<<0);//����жϱ�־λ
		TIM3_Stop();
		rear_inc(&Q_Side);
		F_TASK_USART_VICE++;		
	}
}

void TIM6_Init(uint16_t arr,uint16_t psc)//TASK����
{
	RCC->APBENR1 |= 1<<4;
	TIM6->ARR = arr;
	TIM6->PSC = psc;
	TIM6->DIER |= 1<<0;//ʹ�ܸ����ж�
	TIM6->CR1 |= 1<<0;//ʹ�ܼ�����
	NVIC_SetPriority(TIM6_DAC_LPTIM1_IRQn, 1); 
	NVIC_EnableIRQ(TIM6_DAC_LPTIM1_IRQn);
}
void TIM6_Start(void)
{
	TIM6->CR1 |=1<<0;//ʹ�ܼ�����
}
void TIM6_Stop(void)
{
	TIM6->CR1 &=~(1<<0);	//��ֹ������
	TIM6->CNT =0;//��������
}
uint8_t F_TASK_TIM6=0;
void TIM6_DAC_LPTIM1_IRQHandler(void)
{
	if ((TIM6->SR & 1) == 1) /* Check ARR match */ 
	{	
		TIM6->SR &= ~(1<<0);//����жϱ�־λ
		switch(mcu_get_wifi_work_state())
		{
			case SMART_CONFIG_STATE:
			case AP_STATE:LED_4_SET;break;
			case WIFI_NOT_CONNECTED:
			case WIFI_CONNECTED:LED_4_TOG;break;
			case WIFI_CONN_CLOUD:LED_4_RESET;break;
			case WIFI_LOW_POWER:		LED_4_RESET;break;
			case SMART_AND_AP_STATE:LED_4_RESET;break;
			default :LED_4_RESET;break;
		}
	}
}

void TIM_Init(void)
{	
	TIM3_Init(10,15999);//����10ms�ӽ��ܳ�ʱ
	TIM3_Stop();	
	TIM6_Init(1000,15999);
}

