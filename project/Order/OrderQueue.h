#pragma once

#include "Goods.h"

/*
	������ ʵ�� ѭ������



typedef struct Order
{
	//������
	int orderNum;


	//�ռ���
	char addressee[50];


	//��ϵ�绰
	char phone[20];


	//�ռ���ַ
	char address[50];


	//�µ�ʱ��
	char orderCreateTime[20];

	//������Ʒ������
	GoodsList goods;

	//��Ʒ������
	int count;

} Order;

typedef struct Order_Circular_Queue {

	// ʹ�õ�����������ѭ���������������ֵ
	Order head;


	// ѭ�����е��������
	int max;

	// ��¼����ѭ�����е���ЧԪ�ظ���
	int count;
} OCQ;


// 1.��ʼ��
void init_Circular_Queue(CQ* p);



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int judge_empty(const CQ cqueue);



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int judge_full(const CQ cqueue);



// 4.����
// p ��ʾ��Ҫ������ѭ��������˭�� num ��ʾ��Ҫ�����β����ֵ�Ƕ���
void put_Circular_Queue(CQ* p, const int num);



// 5.ȡ��
int get_Circular_Queue(CQ* p);



// 6.���
void clear_Circular_Queue(CQ* p);



// 7.��ӡ
void print_Circular_Queue(const CQ cqueue);
*/
