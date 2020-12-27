/**
*	@mainpage  Embedded Summary
*	<table>
*	<tr><th>Project  <td>C_NCLD
*	<tr><th>Author   <td>嵌入式男单第九名
*	<tr><th>Source   <td>G:\\C_NCLD
*	<tr><th>Reference<td>
*	- https://mp.weixin.qq.com/s/w5I3_WJmYSNnEpI-GglBDw
*	</table>
*	@section   项目简介
*	人一能之，己百之；人十能之。己千之。果能此道矣，虽愚必明，虽柔必强。\n
*	                                              ——《礼记·中庸》\n
*	    嵌入式行业知识众多，自己不可能一下全部掌握，因此只能耐住心，不断学习。\n
*	但是在学习的过程中不可避免的一件事就是遗忘，这尤其体现在某些“知新”之后就\n
*	少有“温故”机会的地方。每当有所遗忘，就不得不又要花费时间去“温故”，这个\n
*	时候，如果有之前“知新”时的一些总结、笔记，往往会起到事半功倍的效果。因此\n
*	特意建立此项目用于总结Gavin在工作与学习中记录的基础编程知识。
*
*	@section   用法描述
*	-# 在demo_n函数中根据实际需求修改iGroupCnt变量值
*	-# 在main.c中调用demo_n函数
*	-# 编译工程并执行，生成demo_x.c、demo_x.h测试文件
*	-# 按模版编写生成的demo_x.c、demo_x.h文件
*	-# 在main.c中包含待测函数的头文件#include "demo_x.h"
*	-# 在main主函数中调用demo_x()
*
*	@section   变更记录
*	<table>
*	<tr><th>日期 <th>版本 <th>代号 <th>作者 <th>备注 </tr>
*	<tr><td>2020/03/14 <td>1.0.0 <td>20200314-1-0 <td>嵌入式男单第九名 <td>数据类型内存占用 </tr>
*	<tr><td>2020/03/16 <td>1.0.1 <td>20200316-2-0 <td>嵌入式男单第九名 <td>大小端内存存储 </tr>
*	<tr><td>2020/03/16 <td>1.0.1 <td>20200316-2-0 <td>嵌入式男单第九名 <td>预留</tr>
*	<tr><td colspan="5">代号说明：yyyymmdd-n-x    变更日期-第n号示例-第x次变更(x=0表示创建)</tr>
*	</table>

**************************************************/

#ifndef _MAIN_H
#define _MAIN_H

/**
int printf(const char *format,[argument]);
format 参数输出的格式，定义格式为：%[flags][width][.perc][F|N|h|l]type也就是有5类，
1.flage 对齐
	'-'表示左对齐
	默认右对齐
2.width 字符宽
	%2X  输出两个字符的宽度，不足处空格补齐
	%02X 输出两个字符的宽度，不足处用零补齐
3.perc 小数点后面的位数
	%.4f 输出4为小数点
4.指针是否是远指针或整数是否是长整数
5.type(必备)
	d(i) 有符号10进制整数 
	u    无符号10进制整数
	x    十六进制整数
	o    八进制整数 
*/

#endif /* _MAIN_H */
