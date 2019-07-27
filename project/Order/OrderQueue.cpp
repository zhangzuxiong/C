
#include "OrderQueue.h"
/*

// 1.初始化
void init_Circular_Queue(CQ* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" initt_Circular_Queue 函数形参为空\n");

		return;
	}

	// 手动输入循环队列空间需要的最大容量
	printf(" 请输入循环队列空间需要的最大容量（正整数）：");

	scanf(" %d", &(p->max));

	// 可以尝试对输入的数字进行非正整数的判断

	// 初始化 循环队列里面用来存放数据值的 单链表
	init_Single_Linked_List(&(p->list));

	// 可以尝试对申请好内存空间进行零值“初始化”

	// 循环队列内有效元素的个数 置零
	p->count = 0;
}



// 2.判空 如果为空，则为真；否则为假
int judge_empty(const CQ cqueue) {

	if (cqueue.count == 0)
	{
		printf(" 循环队列 为空\n");

		return 1;
	}
	else
	{
		printf(" 循环队列 不为空\n");

		return 0;
	}
}



// 3.判满 如果为满，则为真；否则为假
int judge_full(const CQ cqueue) {


	//当循环队列存放的有效元素的个数达到容量上限时，则放满，是真实的满

	if (cqueue.count == cqueue.max)
	{
		printf(" 循环队列 为满\n");

		return 1;
	}
	else
	{
		printf(" 循环队列 不为满\n");

		return 0;
	}
}



// 4.放入
// p 表示需要操作的循环队列是谁， num 表示需要放入队尾的数值是多少
void put_Circular_Queue(CQ* p, const int num) {

	// 指针判空
	if (p == NULL)
	{
		printf(" put_Circular_Queue 函数形参为空\n");

		return;
	}

	// 判满
	if (judge_full(*p))
	{
		printf(" 当前循环队列为满，无法放入新的元素\n");

		return;
	}

	// 找到队列的末尾，将 num 放入
	// 实质上就是在 里面存放数据值的 单链表 末尾增加一个新的结点
	insert_position_Single_Linked_List(&(p->list), p->count + 1, num);

	// 有效元素的个数
	p->count++;
}



// 5.取出
int get_Circular_Queue(CQ* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" get_Circular_Queue 函数形参为空\n");

		return -1;
	}

	// 判空
	if (judge_empty(*p))
	{
		printf(" 当前循环队列为空，没有可以取出的元素\n");

		return -2;
	}

	// 从 head 所标记的位置取出对应的元素
	// 实质上 是从里面保存数据值的 单链表的头 取出第一个结点
	// 用临时变量 temp 保存单链表删除头部的第一个结点时返回的数据值
	int temp = delete_position_Single_Linked_List(&(p->list), 1);

	// 有效元素个数 -1
	p->count--;

	return temp;
}



// 6.清空
void clear_Circular_Queue(CQ* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" clear_Circular_Queue 函数形参为空\n");

		return;
	}

	// 判空
	if (judge_empty(*p))
	{
		printf(" 当前循环队列为空，没有清空的必要\n");

		return;
	}


		//清空一个循环队列

		//实质上就是清空里面用来保存数据值的 单链表

	clear_Single_Linked_List(&(p->list));

	// 有效元素的个数 置零
	p->count = 0;
}



// 7.打印
void print_Circular_Queue(const CQ cqueue) {

	// 判空
	if (judge_empty(cqueue))
	{
		printf(" 当前循环队列为空，没有可以打印的元素\n");

		return;
	}


		//从头到尾打印循环队列

		//实质就是从头到尾 打印 其中的那根单链表

	printf(" 从循环队列的头开始：\n");

	print_Single_Linked_List(cqueue.list);

	printf(" 到循环队列的尾结束：\n");
}

*/