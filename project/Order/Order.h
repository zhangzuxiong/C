#pragma once

#include "Goods.h"


//订单
typedef struct Order {

	//订单号
	int order_num;

	//用户Id
	//int userId;


		//用户姓名
	char name[50];


	//联系电话
	char phone[20];


	//收件地址
	char address[50];


	//下单时间
	char order_time[20];

	//商品信息
	GoodsList goods;

	//定义一个数组里面数据为单个商品的数量
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
	//订单头
	OrderNode* head;

	OrderNode* tail;

	//有效元素个数
	int count;
}OrderList;


//初始化
void initOrderList(OrderList* p);


//判空
bool judgeEmpotyOrderList(const OrderList list);


//插入，在第position个位置插入一个订单
int insertPositionOrderList(OrderList* p, const const int position, const Order order);


//删除--根据位置删除
Order* deletePositionOrderList(OrderList* p, const int position);


//查找--根据值查找，返回值的位置
int searchValueOrderList(const OrderList list, const Order order);

//查找--根据位置查找，返回这个位置的值
Order* searchPositionOrderList(const OrderList list, const int position);


//查找--按照值查询返回查找的地址
Order* searchValueReturnAddressOrderList(const OrderList list, const int ordernum);

//清空
void clearOrderList(OrderList* p);


//打印
void printOrderList(const OrderList list);


//将订单信息保存到文件
void saveAllOrderInfo(const OrderList list);


//读取文件信息到内存
void getAllOrderInfo(OrderList* p);