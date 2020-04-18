#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MIN_INT 0
#define MAX_INT 32767
//const int MAX_INT = 32767;


//商品信息
typedef struct Goods
{
	//商品ID
	int ID;

	//商品名称
	char name[20];

	//商品价格
	int price;

}Goods;



//订单
typedef struct Order {

	//订单号
	int order_num;


	//收件人
	char addressee[50];


	//联系电话
	char phone[20];


	//收件地址
	char address[50];


	//下单时间
	char order_time[20];

	//商品信息
	Goods goods;

	//商品数量
	int count;

}Order;

void goods_sort(Goods* goods);
void order_sort(Order* order);
void cp(char source[200], char arr[200]);


//显示所有商品
void show_goods(Goods* goods) {
	if (goods==NULL)
	{
		printf("暂时还没有商品！！！\n");
		return;
	}
	int i = 0;
	while (goods[i].ID>0&&goods[i].ID<MAX_INT)
	{
		if (goods[i].ID>0&&goods[i].ID< MAX_INT)
		{
			printf("\t商品ID:%d,商品名称:%s,商品价格:%d元\n", goods[i].ID, goods[i].name, goods[i].price);
		}
		i++;
	}
	printf("\n");
}

//添加商品
void insert_goods(Goods* goods) {
	int i = 0;
	int id = 0;
	char name[20];
	printf("请输入商品ID:");
	scanf("%d", &id);
	while (goods[i].ID > 0 && goods[i].ID < MAX_INT)
	{
		if (goods[i].ID==id)
		{
			printf("该商品ID已存在！！\n");
			return;
		}
		i++;
	}


	i = 0;
	while (goods[i].ID > 0 && goods[i].ID < MAX_INT)
	{
		i++;
	}

	goods[i].ID = id;

	printf("请输入商品名称:");
	scanf("%s", &name);
	cp(name, goods[i].name);
	//*(goods[i].name) = *name;

	printf("请输入商品价格:");
	scanf("%d", &goods[i].price);
}

//删除商品
int delete_goods(Goods* goods, int num) {
	if (goods==NULL)
	{
		printf("商品不存在！！！\n");
		return 0;
	}
	int i = 0;
	char confirm[10] = "yes";
	while (goods[i].ID>0&&goods[i].ID< MAX_INT)
	{
		if (goods[i].ID==num)
		{
			printf("确定删除吗(输入y/n)?");
			scanf("%s", &confirm);
			if (confirm[0]=='y'||confirm[0]=='Y')
			{
				int j = i;
				//删除成功数组前移
				while (goods[j].ID > 0 && goods[j].ID < MAX_INT)
				{
					goods[j] = goods[j+1];
					j++;
				}
				goods[j] = { 0 };
				printf("删除成功！！\n");
				return 1;
			}
		}
		i++;
	}
	printf("删除失败！！！\n");
	return 0;
}

//修改商品
int update_goods(Goods* goods, int num) {
	if (goods==NULL)
	{
		printf("商品不存在！！！\n");
		return 0;
	}
	int i = 0;
	while (goods[i].ID>0&&goods[i].ID< MAX_INT)
	{
		if (goods[i].ID==num)
		{
			printf("请输入新的商品名称:");
			scanf("%s", &goods[i].name);

			printf("请输入新的商品价格:");
			scanf("%d", &goods[i].price);
			return 1;
		}
		i++;
	}
	printf("您输入的ID不存在该商品！！！\n");
	return 0;
}

//根据商品ID查询商品
void select_goods(Goods* goods, int id) {
	if (goods==NULL)
	{
		printf("商品不存在！！！\n");
		return;
	}
	int i = 0;
	while (goods[i].ID>0&&goods[i].ID< MAX_INT)
	{
		if (goods[i].ID==id)
		{
			printf("\t商品ID:%d,商品名称:%s,商品价格:%d元\n", goods[i].ID, goods[i].name, goods[i].price);
			return;
		}
		i++;
	}
	printf("没有找到您输入ID的商品！！！\n");
}

