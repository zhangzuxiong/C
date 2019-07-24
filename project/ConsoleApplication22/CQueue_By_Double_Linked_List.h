#pragma once

#include "Double_Linked_List.h"


// 双链表实现循环队列

typedef struct CQueue {

	// 用双链表来保存队列数据
	DL_List list;

	// 队列的最大容量
	int max;

	// 记录放入队列的有效元素个数
	int count;

} CQueue;


// 1.初始化
void initCQueue(CQueue* p);



// 2.判空 如果为空，则为真；否则为假
int isEmpty(const CQueue queue);



// 3.判满 如果为满，则为真；否则为假
int isFull(const CQueue queue);



// 4.放入,p 表示需要操作的队列是谁， num 表示需要放入队尾的数值是多少
void putCQueue(CQueue* p, const int num);



// 5.取出
int getCQueue(CQueue* p);



// 6.清空
void clearCQueue(CQueue* p);



// 7.打印
void printCQueue(const CQueue queue);

