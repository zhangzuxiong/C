// Order.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Order_Have_Goods.h"
#include "Goods.h"
#include "User.h"
#include "Order.h"


void testOrderHaveGoods() {
	OrderHaveGoodsList list = { 0 };
	initOrderHavaGoods(&list);

	getOrderHavaGoodsData(&list);

	insertPositionOrderHavaGoods(&list, 1, 1, 2);
	insertPositionOrderHavaGoods(&list, 1, 2, 4);
	insertPositionOrderHavaGoods(&list, 1, 3, 6);
	insertPositionOrderHavaGoods(&list, 1, 4, 7);
	printOrderHavaGoods(list);

	saveOrderHavaGoodsData(list);

	printf("%d", searchOrderHavaGoodsByGoodsid(list, 2)->count);
	deletePositionOrderHavaGoods(&list, 2);
	printOrderHavaGoods(list);
}


void testGoods() {
	GoodsList list = { 0 };
	initGoods(&list);
	getGoodsData(&list);
	displayGoods(list,NULL);

	printf("\n----\n");

	insertGoods(&list, { NULL,"热干面",4 });
	insertGoods(&list, { NULL,"热干面",5 });
	insertGoods(&list, { NULL,"热干面",6 });

	displayGoods(list,NULL);

	printf("\n查找Id:%s\n", searchGoodsById(list, 7)->name);

	updateGoodsById(&list, { 13,"1234",1234 });

	displayGoods(list, NULL);

	saveGoods(list);

	clearGoods(&list);
	displayGoods(list, NULL);

}


void testUser() {
	UserList list = { 0 };
	initUserList(&list);

	getAllUserInfo(&list);
	printUserList(list);

	insertUser(&list,1, { 10001,"000000","admin","10010","武汉" });
	insertUser(&list,1, { 10002,"000000","admin","10010","武汉" });
	insertUser(&list,1, { 10003,"000000","admin","10010","武汉" });
	
	printf("\n====\n");
	
	printUserList(list);

	saveAllUserInfo(list);

}


void testOrder() {

	GoodsList goodsList = { 0 };

	initGoods(&goodsList);
	getGoodsData(&goodsList);
	displayGoods(goodsList,NULL);

	int count[3] = { 7,8,9 };

	UserList userList = { 0 };
	initUserList(&userList);
	getAllUserInfo(&userList);
	
	OrderList orderList = { 0 };
	initOrderList(&orderList);
	Order order = {1,1,"2019-8-8",goodsList,count};
	printf("count:%d\n", orderList.count);
	insertPositionOrderList(&orderList, orderList.count+1, order);
	insertPositionOrderList(&orderList, orderList.count+1, order);
	printOrderList(orderList, userList.head->user);

	saveAllOrderInfo(orderList, userList.head->user);


}

int main()
{

	testOrder();

	//testUser();

	//testOrderHaveGoods();

	//testGoods();

    return 0;
}

