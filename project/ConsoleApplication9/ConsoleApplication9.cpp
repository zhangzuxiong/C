// ConsoleApplication9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//---循环队列

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

typedef struct Queue {

	/*
		使用动态内存申请，来解决不同的最大容量需要的内存空间

		定义一个指针变量，用来记录初始化的时候申请的内存空间的起始地址
	*/
	int* data_pointer;

	// 循环队列的最大容量
	int max;

	// 记录放入循环队列的有效元素个数
	int count;

	// 标记循环队列的头
	int head;

	// 标记循环队列的尾
	int tail;

} Queue;

// 1.初始化
void init_Queue(Queue* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" init_Queue 函数形参为空\n");

		return;
	}

	// 在申请新的内存空间给 data_pointer 之前，需要先将它指向的旧空间释放掉
	/*
		注意：

			1.不能释放同一个空间两次
			2.不能释放 NULL
	*/
	if (p->data_pointer != NULL)
	{
		free(p->data_pointer);
	}

	// 手动输入队列空间需要的最大容量
	printf(" 请输入队列空间需要的最大容量（正整数）：");

	scanf(" %d", &(p->max));

	// 可以尝试对输入的数字进行非正整数的判断

	// 根据输入的最大值，去动态申请对应的内存空间大小
	p->data_pointer = (int*)malloc(sizeof(int) * (p->max));

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
int judge_full(const Queue queue) {

	if (queue.count == queue.max)
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
// p 表示需要操作的队列是谁， num 表示需要放入队尾的数值是多少
void put_Queue(Queue* p, int num) {

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

	if (p->tail==p->max)
	{
		p->tail = 0;
	}
	// 找到队列的末尾，将 num 放入
	p->data_pointer[p->tail] = num;

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
	int temp = p->data_pointer[p->head];

	// 有效元素个数 -1
	p->count--;


	// head 先后挪一格
	p->head++;
	if (p->head==p->max)
	{
		p->head = 0;
	}

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
		清空一个队列，实质上需要保留队列本身已申请的动态内存空间

		清除里面的队列的元素，即可

		不需要释放队列本身已申请的动态内存空间
	*/
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

	int i = 0;

	int temp = queue.head;

	while (i < queue.count)
	{
		printf(" queue[%d] = %d\n", temp, queue.data_pointer[temp]);

		temp++;
		if (temp==queue.max)
		{
			temp = 0;
		}

		i++;
	}

	printf(" 到队列的尾结束！\n");
}


int main()
{
	Queue queue = { 0 };
	init_Queue(&queue);


	put_Queue(&queue, 10);
	put_Queue(&queue, 11);
	put_Queue(&queue, 12);
	put_Queue(&queue, 13);
	put_Queue(&queue, 14);
	print_Queue(queue);

	printf("\n---------------");

	printf("%d\n",get_Queue(&queue));
	printf("%d\n",get_Queue(&queue));
	print_Queue(queue);


	printf("\n---------------");
	put_Queue(&queue,15);
	print_Queue(queue);

    return 0;
}

