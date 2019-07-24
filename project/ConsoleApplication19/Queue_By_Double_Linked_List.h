#pragma once

#include "Double_Linked_List.h"


// 双链表实现队列

typedef struct Queue {

	// 用双链表来保存队列数据
	DL_List list;

	// 队列的最大容量
	int max;

	// 记录放入队列的有效元素个数
	int count;

	// 标记队列的头
	int head;

	// 标记队列的尾
	int tail;

} Queue;


// 1.初始化
void initQueue(Queue* p);



// 2.判空 如果为空，则为真；否则为假
int isEmpty(const Queue queue);



// 3.判满 如果为满，则为真；否则为假
int isFull(const Queue queue);



// 4.放入,p 表示需要操作的队列是谁， num 表示需要放入队尾的数值是多少
void putQueue(Queue* p, const int num);



// 5.取出
int getQueue(Queue* p);



// 6.清空
void clearQueue(Queue* p);



// 7.打印
void printQueue(const Queue queue);

