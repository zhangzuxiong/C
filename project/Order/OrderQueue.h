#pragma once

#include "Goods.h"

/*
	单链表 实现 循环队列



typedef struct Order
{
	//订单号
	int orderNum;


	//收件人
	char addressee[50];


	//联系电话
	char phone[20];


	//收件地址
	char address[50];


	//下单时间
	char orderCreateTime[20];

	//保存商品的链表
	GoodsList goods;

	//商品总数量
	int count;

} Order;

typedef struct Order_Circular_Queue {

	// 使用单链表来保存循环队列里面的数据值
	Order head;


	// 循环队列的最大容量
	int max;

	// 记录放入循环队列的有效元素个数
	int count;
} OCQ;


// 1.初始化
void init_Circular_Queue(CQ* p);



// 2.判空 如果为空，则为真；否则为假
int judge_empty(const CQ cqueue);



// 3.判满 如果为满，则为真；否则为假
int judge_full(const CQ cqueue);



// 4.放入
// p 表示需要操作的循环队列是谁， num 表示需要放入队尾的数值是多少
void put_Circular_Queue(CQ* p, const int num);



// 5.取出
int get_Circular_Queue(CQ* p);



// 6.清空
void clear_Circular_Queue(CQ* p);



// 7.打印
void print_Circular_Queue(const CQ cqueue);
*/
