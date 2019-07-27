#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct OrderGoods
{
	//用户ID
	int userId;

	int orderId;

	//商品Id
	int goodsId;

	//商品数量
	int count;

}OrderGoods;

typedef struct OrderHaveGoods
{
	//前一个
	OrderHaveGoods* pre;

	//下一个
	OrderHaveGoods* next;

	//商品Id
	int goodsId;

	//商品数量
	int count;

} OrderHaveGoods;



typedef struct OrderHaveGoodsList
{
	//头指针
	OrderHaveGoods* head;

	//尾指针
	OrderHaveGoods* tail;

	//有效元素个数
	int count;
} OrderHaveGoodsList;


//初始化
void initOrderHavaGoods(OrderHaveGoodsList* p);


//判空
bool judge_Empoty_Double_Linked_List(const OrderHaveGoodsList list);


//插入，在第position个位置插入
int insertPositionOrderHavaGoods(OrderHaveGoodsList* p, const const int position, const int goodsId, const int count);


//删除--根据位置删除
int deletePositionOrderHavaGoods(OrderHaveGoodsList* p, const int position);



//查找--按照值查询返回查找的地址
OrderHaveGoods* searchOrderHavaGoodsByGoodsid(const OrderHaveGoodsList list, const int value);

//清空
void clearOrderHavaGoods(OrderHaveGoodsList* p);


//打印
void printOrderHavaGoods(const OrderHaveGoodsList list);


//将订单中单个商品有多上个的信息保存到文件
void saveOrderHavaGoodsData(const OrderHaveGoodsList list);

//读取文件中单个商品在订单中的数量
void getOrderHavaGoodsData( OrderHaveGoodsList* p);