//下单
void insert_order(Order* order,Goods* goods) {
	int goods_menu=0;
	Order o;


	printf("请输入订单号:");
	scanf("%d", &o.order_num);
	int i = 0;
	while (order[i].order_num > 0 && order[i].order_num < MAX_INT)
	{
		if (order[i].order_num==o.order_num)
		{
			printf("该订单号已存在！！！\n");
			return;
		}
		i++;
	}


	printf("请输入收件人:");
	scanf("%s", &o.addressee);

	printf("请输入联系电话:");
	scanf("%s", &o.phone);

	printf("请输入收件地址:");
	scanf("%s", &o.address);

	printf("请输入下单时间:");
	scanf("%s", &o.order_time);


	show_goods(goods);
	printf("请选择购买的商品:");
	scanf("%d", &goods_menu);
	i = 0;
	while (goods[i].ID>0&&goods[i].ID< MAX_INT)
	{
		if (goods[i].ID==goods_menu)
		{
			o.goods = goods[i];
		}
		i++;
	}
	if (!(o.goods.ID>=0&&o.goods.ID<MAX_INT))
	{
		printf("您选择的商品不存在!!!\n");
		return ;
	}

	printf("请输入购买商品的数量:");
	scanf("%d", &o.count);

	i = 0;
	while (order[i].order_num>0&&order[i].order_num< MAX_INT)
	{
		i++;
	}
	order[i] = o;

}


//查询---订单号
void show_order(Order* order,Goods* goods,int id) {
	if (order==NULL)
	{
		printf("订单不存在！！\n");
		return;
	}
	int i = 0;
	int count = 0;
	while (order[i].order_num>0&&order[i].order_num< MAX_INT)
	{
		if (order[i].order_num==id)
		{
			count++;
			printf("订单号:%d,收件人:%s,联系电话:%s,收件地址:%s,下单时间:%s,商品[ID:%d,名称:%s,价格:%d],商品总数:%d\n",
						order[i].order_num, order[i].addressee, order[i].phone, order[i].address, order[i].order_time, order[i].goods.ID, 
						order[i].goods.name, order[i].goods.price, order[i].count);

		}
		i++;
	}
	if (!count)
	{
		printf("没有找到订单！！！\n");
	}
}

//显示全部订单
void show_order(Order* order, Goods* goods) {
	if (order==NULL)
	{
		printf("订单不存在！！\n");
		return;
	}
	int i = 0;
	while (order[i].order_num>0&&order[i].order_num< MAX_INT)
	{
		if (order[i].order_num>0&&order[i].order_num< MAX_INT)
		{
			printf("订单号:%d,收件人:%s,联系电话:%s,收件地址:%s,下单时间:%s,商品[ID:%d,名称:%s,价格:%d],商品总数:%d\n",
				order[i].order_num, order[i].addressee, order[i].phone, order[i].address, order[i].order_time, order[i].goods.ID,
				order[i].goods.name, order[i].goods.price, order[i].count);
		}
		i++;
	}
}



//修改
int update_order(Order* order,int id) {
	int i = 0;
	while (order[i].order_num > 0 && order[i].order_num < MAX_INT)
	{
		if (order[i].order_num==id)
		{
			//修改:收件人、电话、地址
			printf("请输入新的收件人:");
			scanf("%s", &order[i].addressee);

			printf("请输入新的联系电话:");
			scanf("%s", &order[i].phone);

			printf("请输入新的收件地址:");
			scanf("%s", &order[i].address);

			return 1;

		}
		i++;
	}
	return 0;
}


//取消
int delete_order(Order* order,int num) {
	int i = 0;
	char confirm[5];
	while (order[i].order_num > 0 && order[i].order_num < MAX_INT)
	{
		if (order[i].order_num==num)
		{
			//printf("确定取消订单吗(输入y/n)?");
			//scanf("%s", &confirm);
			char c;
			printf("确定取消订单吗(输入y/n)?");
			scanf(" %c", &c);
			if (c=='y'||c=='Y')
			{
				//将数组前移
				int j = i;
				while (order[j].order_num > 0 && order[j].order_num < MAX_INT)
				{
					order[j] = order[j + 1];
					j++;
				}
				order[j] = { 0 };
				return 1;

			}
		}
		i++;
	}

	return 0;
}

//订单排序
void order_sort(Order* order) {

	Order o;
	int i = 0, j=0;
	while (order[i].order_num > 0 && order[i].order_num < MAX_INT)
	{
		j = i + 1;
		while (order[j].order_num>0&&order[j].order_num<MAX_INT)
		{
			if (order[j].order_num<order[i].order_num)
			{
				o = order[j];
				order[j] = order[i];
				order[i] = o;
			}
			j++;
		}
		i++;
	}

}

