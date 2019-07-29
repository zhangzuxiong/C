#pragma once

#include "Order.h"
// 双链表实现循环队列

typedef struct OrderCQueue {

	// 用双链表来保存队列数据
	 OrderList list;

	// 队列的最大容量
	int max;

	// 记录放入队列的有效元素个数
	int count;

} OrderCQueue;

// 1.初始化
void initOrderCQueue(OrderCQueue* p);



// 2.判空 如果为空，则为真；否则为假
int isEmptyOrderCQueue(const OrderCQueue queue);



// 3.判满 如果为满，则为真；否则为假
int isFullOrderCQueue(const OrderCQueue queue);



// 4.放入,p 表示需要操作的队列是谁， num 表示需要放入队尾的订单是多少
void putOrderCQueue(OrderCQueue* p, const Order order);



// 5.取出
Order* getOrderCQueue(OrderCQueue* p);



// 6.清空
void clearOrderCQueue(OrderCQueue* p);



// 7.打印
void printOrderCQueue(const OrderCQueue queue);

