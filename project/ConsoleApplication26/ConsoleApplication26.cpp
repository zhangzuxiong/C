// ConsoleApplication26.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//数组实现队列  先进先出

#include "Queue_By_Array.h"

/*
typedef struct Queue
{
	//数组
	ArrayList list;

	//队列的最大容量
	int max;

	//队列的有效元素个数
	int count;


	//队列的头和尾只用来判满
	//队列的头
	int head;

	//队列的尾
	int tail;

} Queue;

// 1.初始化
void initQueue(Queue* p) {

	// 指针判空
	if (p == NULL)
	{
		return;
	}

	// 手动输入队列需要的最大容量
	printf(" 请输入队列需要的最大容量（正整数）：");

	scanf(" %d", &(p->max));

	// 队列使用的是数组，所初始化队列，就是初始化其中属性 数组
	initArrayList(&(p->list));

	// 队列有效元素的个数 置零
	p->count = 0;

	p->head = 0;

	p->tail = 0;
}



// 2.判空 如果为空，则为真；否则为假
int isEmpty(const Queue queue) {

	if (queue.count == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



// 3.判满 如果为满，则为真；否则为假
int isFull(const Queue queue) {

	if (queue.max == queue.tail)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



// 4.插入,p 表示需要操作的队列是谁， num 表示需要插入队列的数值是多少
void putQueue(Queue* p, const Element num) {

	// 指针判空
	if (p == NULL)
	{
		return;
	}

	// 判满
	if (isFull(*p))
	{
		printf(" 队列已满，无法放入新的元素\n");
		return;
	}

	// 给队列放入一个值
	// 相当于在数组第一位增加一个元素
	insertArrayList(&(p->list), 1, num);

	// 有效元素的个数 +1
	p->count++;

	p->tail++;
}



// 5.取出
Element getQueue(Queue* p) {

	// 指针判空
	if (p == NULL)
	{

		return NULL;
	}

	// 判空
	if (isEmpty(*p))
	{
		printf(" 队列为空，没有可以出队的元素\n");

		return NULL;
	}

	// 将需要弹出的数值先保留下来
	int res = p->list.arr[0];

	
	// 相当于 删除 数组的第一个元素
	getArrayList(&(p->list), 1);

	// 下面一行代码等价于上面两行
	//int res = getArrayList(&(p->list), 1);

	// 队列的有效元素个数 -1
	p->count--;

	p->head++;

	if (p->head == p->tail)
	{
		p->head = 0;
		p->tail = 0;
	}

	return res;
}



// 6.清空
void clearQueue(Queue* p) {

	// 指针判空
	if (p == NULL)
	{
		//printf(" 清空函数形参为空\n");

		return;
	}

	// 判空
	if (isEmpty(*p))
	{
		printf(" 当前队列为空，没有清空的必要\n");

		return;
	}

	//清空一个队列，实质上需要清空数组
	clearArrayList(&(p->list));

	// 队列的有效元素个数 置零
	p->count = 0;

	p->head = 0;
	p->tail = 0;
}



// 7.打印
void printQueue(const Queue stack) {

	// 判空
	if (isEmpty(stack))
	{
		printf(" 队列为空，没有可以打印的元素\n");

		return;
	}


	printArrayList(stack.list);
}

*/






void testQueue() {
	Queue queue = { 0 };
	initQueue(&queue);
	for (size_t i = 0; i < 10; i++)
	{
		putQueue(&queue, (i + 1) * 10);
	}

	printQueue(queue);

	for (size_t i = 0; i < 9; i++)
	{
		printf("出队元素:%d\n", getQueue(&queue));

	}
	putQueue(&queue, 101);

	printf("出队元素:%d\n", getQueue(&queue));
	putQueue(&queue, 101);

	printQueue(queue);

	clearQueue(&queue);
	printf("出队元素:%d\n", getQueue(&queue));

	printQueue(queue);
}

int main()
{


	return 0;
}
