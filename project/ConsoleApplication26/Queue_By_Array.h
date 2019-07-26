#pragma once


#include "Array_List.h"

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
void initQueue(Queue* p);



// 2.判空 如果为空，则为真；否则为假
int isEmpty(const Queue queue);



// 3.判满 如果为满，则为真；否则为假
int isFull(const Queue queue);



// 4.插入,p 表示需要操作的队列是谁， num 表示需要插入队列的数值是多少
void putQueue(Queue* p, const Element num);



// 5.取出
Element getQueue(Queue* p);



// 6.清空
void clearQueue(Queue* p);



// 7.打印
void printQueue(const Queue stack);


