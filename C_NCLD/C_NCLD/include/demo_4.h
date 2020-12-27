/**
*	@file		demo_4.h
*	@author		嵌入式男单第九名
*	@details	示例内容
*	-# 记录指针常量与常量指针的特点
*	-# 记录含结构体指针参数的函数中，结构体成员的调用方法
**************************************************/
#pragma once

#define DEMO_4	"\n指针常量与结构体常量\n\n"

typedef struct st_int_data
{
	int	 data;
	int* p_data;
}int_data_t;
typedef struct st_int_data * int_data_hdl_t;

typedef struct st_const_test
{
	int data;
	const int c_data;		/* 含结构体常量的结构体在创建时必须对其常量进行初始化 */
	int * p_data;
	int const * icp_data;	/* 常量指针，可以改指向，不可改指向的值 */
	int * const ipc_data;	/* 指针常量，不可改指向，可以改指向的值 */
	int const * const icpc_data;	/* 指向常量的常量指针，指向与指向的值全不可改 */
	int_data_hdl_t int_data;
}const_test_t;
typedef struct st_const_test * const_test_hdl_t;

/**
*	@brief		测试用例入口函数
*	@details	
*				指针常量与结构体常量
**************************************************/
void demo_4(void);


/**
*	@brief		结构体指针作为参数1
*	@details	输出结构体指针为父级结构体指针
**************************************************/
void func1(const const_test_hdl_t p_hdl);

/**
*	@brief		结构体指针作为参数2
*	@details	输出结构体指针为子级结构体指针
*				输入参数为指针常量，不可以改指向（可改指向的值）
**************************************************/
void func2(int_data_hdl_t* const p_hdl);
