/**
*	@file		demo_5.h
*	@author		嵌入式男单第九名
*	@details	示例内容
*	-# C语言实现两种结构的循环队列
*	-# 通过虚拟串口来演示循环队列的使用方法
**************************************************/
#pragma once

#define DEMO_5	"\n循环队列的实现\n\n"

#define QUEUE_CFG_BUFF_SIZE	(256)	/*< 串口接收缓冲区大小 */
#define QUEUE_CFG_MAX_CTRL_BLKS	(2)	/*< 最大队列控制块个数 */

/**
*	@enum	e_queue_err
*	@brief	队列操作异常代码
**************************************************/
typedef enum e_queue_err
{
	QUEUE_SUCCESS = 0,				/*< 队列操作成功 */
	QUEUE_ERR_NULL_PTR,				/*< 队列缓冲区无效 */
	QUEUE_ERR_INVALID_ARG,			/*< 队列参数无效 */
	QUEUE_ERR_QUEUE_FULL,			/*< 队列满 */
	QUEUE_ERR_QUEUE_EMPTY			/*< 队列空 */
} queue_err_t;

/**
*	@struct	st_queue_ctrl_A
*	@brief	循环队列结构控制块A
**************************************************/
typedef struct st_queue_ctrl_A
{
	unsigned char	*buffer;		/*< 队列缓冲区指针 */
	unsigned int	size;			/*< 队列缓冲区大小 */
	unsigned int	count;			/*< 队列缓冲区中有效数据个数 */
	unsigned int	in_index;		/*< 入队指针位置 */
	unsigned int	out_index;		/*< 出队指针位置 */
} queue_ctrl_A_t;
typedef struct st_queue_ctrl_A *  queue_A_hdl_t;

/**
*	@struct	st_queue_ctrl_B
*	@brief	循环队列结构控制块B
**************************************************/
typedef struct st_queue_ctrl_B
{
	unsigned char	*buffer;		/*< 队列缓冲区指针 */
	unsigned int	size;			/*< 队列缓冲区大小 */
	unsigned int	head_index;		/*< 入队指针位置 */
	unsigned int	rear_index;		/*< 出队指针位置 */
}queue_ctrl_B_t;
typedef struct st_queue_ctrl_B *  queue_B_hdl_t;

/**
*	@brief		测试用例入口函数
*	@details	
*				循环队列
**************************************************/
void demo_5(void);

/**
*	@brief		循环队列初始化
*	@details	配置循环队列缓冲区，并初始化循环队列参数
*	@param[in]	p_buf	循环队列缓冲区首地址
*	@param[in]	size	循环队列缓冲区大小
*	@param[in]	p_hdl	循环队列控制块首地址
*	@return		循环队列初始化成功与否
*		@retval QUEUE_SUCCESS 成功
*		@retval QUEUE_ERR_INVALID_ARG 队列参数无效
*		@retval QUEUE_ERR_NULL_PTR 缓冲区配置失败
**************************************************/
queue_err_t queue_init_A(unsigned char * const p_buf, unsigned int const size, queue_A_hdl_t * const p_hdl);

/**
*	@brief		数据入队
*	@details	循环队列入队一个字节，队列满时不再入队
*	@param[in]	hdl		循环队列控制块首地址
*	@param[in]	byte	待入队数据
*	@return		数据入队成功与否
*		@retval QUEUE_SUCCESS 成功
*		@retval QUEUE_ERR_QUEUE_FULL 队列溢满
*		@retcal QUEUE_ERR_NULL_PTR 无效循环队列指针
**************************************************/

queue_err_t in_queue_A(queue_A_hdl_t const hdl, unsigned char const byte);
/**
*	@brief		数据出队
*	@details	循环队列出队一个字节
*	@param[in]	hdl		循环队列控制块首地址
*	@param[in]	p_byte	待出队数据地址
*	@return		数据出队成功与否
*		@retval QUEUE_SUCCESS 成功
*		@retval QUEUE_ERR_QUEUE_EMPTY 队列为空
*		@retval QUEUE_ERR_INVALID_ARG 出队数据地址为空
*		@retcal QUEUE_ERR_NULL_PTR 无效循环队列指针
**************************************************/
queue_err_t out_queue_A(queue_A_hdl_t const hdl, unsigned char * const p_byte);

/**
*	@brief		循环队列复位
*	@details	复位循环队列
*	@param[in]	p_buf	循环队列缓冲区首地址
*	@return		程序执行成功与否
*		@retval QUEUE_SUCCESS 成功
*		@retval QUEUE_ERR_NULL_PTR 无效循环队列指针
**************************************************/
queue_err_t queue_flush_A(queue_A_hdl_t const hdl);


queue_err_t queue_init_B(unsigned char * const p_buf, unsigned int const size, queue_B_hdl_t * const p_hdl);
queue_err_t in_queue_B(queue_B_hdl_t const hdl, unsigned char const byte);
queue_err_t out_queue_B(queue_B_hdl_t const hdl, unsigned char * const p_byte);
queue_err_t queue_flush_B(queue_B_hdl_t const hdl);
