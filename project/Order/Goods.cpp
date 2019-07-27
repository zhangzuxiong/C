
#include "Goods.h"

static int GOODSID = 1;

//初始化
void initGoods(GoodsList* p) {
	// 指针判空
	if (p == NULL)
	{
		//printf("初始化商品信息的函数形参为空\n");

		return;
	}

	/*printf("请输入商品队列的长度:");
	scanf(" %d", &(p->max));

	while (p->max <= 0)
	{
		printf("输入有误，请重新输入:");
		scanf(" %d", &(p->max));
	}*/

	// 临时指针变量，用来释放结点空间
	GoodsNode* temp = p->head;



	// 循环遍历整个单链表，逐一释放每个结点
	while (p->head != NULL)
	{
		// 将 头指针 指向第一个结点的下一个结点（第二个）
		p->head = temp->next;

		// 释放 temp 所指向的结点，原单链表的第一个结点
		free(temp);

		// 将 temp 再次指向下一个需要释放的结点
		// 现单链表第一个结点，原单链表第二个结点
		temp = p->head;
	}

}



//新增，返回值1:插入成功,0:插入失败
int insertGoods(GoodsList* p, const Goods goods) {
	if (p == NULL)
	{
		printf("新增商品参数为空\n");
		return 0;
	}

	GoodsNode* index = p->head;

	//将商品保存到指针节点
	GoodsNode* data = (GoodsNode*)malloc(sizeof(GoodsNode));

	data->goods = goods;
	//自动生成商品ID
	data->goods.ID = GOODSID;

	//如果链表为空，则在第一个位置插入，需要特殊处理
	if (index == NULL)
	{
		p->head = data;
	}
	else
	{
		//在商品链表末尾插入一个商品
		while (index->next != NULL)
		{
			index = index->next;
		}

		index->next = data;
	}

	//队列末尾指针置位NULL
	data->next = NULL;


	//商品ID自增
	GOODSID++;

	return 1;

}

//通过商品ID删除对应的商品
int deleteGoodsById(GoodsList* p, const int ID) {
	// 指针判空
	if (p == NULL)
	{
		printf("删除函数形参为空\n");
		return 0;
	}


	if (ID < 1)
	{
		printf("输入的商品ID不合理\n");
		return 0;
	}

	//一个临时变量保存删除的商品
	GoodsNode* temp = p->head;

	//保存删除商品节点的前一个节点
	GoodsNode* pre = temp;

	while (temp->next != NULL && temp->goods.ID != ID)
	{
		pre = temp;
		temp = temp->next;
	}
	if (temp->goods.ID != ID)
	{
		printf("没有找到对应的商品\n");
		return 0;
	}

	//如果在第一个
	if (temp = pre)
	{
		p->head = pre->next;
	}
	else
	{
		pre->next = temp->next;
	}

	free(temp);

	printf("删除成功\n");
	return 1;
}


//取出队列的第一个节点元素,返回值，1：删除成功，0：删除失败
int deleteGoods(GoodsList* p) {
	// 指针判空
	if (p == NULL)
	{
		printf("取出函数形参为空\n");
		return 0;
	}


	//删除队列的第一个商品
	GoodsNode* temp = p->head;

	//头指针指向第二个节点
	p->head = temp;

	//销毁第一个节点空间
	printf("删除商品[商品ID:%d,商品名称:%s,商品价格:%d]\n", temp->goods.ID, temp->goods.name, temp->goods.price);
	free(temp);


	printf("删除成功\n");
	return 1;
}

//修改,返回值，1:修改成功,0:修改失败
int updateGoodsById(GoodsList* p, Goods goods) {


	//临时变量，保存商品信息
	GoodsNode* temp = p->head;
	while (temp != NULL)
	{
		if (temp->goods.ID == goods.ID)
		{
			temp->goods = goods;
			printf("修改成功\n");
			return 1;
		}
		temp = temp->next;
	}

	printf("您输入的商品ID不存在\n");

	return 0;
}


