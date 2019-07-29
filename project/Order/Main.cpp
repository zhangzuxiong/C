// Order.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "User.h"
#include "OrderQueue.h"


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

	insertUser(&list, list.count + 1, { "admin","000000"});
	insertUser(&list, list.count + 1, { "admin1","111111"});
	insertUser(&list, list.count + 1, { "admin2","222222"});
	
	printf("\n====\n");
	
	printUserList(list);

	saveAllUserInfo(list);

}


void testOrder() {

	GoodsList goodsList = { 0 };

	initGoods(&goodsList);
	getGoodsData(&goodsList);
	displayGoods(goodsList,NULL);

	int count1[3] = { 7,7,7 };
	int count2[3] = { 8,8,8 };
	int count3[3] = { 9,9,9 };

	UserList userList = { 0 };
	initUserList(&userList);
	getAllUserInfo(&userList);
	
	OrderList orderList = { 0 };
	initOrderList(&orderList);

	getAllOrderInfo(&orderList);
	printOrderList(orderList);

	//return;


	Order order1 = {1,"天天","176123450","尚上游","2019-8-8",goodsList,count1};
	Order order2 = {1,"安安","13532452","武汉","2019-8-8",goodsList,count2};
	Order order3 = {1,"弟弟","138435347570","常青","2019-8-8",goodsList,count3};
	printf("count:%d\n", orderList.count);
	insertPositionOrderList(&orderList, orderList.count+1, order1);
	insertPositionOrderList(&orderList, orderList.count+1, order2);
	insertPositionOrderList(&orderList, orderList.count+1, order3);
	printOrderList(orderList);

	saveAllOrderInfo(orderList);

}


//下单
void produceOrder(OrderCQueue* p, const GoodsList goodsList) {

	if (p == NULL)
	{
		return;
	}
	//下单
	Order order = { 0 };
	printf("请输入姓名:");
	scanf(" %s", order.name);

	printf("请输入联系电话:");
	scanf(" %s", order.phone);

	printf("请输入收件地址:");
	scanf(" %s", order.address);

	printf("请输入下单时间:");
	scanf(" %s", order.order_time);

	//选择商品
	int select = 1;
	int i = 0;
	GoodsList goods = { 0 };
	initGoods(&goods);
	int num[10] = { 0 };
	while (select)
	{

		printf("请选择商品，输入0结束:\n");
		displayGoods(goodsList, NULL);
		scanf(" %d", &select);


		Goods* g = searchGoodsById(goodsList, select);

		if (g == NULL)
		{
			printf("选择的商品不存在\n");
			continue;
		}

		insertGoodsByFile(&goods, *g);

		printf("请输入购买数量:");
		scanf(" %d", &num[i]);
		i++;
		printf("\n");

	}

	order.count = num;
	order.goods = goods;

	putOrderCQueue(p, order);

}



void menu() {
	GoodsList goodsList = { 0 };
	initGoods(&goodsList);
	getGoodsData(&goodsList);

	UserList userList = { 0 };
	initUserList(&userList);
	getAllUserInfo(&userList);

	OrderCQueue orderQueue = { 0 };
	initOrderCQueue(&orderQueue);

	User user = { 0 };
	printf("请输入用户名:");
	scanf(" %s", user.name);
	printf("请输入密码:");
	scanf(" %s", user.password);

	User* fileUser = searchUserByID(userList, user.name);
	if (fileUser==NULL||!cmp(user.name, fileUser->name)||!cmp(user.password, fileUser->password))
	{
		printf("登录失败\n");
		return;
	}

	printf("%s,%s\n", fileUser->name, fileUser->password);


	OrderList orderList = { 0 };
	initOrderList(&orderList);

	int flag = 1;
	while (flag)
	{
		printf("\t\t1.下单\n");
		printf("\t\t2.查看订单\n");
		printf("\t\t3.退回订单\n");
		printf("\t\t0.退出\n");
		printf("请选择:");
		scanf(" %d", &flag);
		switch (flag)
		{
		case 1:
			produceOrder(&orderQueue, goodsList);
			break;

		case 2:
			printOrderCQueue(orderQueue);
			break;

		case 3:
			if (getOrderCQueue(&orderQueue)!=NULL) {
				printf("退回成功\n");
			}
			break;
		case 0:

			break;

		default:
			printf("输入有误\n");
			break;
		}




	}


	////查询订单号为1的结果
	//Order* res = searchValueReturnAddressOrderList(orderList, 1);

	//printf("查询结果:\n");
	//	res->order_num, res->name, res->order_time, res->address, res->phone);
	//printf("购买的商品是:\n");
	//displayGoods(res->goods, res->count);


	//退单
	/*Order* delorder = deletePositionOrderList(&orderList, 2);
	if (delorder!=NULL)
	{
		printf("删除的的订单号是：%d\n", delorder->order_num);
	}
	printOrderList(orderList);

	saveAllOrderInfo(orderList);*/


}


int main()
{

	menu();

	//testOrder();

	//testUser();

	//testOrderHaveGoods();

	//testGoods();

    return 0;
}

