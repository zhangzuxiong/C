#pragma once

#include "Goods.h"


//����
typedef struct Order {

	//������
	int order_num;

	//�û�Id
	//int userId;


		//�û�����
	char name[50];


	//��ϵ�绰
	char phone[20];


	//�ռ���ַ
	char address[50];


	//�µ�ʱ��
	char order_time[20];

	//��Ʒ��Ϣ
	GoodsList goods;

	//����һ��������������Ϊ������Ʒ������
	int* count;

}Order;

//
typedef struct OrderNode {

	OrderNode* next;

	OrderNode* pre;


	Order order;

}OrderNode;

typedef struct OrderList
{
	//����ͷ
	OrderNode* head;

	OrderNode* tail;

	//��ЧԪ�ظ���
	int count;
}OrderList;


//��ʼ��
void initOrderList(OrderList* p);


//�п�
bool judgeEmpotyOrderList(const OrderList list);


//���룬�ڵ�position��λ�ò���һ������
int insertPositionOrderList(OrderList* p, const const int position, const Order order);


//ɾ��--����λ��ɾ��
Order* deletePositionOrderList(OrderList* p, const int position);


//����--����ֵ���ң�����ֵ��λ��
int searchValueOrderList(const OrderList list, const Order order);

//����--����λ�ò��ң��������λ�õ�ֵ
Order* searchPositionOrderList(const OrderList list, const int position);


//����--����ֵ��ѯ���ز��ҵĵ�ַ
Order* searchValueReturnAddressOrderList(const OrderList list, const int ordernum);

//���
void clearOrderList(OrderList* p);


//��ӡ
void printOrderList(const OrderList list);


//��������Ϣ���浽�ļ�
void saveAllOrderInfo(const OrderList list);


//��ȡ�ļ���Ϣ���ڴ�
void getAllOrderInfo(OrderList* p);