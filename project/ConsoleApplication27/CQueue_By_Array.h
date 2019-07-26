#pragma once


#include "Array_List.h"

typedef struct CQueue
{
	//数组
	ArrayList list;

	//循环队列的最大容量
	int max;

	//循环队列的有效元素个数
	int count;

} CQueue;


// 1.初始化
void initCQueue(CQueue* p);



// 2.判空 如果为空，则为真；否则为假
int isEmpty(const CQueue queue);



// 3.判满 如果为满，则为真；否则为假
int isFull(const CQueue queue);



// 4.插入,p 表示需要操作的循环队列是谁， num 表示需要插入循环队列的数值是多少
void putCQueue(CQueue* p, const Element num);



// 5.取出
Element getCQueue(CQueue* p);



// 6.清空
void clearCQueue(CQueue* p);



// 7.打印
void printCQueue(const CQueue stack);


