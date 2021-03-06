
#include "Stack_by_Single_Linked_List.h"


// 1.初始化
void init_Stack(Stack* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" init_Stack 函数形参为空\n");

		return;
	}

	// 手动输入栈空间需要的最大容量
	printf(" 请输入栈空间需要的最大容量（正整数）：");

	scanf(" %d", &(p->max));

	// 栈使用的是单链表，所初始化栈，就是初始化其中属性 单链表
	init_Single_Linked_List(&(p->list));

	// 可以尝试对申请好内存空间进行零值“初始化”

	// 栈内有效元素的个数 置零
	p->count = 0;
}



// 2.判空 如果为空，则为真；否则为假
int judge_empty(const Stack stack) {

	if (stack.count == 0)
	{
		printf(" 栈 为空\n");

		return 1;
	}
	else
	{
		printf(" 栈 不为空\n");

		return 0;
	}
}



// 3.判满 如果为满，则为真；否则为假
int judge_full(const Stack stack) {

	if (stack.count == stack.max)
	{
		printf(" 栈 为满\n");

		return 1;
	}
	else
	{
		printf(" 栈 不为满\n");

		return 0;
	}
}



// 4.压入
// p 表示需要操作的栈是谁， num 表示需要压入栈的数值是多少
void push_Stack(Stack* p, const int num) {

	// 指针判空
	if (p == NULL)
	{
		printf(" push_Stack 函数形参为空\n");

		return;
	}

	// 判满
	if (judge_full(*p))
	{
		printf(" 当前栈为满，无法放入新的元素\n");

		return;
	}

	// 给栈顶放入一个值
	// 相当于在单链表的头插入一个新结点
	insert_position_Single_Linked_List(&(p->list), 1, num);

	// 有效元素的个数 +1
	p->count++;
}



// 5.弹出
// 弹出的变量的类型，取决于栈里面存放的元素的类型
// 弹出的必然是栈顶的那个元素，所以不需要形参来知道需要弹出哪个元素
int pop_Stack(Stack* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" pop_Stack 函数形参为空\n");

		return -1;
	}

	// 判空
	if (judge_empty(*p))
	{
		printf(" 当前栈为空，没有可以弹出的元素\n");

		return -2;
	}

	// 将需要弹出的数值先保留下来
	int res = p->list.head->data;

	// 弹出栈顶元素
	// 相当于 删除 单链表的第一个有效结点
	delete_position_Single_Linked_List(&(p->list), 1);

	// 下面一行代码等价于上面两行
	//int res = delete_position_Single_Linked_List(&(p->list), 1);

	// 栈里面的有效元素个数 -1
	p->count--;

	return res;
}



// 6.清空
void clear_Stack(Stack* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" clear_Stack 函数形参为空\n");

		return;
	}

	// 判空
	if (judge_empty(*p))
	{
		printf(" 当前栈为空，没有清空的必要\n");

		return;
	}

	/*
		清空一个栈，实质上需要清空单链表
	*/
	clear_Single_Linked_List(&(p->list));

	// 栈的有效元素个数 置零
	p->count = 0;
}



// 7.打印
void print_Stack(const Stack stack) {

	// 判空
	if (judge_empty(stack))
	{
		printf(" 当前栈为空，没有可以打印的元素\n");

		return;
	}

	/*
		打印的时候需要按照栈的图形打印，先打印栈的顶部，最后是底部

		按照单链表从头到尾进行打印
	*/
	printf(" 从栈顶开始：\n");

	print_Single_Linked_List(stack.list);

	printf(" 到栈底结束！\n");
}