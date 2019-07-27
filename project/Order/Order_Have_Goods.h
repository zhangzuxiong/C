#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct OrderGoods
{
	//�û�ID
	int userId;

	int orderId;

	//��ƷId
	int goodsId;

	//��Ʒ����
	int count;

}OrderGoods;

typedef struct OrderHaveGoods
{
	//ǰһ��
	OrderHaveGoods* pre;

	//��һ��
	OrderHaveGoods* next;

	//��ƷId
	int goodsId;

	//��Ʒ����
	int count;

} OrderHaveGoods;



typedef struct OrderHaveGoodsList
{
	//ͷָ��
	OrderHaveGoods* head;

	//βָ��
	OrderHaveGoods* tail;

	//��ЧԪ�ظ���
	int count;
} OrderHaveGoodsList;


//��ʼ��
void initOrderHavaGoods(OrderHaveGoodsList* p);


//�п�
bool judge_Empoty_Double_Linked_List(const OrderHaveGoodsList list);


//���룬�ڵ�position��λ�ò���
int insertPositionOrderHavaGoods(OrderHaveGoodsList* p, const const int position, const int goodsId, const int count);


//ɾ��--����λ��ɾ��
int deletePositionOrderHavaGoods(OrderHaveGoodsList* p, const int position);



//����--����ֵ��ѯ���ز��ҵĵ�ַ
OrderHaveGoods* searchOrderHavaGoodsByGoodsid(const OrderHaveGoodsList list, const int value);

//���
void clearOrderHavaGoods(OrderHaveGoodsList* p);


//��ӡ
void printOrderHavaGoods(const OrderHaveGoodsList list);


//�������е�����Ʒ�ж��ϸ�����Ϣ���浽�ļ�
void saveOrderHavaGoodsData(const OrderHaveGoodsList list);

//��ȡ�ļ��е�����Ʒ�ڶ����е�����
void getOrderHavaGoodsData( OrderHaveGoodsList* p);


