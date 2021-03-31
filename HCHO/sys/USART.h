#ifndef __USART_H
#define __USART_H 		
#include "MY_ST_config.h"
#include "stdio.h"
#include "string.h"




typedef struct {
	uint8_t front;//����ָ��
	uint8_t rear;//��βָ��
	uint8_t size;//��������
}Queue;

void front_inc(Queue* SQ);
void rear_inc(Queue* SQ);



#define USART_MAIN  USART1
#define USART_MAIN_BOUND 115200
void Configure_USART_MAIN(uint32_t bound);//TX PC4, RX PC5 USART1



#define USART_VICE  USART2
#define USART_VICE_BUF_LEN 10
#define USART_VICE_BOUND 9600
struct quene_buf_type2
{
	uint8_t tab;
	uint16_t length;
	uint8_t data[USART_VICE_BUF_LEN];
};	
#define quene_side_buf_total 4
extern struct quene_buf_type2 q_side_buf[quene_side_buf_total];
extern Queue Q_Side;
extern uint8_t F_TASK_USART_VICE;
void Configure_USART_VICE(uint32_t bound);//TX PD8, RX PD9 USART3
void TASK_USART_VICE(void);

void Configure_USART_VICE(uint32_t bound);

#endif

