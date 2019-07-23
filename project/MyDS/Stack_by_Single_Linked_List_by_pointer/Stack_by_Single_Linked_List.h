#pragma once

#include  "Single_Linked_List.h"

typedef struct Stack {

	// 使用单链表来保存数据值
	SL_List list;
	//SL_List* p;

	// 栈的最大容量
	int max;

	// 记录放入栈的有效元素个数
	int count;

} Stack;



// 1.初始化
void init_Stack(Stack* p);



// 2.判空 如果为空，则为真；否则为假
int judge_empty( const Stack stack );



// 3.判满 如果为满，则为真；否则为假
int judge_full( const Stack stack );



// 4.压入
// p 表示需要操作的栈是谁， num 表示需要压入栈的数值是多少
void push_Stack( Stack* p, const int num );



// 5.弹出
// 弹出的变量的类型，取决于栈里面存放的元素的类型
// 弹出的必然是栈顶的那个元素，所以不需要形参来知道需要弹出哪个元素
int pop_Stack( Stack* p );



// 6.清空
void clear_Stack( Stack* p );



// 7.打印
void print_Stack( const Stack stack );