//商品排序
void goods_sort(Goods* goods) {

	Goods g;
	int i = 0, j = 0;
	while (goods[i].ID > 0 && goods[i].ID < MAX_INT)
	{
		j = i + 1;
		while (goods[j].ID > 0 && goods[j].ID < MAX_INT)
		{
			if (goods[j].ID < goods[i].ID)
			{
				g = goods[j];
				goods[j] = goods[i];
				goods[i] = g;
			}
			j++;
		}
		i++;
	}

}

//计算订单总价
void total_price(Order* order, int order_num)
{
	if (order==NULL)
	{
		printf("订单为空！！\n");
		return;
	}
	int i = 0;
	while (order[i].order_num>0&&order[i].order_num<MAX_INT)
	{
		if (order[i].order_num==order_num)
		{
			int price = 0;
			price = order[i].count * order[i].goods.price;
			printf("订单号%d的总金额为%d元\n", order_num, price);
			return;
		}
		i++;
	}
	printf("您输入的订单号不存在！！！\n");
}

//打印字符串
void print(char arr[200]) {
	int i = 0;
	while (arr[i]!=0)
	{
		printf("%c", arr[i]);
		i++;
	}
	printf("\n");
}

//字符串复制 将source复制给arr
void cp(char source[200], char arr[200]) {
	int i = 0;
	while (source[i]!=0)
	{
		arr[i] = source[i];
		i++;
	}
	arr[i] = '\0';
}

int main()
{
	/*
	char a1[10] = "1234";
	char a2[10] = "qwertyuio";
	print(a1);
	cp(a2, a1);
	print(a1);

	char c;
	printf("请输入一个字符:");
	scanf(" %c", &c);
	printf("c=%c", c);
	return 0;
	*/


	Order order[10];
	Goods goods[10];
	int order_num = 0;
	int goods_id = 0;
	int result = 0;
	int menu = 1;
	while (menu)
	{
		printf("\n\n\t1.商品添加\t\t2.商品修改\n");
		printf("\t3.商品查找\t\t4.商品删除\n");
		printf("\t5.显示所有商品\t\t6.下单\n");
		printf("\t7.修改订单\t\t8.查找订单\n");
		printf("\t9.删除订单\t\t10.显示所有订单\n");
		printf("\t11.对所有订单排序\t12.对所有商品排序\n");
		printf("\t13.计算订单的总金额\t0.退出\n");

		printf("请选择功能:");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			//新增商品
			insert_goods(goods);
			break;		
		
		case 2:
			//修改商品
			printf("请输入想要修改的商品的ID:");
			scanf("%d", &goods_id);
			update_goods(goods, goods_id);
			break;	

		case 3:
			//根据ID查询商品
			printf("请输入想要查询的商品的ID:");
			scanf("%d", &goods_id);
			select_goods(goods, goods_id);
			break;	

		case 4:
			//删除商品
			printf("请输入想要删除的商品的ID:");
			scanf("%d", &goods_id);
			result=delete_goods(goods, goods_id);
			break;	

		case 5:
			//显示所有商品
			show_goods(goods);
			break;	

		case 6:
			//下单
			insert_order(order, goods);
			break;	

		case 7:
			//修改订单
			printf("请输入需要修改订单的的订单号:");
			scanf("%d", &order_num);
			result = update_order(order, order_num);
			if (result == 1)
			{
				printf("修改成功！！\n");
			}
			if (result == 0)
			{
				printf("没有找到您输入的订单号！！！\n");
			}
			break;	

		case 8:
			//查询订单
			printf("请输入需要查询的订单:");
			scanf("%d", &order_num);
			show_order(order, goods, order_num);
			break;	

		case 9:
			//删除订单
			printf("请输入需要删除订单的订单号:");
			scanf("%d", &order_num);
			result = delete_order(order, order_num);
			if (result == 1)
			{
				printf("删除成功！！\n");
			}
			if (result == 0)
			{
				printf("没有找到您输入的订单号！！！\n");
			}
			break;	

		case 10:
			show_order(order, goods);
			break;

		case 11:
			order_sort(order);
			break;	

		case 12:
			goods_sort(goods);
			break;	
			
		case 13:
			printf("请输入需要计算订单总金额的订单号：");
			scanf("%d", &order_num);
			total_price(order, order_num);
			break;	

		case 0:
			return 0;

		default:
			break;
		}
	}


	//printf("%d   %s   %d\n", goods[0].ID, goods[0].name, goods[0].price);
	

    return 0;
}
