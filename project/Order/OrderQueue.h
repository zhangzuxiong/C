#pragma once

#include "Order.h"
// ˫����ʵ��ѭ������

typedef struct OrderCQueue {

	// ��˫�����������������
	 OrderList list;

	// ���е��������
	int max;

	// ��¼������е���ЧԪ�ظ���
	int count;

} OrderCQueue;

// 1.��ʼ��
void initOrderCQueue(OrderCQueue* p);



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmptyOrderCQueue(const OrderCQueue queue);



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int isFullOrderCQueue(const OrderCQueue queue);



// 4.����,p ��ʾ��Ҫ�����Ķ�����˭�� num ��ʾ��Ҫ�����β�Ķ����Ƕ���
void putOrderCQueue(OrderCQueue* p, const Order order);



// 5.ȡ��
Order* getOrderCQueue(OrderCQueue* p);



// 6.���
void clearOrderCQueue(OrderCQueue* p);



// 7.��ӡ
void printOrderCQueue(const OrderCQueue queue);

