/**
*	@file		demo_5.c
*	@brief		循环队列
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_5.h"

typedef enum e_uart_ch				/* 串口列表 */
{
	UART0 = 0,
	UART1 = 1,
	UART_NUM
} uart_ch_t;

typedef struct st_uart_ctrl			/* 串口控制块 */
{
	queue_A_hdl_t rx_queue;
	queue_B_hdl_t tx_queue;
} uart_ctrl_t;
typedef struct st_uart_ctrl * uart_hdl_t;

static uart_ctrl_t   uart0 = { NULL, NULL };
static uart_ctrl_t   uart1 = { NULL, NULL };
const static uart_hdl_t g_handles[UART_NUM] =
{
	&uart0,
	NULL
};

static unsigned char uart0_rx_buf[QUEUE_CFG_BUFF_SIZE];
static unsigned char uart0_tx_buf[QUEUE_CFG_BUFF_SIZE];
static queue_ctrl_A_t g_qcb_A[QUEUE_CFG_MAX_CTRL_BLKS];
static queue_ctrl_B_t g_qcb_B[QUEUE_CFG_MAX_CTRL_BLKS];

void demo_5(void)
{
	printf(DEMO_5);

	unsigned char m[4] = { 0x55, 0xAA, 0x00, 0x00 };
	printf("双指针队列A测试 \n");
	queue_err_t q_err = QUEUE_ERR_INVALID_ARG;
	q_err = queue_init_A(uart0_rx_buf, QUEUE_CFG_BUFF_SIZE, &g_handles[UART0]->rx_queue);

	in_queue_A(g_handles[UART0]->rx_queue, m[0]);
	in_queue_A(g_handles[UART0]->rx_queue, m[1]);
	printf("顺序入队数据：m[0] = %02X，m[1] = %02X \n", m[0], m[1]);

	out_queue_A(g_handles[UART0]->rx_queue, &m[2]);
	out_queue_A(g_handles[UART0]->rx_queue, &m[3]);
	printf("顺序出队数据：m[2] = %02X，m[3] = %02X \n", m[2], m[3]);

	printf("\n双指针队列B测试 \n");
	m[0] = 0xAA; m[1] = 0x55;
	q_err = queue_init_B(uart0_tx_buf, QUEUE_CFG_BUFF_SIZE, &g_handles[UART0]->tx_queue);

	in_queue_B(g_handles[UART0]->tx_queue, m[0]);
	in_queue_B(g_handles[UART0]->tx_queue, m[1]);
	printf("顺序入队数据：m[0] = %02X，m[1] = %02X \n", m[0], m[1]);
	
	out_queue_B(g_handles[UART0]->tx_queue, &m[2]);
	out_queue_B(g_handles[UART0]->tx_queue, &m[3]);
	printf("顺序出队数据：m[2] = %02X，m[3] = %02X \n", m[2], m[3]);
}


queue_err_t queue_init_A(unsigned char * const p_buf, unsigned int const size, queue_A_hdl_t * const p_hdl)
{
	queue_ctrl_A_t *p_qcb = 0;

	if (NULL == p_hdl)
	{
		return QUEUE_ERR_INVALID_ARG;
	}
	if (NULL == p_buf)
	{
		return QUEUE_ERR_NULL_PTR;
	}
	if (size < 2)
	{
		return QUEUE_ERR_INVALID_ARG;
	}

	p_qcb = &g_qcb_A[0];

	p_qcb->buffer = p_buf;
	p_qcb->size = size;
	p_qcb->count = 0;
	p_qcb->in_index = 0;
	p_qcb->out_index = 0;

	*p_hdl = p_qcb;
	return QUEUE_SUCCESS;
}


queue_err_t in_queue_A(queue_A_hdl_t const hdl, unsigned char const byte)
{
	if (NULL == hdl)
	{
		return QUEUE_ERR_NULL_PTR;
	}

	if (hdl->count >= hdl->size)
	{
		return QUEUE_ERR_QUEUE_FULL;
	}

	hdl->buffer[hdl->in_index++] = byte;
	if (hdl->in_index >= hdl->size)
	{
		hdl->in_index = 0;
	}
	hdl->count++;

	return QUEUE_SUCCESS;
}


queue_err_t out_queue_A(queue_A_hdl_t const hdl, unsigned char * const p_byte)
{
	if (NULL == hdl)
	{
		return QUEUE_ERR_NULL_PTR;
	}
	if (NULL == p_byte)
	{
		return QUEUE_ERR_INVALID_ARG;
	}

	if (0 == hdl->count)
	{
		return QUEUE_ERR_QUEUE_EMPTY;
	}

	*p_byte = hdl->buffer[hdl->out_index++];
	if (hdl->out_index >= hdl->size)
	{
		hdl->out_index = 0;
	}
	hdl->count--;

	return QUEUE_SUCCESS;
}


queue_err_t queue_flush_A(queue_A_hdl_t const hdl)
{
	if (NULL == hdl)
	{
		return QUEUE_ERR_NULL_PTR;
	}

	hdl->in_index = 0;
	hdl->out_index = 0;
	hdl->count = 0;

	return QUEUE_SUCCESS;
}


queue_err_t queue_init_B(unsigned char * const p_buf, unsigned int const size, queue_B_hdl_t * const p_hdl)
{
	queue_ctrl_B_t *p_qcb = 0;

	if (NULL == p_hdl)
	{
		return QUEUE_ERR_INVALID_ARG;
	}
	if (NULL == p_buf)
	{
		return QUEUE_ERR_NULL_PTR;
	}
	if (size < 2)
	{
		return QUEUE_ERR_INVALID_ARG;
	}

	p_qcb = &g_qcb_B[0];

	p_qcb->buffer = p_buf;
	p_qcb->size = size;
	p_qcb->head_index = 0;
	p_qcb->rear_index = 0;

	*p_hdl = p_qcb;
	return QUEUE_SUCCESS;
}


queue_err_t in_queue_B(queue_B_hdl_t const hdl, unsigned char const byte)
{
	if (NULL == hdl)
	{
		return QUEUE_ERR_NULL_PTR;
	}

	if (((hdl->rear_index + 1) % hdl->size) == hdl->head_index)
	{
		return QUEUE_ERR_QUEUE_FULL;
	}

	hdl->buffer[hdl->rear_index] = byte;
	hdl->rear_index = (hdl->rear_index + 1) % hdl->size;

	return QUEUE_SUCCESS;
}


queue_err_t out_queue_B(queue_B_hdl_t const hdl, unsigned char * const p_byte)
{
	if (NULL == hdl)
	{
		return QUEUE_ERR_NULL_PTR;
	}
	if (NULL == p_byte)
	{
		return QUEUE_ERR_INVALID_ARG;
	}

	if (hdl->rear_index == hdl->head_index)
	{
		return QUEUE_ERR_QUEUE_EMPTY;
	}
	
	*p_byte = hdl->buffer[hdl->head_index];
	hdl->head_index = (hdl->head_index + 1) % hdl->size;

	return QUEUE_SUCCESS;
}


queue_err_t queue_flush_B(queue_B_hdl_t const hdl)
{
	if (NULL == hdl)
	{
		return QUEUE_ERR_NULL_PTR;
	}

	hdl->head_index = 0;
	hdl->rear_index = 0;

	return QUEUE_SUCCESS;
}
