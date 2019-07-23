
#include "Queue_by_Single_Linked_List.h"

// 1.初始化
void init_Queue(Queue* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" init_Queue 函数形参为空\n");

		return;
	}

	// 手动输入队列空间需要的最大容量
	printf(" 请输入队列空间需要的最大容量（正整数）：");

	scanf(" %d", &(p->max));

	// 可以尝试对输入的数字进行非正整数的判断

	// 初始化队列的存储空间，就是初始化单链表
	init_Single_Linked_List(&(p->list));

	// 可以尝试对申请好内存空间进行零值“初始化”

	// 队列内有效元素的个数 置零
	p->count = 0;

	// 头放置到数组的第一个元素
	p->head = 0;

	// 尾放置到数组的第一个元素
	p->tail = 0;

}



// 2.判空 如果为空，则为真；否则为假
int judge_empty(const Queue queue) {

	if (queue.count == 0)
	{
		printf(" 队列 为空\n");

		return 1;
	}
	else
	{
		printf(" 队列 不为空\n");

		return 0;
	}
}



// 3.判满 如果为满，则为真；否则为假
int judge_full(const Queue queue) {

	/*
		当 tail 走到数组的末尾时，其实前面 head 可能已经挪出可以存放的空间了，
		但是 tail 不能使用那些空间，因此是个假的满
	*/
	if (queue.tail == queue.max)
	{
		printf(" 队列 为满\n");

		return 1;
	}
	else
	{
		printf(" 队列 不为满\n");

		return 0;
	}
}



// 4.放入
// p 表示需要操作的队列是谁， num 表示需要放入队尾的数值是多少
void put_Queue(Queue* p, const int num) {

	// 指针判空
	if (p == NULL)
	{
		printf(" put_Queue 函数形参为空\n");

		return;
	}

	// 判满
	if (judge_full(*p))
	{
		printf(" 当前队列为满，无法放入新的元素\n");

		return;
	}

	// 找到队列的末尾，将 num 放入
	// 相当于在单链表的末尾插入一个新的结点
	insert_position_Single_Linked_List(&(p->list), p->count + 1, num);

	// 队尾向后挪一格
	p->tail++;

	// 有效元素的个数
	p->count++;
}



// 5.取出
int get_Queue(Queue* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" get_Queue 函数形参为空\n");

		return -1;
	}

	// 判空
	if (judge_empty(*p))
	{
		printf(" 当前队列为空，没有可以取出的元素\n");

		return -2;
	}

	// 用一个临时变量保存需要返回的数值
	int temp = 0;

	// 相当于从单链表的头 取出第一个结点的数值
	temp = p->list.head.next_pointer->data;

	// 删除单链表头的第一个结点
	delete_position_Single_Linked_List(&(p->list), 1);

	// 下面一行代码可以取代上面三行代码（推荐使用下面一行代码）
	//int temp = delete_position_Single_Linked_List(&(p->list), 1);

	// 有效元素个数 -1
	p->count--;

	// head 先后挪一格
	p->head++;

	// 判断 head 是否 取空了队列，如果取空队列，head 和 tail 要返回数组第一个元素的位置
	if (p->head == p->tail)
	{
		p->head = 0;
		p->tail = 0;
	}

	return temp;
}



// 6.清空
void clear_Queue(Queue* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" clear_Queue 函数形参为空\n");

		return;
	}

	// 判空
	if (judge_empty(*p))
	{
		printf(" 当前队列为空，没有清空的必要\n");

		return;
	}

	/*
		清空一个队列，实质上就是清空单链表
	*/
	clear_Single_Linked_List(&(p->list));

	// 有效元素的个数 置零
	p->count = 0;

	// 头和尾回到数组的第一个元素上
	p->head = 0;

	p->tail = 0;
}



// 7.打印
void print_Queue(const Queue queue) {

	// 判空
	if (judge_empty(queue))
	{
		printf(" 当前队列为空，没有可以打印的元素\n");

		return;
	}

	/*
		打印的时候需要按照队列的图形打印，先打印队列的头，最后是尾
	*/
	printf(" 从队列的头开始：\n");

	print_Single_Linked_List(queue.list);

	printf(" 到队列的尾结束！\n");
}


