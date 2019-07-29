#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//��Ʒ������Ϣ
typedef struct Goods
{
	//��ƷID
	int ID;

	//��Ʒ����
	char name[20];

	//��Ʒ�۸�
	int price;

	//���
	//int stock;

}Goods;


typedef struct GoodsNode {

	//��Ʒ
	Goods goods;

	//��һ����Ʒ
	GoodsNode* next;

} GoodsNode;

// ��Ƶ��������������
typedef struct GoodsList {

	//��һ����Ʒ
	GoodsNode* head;

} GoodsList;


//��ʼ��
void initGoods(GoodsList* p);


//����������ֵ1:����ɹ�,0:����ʧ��
int insertGoods(GoodsList* p, const Goods goods);

int insertGoodsByFile(GoodsList* p, const Goods goods);

//ͨ����ƷIDɾ����Ӧ����Ʒ
int deleteGoodsById(GoodsList* p, const int ID);


//ȡ�����еĵ�һ���ڵ�Ԫ��,����ֵ��1��ɾ���ɹ���0��ɾ��ʧ��
int deleteGoods(GoodsList* p);

//�޸�,����ֵ��1:�޸ĳɹ�,0:�޸�ʧ��
int updateGoodsById(GoodsList* p, Goods goods);


//����--������ƷID������Ʒ������ֵ��Ʒ
Goods* searchGoodsById(const GoodsList list, int ID);


//��ʾ��Ʒ��Ϣ
void displayGoods(const GoodsList list,int* count);


//���
void clearGoods(GoodsList* p);

//����Ʒ��Ϣ���浽�ļ�
void saveGoods(const GoodsList list);


//���ļ��е���Ʒ��ȡ������
void getGoodsData(GoodsList* p);
