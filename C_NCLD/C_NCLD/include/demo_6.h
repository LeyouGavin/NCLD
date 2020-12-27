/**
*	@file		demo_6.h
*	@author		嵌入式男单第九名
*	@details	示例内容
*	-# C语言实现双向链表（环形链表）
*	-# 简述内联函数使用规范
**************************************************/
#pragma once

#define DEMO_6	"\n双向链表的实现\n\n"

/**
*	@brief	获取指定结构体成员的指针地址
*	@details
*	- 宏定义
*		宏定义实现函数时不会检查函数参数，但内联函
*	数会。
*		宏是由预处理器对宏进行替代，而内联函数是通
*	过编译器控制来实现的。
*	- 内联函数（C99支持，C89不支持）
*		在程序编译时，编译器将程序中的内联函数的调
*	用表达式用内联函数的函数体来进行替换。由于节省
*	了函数调用的时间，因此提高了程序的运行效率，但
*	其增加了代码量，增加了空间的开销。
*		当函数体语句较少、没有复杂的循环语句且调用
*	频率较多时，可选用内联函数。但是内联函数体过大
*	时反而会增加二进制映像的大小，降低CPU高速缓存的
*	访问速度。
*		相比于宏定义，内联函数没有长度和格式限制。
*	编译器还可以检查函数调用方式，以防止其被误用。
*		内联标识只是建议编译器执行内联，在-O0优化
*	时可能不起作用，在ARM中可通过__attribute__
*	((always_inline))命令强制函数进行内联。
*		内联函数的定义一般放在头文件中，其他文件
*	要用的时候，包含定义了内联函数的头文件即可。
*	若在源文件中定义内联函数，在头文件中声明，由
*	于每个源文件都是独立编译的，因此编译完之后只
*	能像普通函数一样调用，失去内联意义。
*		内联函数在头文件中实现，等于一个普通函数在
*	头文件中定义，其他文件调用时展开为内联函数，如
*	果其被多个源文件包含，将会出现重定义的情况，因
*	此会在inline前用static修饰。（相当于在不同的源
*	文件中分别创建对象）
*		内联函数用于实现，不用于声明，即内联函数必
*	有函数体，否则内联不起作用
**************************************************/
#define get_container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))

/**
*	@brief	初始化一个链表对象
**************************************************/
#define LIST_OBJECT_INIT(object) { &(object), &(object) }

/**
*	@struct	st_list_node
*	@brief	双向链表
**************************************************/
struct st_list_node
{
	struct st_list_node *next;
	struct st_list_node *prev;
};
typedef struct st_list_node list_t;

/**
*	@brief	初始化一个双向环形链表
*	@param	l：待初始化的双向环形链表
**************************************************/
static inline void list_init(list_t *l)
{
	l->next = l->prev = l;
}

/**
*	@brief	在一个链表节点后插入一个新节点
*	@param	l：待插入的节点位置
*	@param	n：待插入的新节点
**************************************************/
static inline void list_insert_after(list_t *l, list_t *n)
{
	l->next->prev = n;
	n->next = l->next;

	l->next = n;
	n->prev = l;
}

/**
*	@brief	在一个链表节点前插入一个新节点
*	@param	l：待插入的结点位置
*	@param	n：待插入的新节点
**************************************************/
static inline void list_insert_before(list_t *l, list_t *n)
{
	l->prev->next = n;
	n->prev = l->prev;

	l->prev = n;
	n->next = l;
}

/**
*	@brief	在链表中删除一个节点
*	@param	n：待删除的节点
**************************************************/
static inline void list_remove(list_t *n)
{
	n->next->prev = n->prev;
	n->prev->next = n->next;

	n->next = n->prev = n;
}

/**
*	@brief	判断链表是否为空链表
*	@param	l：输入链表
**************************************************/
static inline int list_isempty(const list_t *l)
{
	return l->next == l;
}

/**
*	@brief	判断链表长度
*	@param	l：输入链表
**************************************************/
static inline unsigned int list_len(const list_t *l)
{
	unsigned int len = 0;
	const list_t *p = l;
	while (p->next != l)
	{
		p = p->next;
		len++;
	}
	return len;
}

/**
*	@brief	获取链表成员入口
*	@param	node：入口节点
*	@param	type：链表所在对象的结构体类型
*	@param	member：链表在对象结构体中的标识名
**************************************************/
#define get_list_entry(node, type, member) \
    get_container_of(node, type, member)

/**
*	@brief	遍历链表
**************************************************/
#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

/**
*	@brief	安全遍历链表
*			在安全链表上迭代，防止删除节点
**************************************************/
#define list_for_each_safe(pos, n, head) \
	for (pos = (head)->next, n = pos->next; pos != (head); \
		pos = n, n = pos->next)

/**
*	@struct	st_slist_node
*	@brief	单向链表
**************************************************/
struct st_slist_node
{
	struct st_slist_node *next;
};
typedef struct st_slist_node slist_t;


/**
*	@brief		测试用例入口函数
*	@details	
*				环形链表
**************************************************/
void demo_6(void);