//查找--根据商品ID查找商品，返回值商品
Goods* searchGoodsById(const GoodsList list, int ID) {


	//临时变量，保存商品信息
	GoodsNode* temp = list.head;
	while (temp != NULL)
	{
		if (temp->goods.ID == ID)
		{
			printf("商品ID:%d,商品名称:%s,商品价格:%d\n", temp->goods.ID, temp->goods.name, temp->goods.price);
			return &(temp->goods);
		}
		temp = temp->next;
	}

	printf("没有找到\n");
	return NULL;
}


//显示商品信息
void displayGoods(const GoodsList list,int* count) {

	//临时商品节点保存商品信息
	GoodsNode* temp = list.head;

	if (temp!=NULL)
	{
		if (count!=NULL)
		{
			printf("\t%-10s%-10s%-14s%-5s\n", "商品ID", "商品名称", "商品价格(元)","个数(个)");
		}
		else
		{
			printf("\t%-10s%-10s%-5s\n", "商品ID","商品名称","商品价格(元)");
		}
	}
	int i = 0;
	while (temp != NULL)
	{
		if (count!=NULL)
		{
			printf("\t%-10d%-10s%-14d%-5d\n", temp->goods.ID, temp->goods.name, temp->goods.price,count[i]);
			i++;
			temp = temp->next;
		}
		else
		{
			//printf("商品ID:%d,商品名称:%s,商品价格:%d\n", temp->goods.ID, temp->goods.name, temp->goods.price);
			printf("\t%-10d%-10s%-5d\n", temp->goods.ID, temp->goods.name, temp->goods.price);
			temp = temp->next;
		}
		
		

	}
}



//清空
void clearGoods(GoodsList* p) {
	// 指针判空
	if (p == NULL)
	{
		printf("清空函数形参为空\n");
		return;
	}


	// 临时指针变量，用来释放结点空间
	GoodsNode* temp = p->head;

	// 循环遍历整个单链表，逐一释放每个结点
	while (p->head != NULL)
	{
		// 将头指针指向第一个结点的下一个结点（第二个）
		//p->head = p->head->next;
		p->head = temp->next;

		// 释放 temp 所指向的结点，原单链表的第一个结点
		free(temp);

		// 将 temp 再次指向下一个需要释放的结点
		temp = p->head;
	}

}

//将商品信息保存到文件
void saveGoods(const GoodsList list) {
	FILE* file = fopen("../Order/goods.txt", "w");
	if (!file)
	{
		printf("文件打开失败\n");
		return;
	}

	//保存商品的节点
	GoodsNode* node = list.head;

	//循环遍历将每一个商品写入文件
	while (node != NULL)
	{
		fprintf(file, "%d\t%s\t\%d\n", node->goods.ID, node->goods.name, node->goods.price);
		node = node->next;
	}

	printf("商品保存成功\n");

	//文件关闭
	fclose(file);
}


//将文件中的商品读取到队列
void getGoodsData(GoodsList* p) {
	FILE* file = fopen("../Order/goods.txt", "r");
	if (!file)
	{
		printf("文件打开失败\n");
		return;
	}

	GoodsNode* temp = NULL;

	//头结点特殊处理
	GoodsNode* index;

	p->head = index = (GoodsNode*)malloc(sizeof(GoodsNode));

	fscanf(file, "%d\t%s\t\%d\n", &index->goods.ID, &index->goods.name, &index->goods.price);
	if (index->goods.ID < 1)
	{
		printf("文件为空\n");
		return;
	}
	GOODSID++;

	//将文件内容读取出来
	while (!feof(file))
	{
		//没读取一个商品，商品ID加1
		GOODSID++;

		temp = (GoodsNode*)malloc(sizeof(GoodsNode));

		fscanf(file, "%d\t%s\t\%d\n", &temp->goods.ID, &temp->goods.name, &temp->goods.price);
		index->next = temp;

		index = index->next;

	}

	//队列末尾置位NULL
	temp->next = NULL;


	//关闭文件
	fclose(file);
}