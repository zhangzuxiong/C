#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//商品基本信息
typedef struct Goods
{
	//商品ID
	int ID;

	//商品名称
	char name[20];

	//商品价格
	int price;

	//库存
	//int stock;

}Goods;


typedef struct GoodsNode {

	//商品
	Goods goods;

	//下一个商品
	GoodsNode* next;

} GoodsNode;

// 设计单链表的数据类型
typedef struct GoodsList {

	//第一个商品
	GoodsNode* head;

} GoodsList;


//初始化
void initGoods(GoodsList* p);


//新增，返回值1:插入成功,0:插入失败
int insertGoods(GoodsList* p, const Goods goods);

int insertGoodsByFile(GoodsList* p, const Goods goods);

//通过商品ID删除对应的商品
int deleteGoodsById(GoodsList* p, const int ID);


//取出队列的第一个节点元素,返回值，1：删除成功，0：删除失败
int deleteGoods(GoodsList* p);

//修改,返回值，1:修改成功,0:修改失败
int updateGoodsById(GoodsList* p, Goods goods);


//查找--根据商品ID查找商品，返回值商品
Goods* searchGoodsById(const GoodsList list, int ID);


//显示商品信息
void displayGoods(const GoodsList list,int* count);


//清空
void clearGoods(GoodsList* p);

//将商品信息保存到文件
void saveGoods(const GoodsList list);


//将文件中的商品读取到队列
void getGoodsData(GoodsList* p);
