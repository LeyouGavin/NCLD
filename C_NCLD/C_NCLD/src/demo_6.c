/**
*	@file		demo_6.c
*	@brief		环形链表
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_6.h"

#define NAME_MAX (12)
#define RT_ASSERT(EX)								\
if (!(EX))											\
{													\
    assert_handler(#EX, __FUNCTION__, __LINE__);	\
}
#define _OBJ_CONTAINER_LIST_INIT(c)     \
    {&(liquor_container[c].object_list), &(liquor_container[c].object_list)}

void assert_handler(const char *ex_string, const char *func, int line);
char *strncpy(char *dst, const char *src, int n);
unsigned int strncmp(const char *cs, const char *ct, unsigned int count);
void whitespirit_add(struct whitespirit_info *object, enum liquor_type type, const char *name);
struct liquor_info* get_liquor_information(enum liquor_type type);
struct whitespirit_info* whitespirit_find(const char *name, enum liquor_type type);

/**
*	@enum	liquor_type
*	@brief	酒类别枚举
**************************************************/
enum liquor_type
{
	WhiteSpirit,/**< 白酒 */
	Whisky,		/**< 威士忌 */
	Liquor_Unknown
};

/**
*	@struct	whitespirit_info
*	@brief	白酒信息结构体
**************************************************/
struct whitespirit_info
{
	list_t	list;
	char name[NAME_MAX];
	int price;
};

/**
*	@struct	liquor_info
*	@brief	酒类型信息结构体
**************************************************/
struct liquor_info
{
	enum liquor_type type;
	list_t	object_list;
	int	object_size;
};

/**
*	@struct	liquor_container[]
*	@brief	酒类型容器，存放所有酒类信息
**************************************************/
static struct liquor_info liquor_container[Liquor_Unknown] =
{
	/**< Tips：通过枚举变量初始化不同容器链表 */
	{ WhiteSpirit, _OBJ_CONTAINER_LIST_INIT(WhiteSpirit), sizeof(struct whitespirit_info) },
	{ Whisky, _OBJ_CONTAINER_LIST_INIT(Whisky), 0 }
};

void demo_6(void)
{
	printf(DEMO_6);

	struct whitespirit_info *whitespirit;
	struct whitespirit_info whitespirit0;
	struct whitespirit_info whitespirit1;
	struct whitespirit_info whitespirit2;

	whitespirit_add(&whitespirit0, WhiteSpirit, "Maotai");
	whitespirit_add(&whitespirit1, WhiteSpirit, "Fenjiu");
	whitespirit_add(&whitespirit2, WhiteSpirit, "Wuliangye");

	whitespirit = whitespirit_find("Fenjiu", WhiteSpirit);
	printf("%s\n", whitespirit->name);

	list_t *node = liquor_container[0].object_list.next;
	whitespirit = get_container_of(node, struct whitespirit_info, list);
	printf("%s\n", whitespirit->name);
}

/**
*	@brief		新增一种白酒
*	@details	在白酒列表中新增一类指定名称的白酒
*	@param[in]	object	新增白酒信息首地址
*	@param[in]	type	新增酒所属枚举类型
*	@param[in]	name	新增白酒名称首地址
**************************************************/
void whitespirit_add(struct whitespirit_info *object, enum liquor_type type, const char *name)
{
	struct liquor_info *information;

	information = get_liquor_information(type);
	RT_ASSERT(information != 0);

	strncpy(object->name, name, NAME_MAX);
	list_insert_after(&(information->object_list), &(object->list));
}

/**
*	@brief		获取某种类型酒的信息
*	@details	遍历酒类列表，获取指定类型的酒信息首地址
*	@param[in]	type	需获取的酒类型
*	@return		
*		@retval 0	无指定类型的酒类型
*		@retval !0	指定类型的酒信息首地址
**************************************************/
struct liquor_info* get_liquor_information(enum liquor_type type)
{
	int index;

	for (index = 0; index < Liquor_Unknown; index++)
	{
		if (liquor_container[index].type == type)
		{
			return &liquor_container[index];
		}
	}

	return 0;
}

/**
*	@brief		查找某种白酒的信息
*	@details	遍历白酒列表，获取指定名称的白酒信息
*	@param[in]	name	需查找的酒名称
*	@param[in]	type	需查找的酒类型
*	@return
*		@retval 0	无指定名称的白酒信息
*		@retval !0	指定名称的白酒信息首地址
**************************************************/
struct whitespirit_info* whitespirit_find(const char *name, enum liquor_type type)
{
	struct whitespirit_info *whitespirit = 0;
	struct st_list_node *node = 0;
	struct liquor_info *liquor = 0;

	liquor = get_liquor_information(type);
	RT_ASSERT(0 != liquor);

	for (node = liquor->object_list.next;
		node != &(liquor->object_list);
		node = node->next)
	{
		whitespirit = get_container_of(node, struct whitespirit_info, list);
		if (0 == strncmp(whitespirit->name, name, NAME_MAX))
		{
			return whitespirit;
		}
	}
	return 0;
}

/**
*	@brief		字符串复制
*	@details	从源字符串复制指定字节长度的字符到目的字符串
*	@param[in]	dst	目的字符串首地址
*	@param[in]	src	源字符串首地址
*	@param[in]	n	需复制的字符串字节长度
*	@return		目的字符串首地址
**************************************************/
char *strncpy(char *dst, const char *src, int n)
{
	if (0 != n)
	{
		char *d = dst;
		const char *s = src;

		do {
			if ((*d++ = *s++) == 0)
			{
				while (--n != 0)
				{
					*d++ = 0;
				}
				break;
			}
		} while (--n != 0);
	}

	return dst;
}

/**
*	@brief		字符串比较
*	@details	比较两个字符串从首部开始的指定字节长度的字符内容
*	@param[in]	cs	比较字符串1
*	@param[in]	ct	比较字符串2
*	@param[in]	n	需比较的字符串字节长度
*	@return
*		@retval 0	字符串内容相同
*		@retval !0	字符串内容不同
**************************************************/
unsigned int strncmp(const char *cs, const char *ct, unsigned int count)
{
	char res = 0;

	while (count)
	{
		if ((res = *cs - *ct++) != 0 || !*cs++)
		{
			break;
		}
		count--;
	}

	return res;
}

void assert_handler(const char *ex_string, const char *func, int line)
{
	printf("(%s) assertion failed at function:%s, line number:%d \n", ex_string, func, line);
	while (1);
}
