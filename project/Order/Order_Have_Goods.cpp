

#include "Order_Have_Goods.h"


//初始化
void initOrderHavaGoods(OrderHaveGoodsList* p) {
	//指针判空
	if (p == NULL)
	{
		printf("初始化参数为空\n");
		return;
	}

	//临时指针变量，来释放双链表中之前存在的空间
	OrderHaveGoods* temp = p->head;
	while (p->head != NULL)
	{
		//把头往后移动一个
		p->head = temp->next;

		//释放空间
		free(temp);

		//指向下一个释放的空间
		temp = p->head;
	}

	//尾指针置位NULL
	p->tail = NULL;

	//有效元素置位0
	p->count = 0;

}


//判空
bool judge_Empoty_Double_Linked_List(const OrderHaveGoodsList list) {
	if (list.count == 0)
	{
		//printf("双链表为空\n");
		return true;
	}
	else
	{
		//printf("双链表不为空\n");
		return false;
	}
}


//插入，在第position个位置插入
int insertPositionOrderHavaGoods(OrderHaveGoodsList* p, const const int position, const int goodsId, const int count) {
	if (p == NULL)
	{
		//printf("插入双链表的参数为空\n");
		return 0;
	}

	if (position < 1 || position > p->count + 1)
	{
		printf("插入位置不合理\n");
		return 0;
	}

	//新插入的节点
	OrderHaveGoods* node = (OrderHaveGoods*)malloc(sizeof(OrderHaveGoods));
	node->goodsId = goodsId;
	node->count = count;

	//链表为空
	if (p->count == 0)
	{
		//新节点既是头结点也是尾结点
		p->head = node;
		p->tail = node;

		//头结点的下一个和尾结点的前一个置为NULL
		p->head->next = NULL;
		p->tail->pre = NULL;
	}
	//链表非空，在头或尾插入
	else if (p->count != 0 && (position == 1 || position == p->count + 1))
	{
		//在头插入
		if (position == 1)
		{
			//新节点的下一个节点为头结点
			node->next = p->head;

			//新节点的前一个节点是头结点的前一个节点（NULL）
			node->pre = p->head->pre;

			//头节点的前一个节点是新节点
			p->head->pre = node;

			//将新节点设置为新的头结点
			p->head = node;
		}
		//在尾插入
		else
		{
			//新节点的下一个节点为尾结点的下一个节点（NULL）
			node->next = p->tail->next;

			//新节点的前一个节点是尾结点
			node->pre = p->tail;

			//尾结点的下一个节点是新节点
			p->tail->next = node;

			//将新节点设置为新的尾结点
			p->tail = node;
		}
	}
	//在中间插入
	else
	{
		//记录插入的位置
		OrderHaveGoods* index = p->head;

		//循环计数器，找到插入的位置
		int i = 1;
		while (i < position)
		{
			index = index->next;
			i++;
		}
		//先改变next，分为2步
		//1.新节点的下一个指向index的位置
		node->next = index;

		//2.插入位置的前一个指向新节点
		index->pre->next = node;


		//再改变pre,分为2步
		//1.新节点的前一个指向插入节点的前一个
		node->pre = index->pre;

		//2.插入位置的前一个指向新节点
		index->pre = node;
	}

	//有效元素加1
	p->count++;

	return 1;
}


//删除--根据位置删除
int deletePositionOrderHavaGoods(OrderHaveGoodsList* p, const int position) {
	if (p == NULL)
	{
		printf("删除参数为空\n");
		return 0;
	}

	if (judge_Empoty_Double_Linked_List(*p))
	{
		printf("双向链表为空,无法删除\n");
		return 0;
	}

	if (position < 1 || position > p->count)
	{
		printf("删除的位置不合理\n");
		return 0;
	}

	//记录删除的位置
	OrderHaveGoods* index = p->head;

	//保存删除的数据
	int res = 1;

	//双链表只有一个元素，直接释放头，头尾赋NULL
	if (p->count == 1)
	{

		//释放空间
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
	}
	//删除之后不空，并且删除的位置在第一个
	else if (position == 1 && p->count > 1)
	{

		//将head向后移动一个
		p->head = index->next;

		free(index);

		index = NULL;

		//新节点的前一个节点置位NULL
		p->head->pre = NULL;

		/*
		//头结点往后移动一个作为新的头节点
		p->head = p->head->next;
		//释放旧的头节点
		free(p->head->pre);
		//新的头结点的pre为NULL
		p->head->pre = NULL;
		*/
	}
	//删除最后一个，并且双链表有效元素大于1个
	else if (position == p->count && p->count > 1)
	{

		//将tail向前移动一个
		p->tail = p->tail->pre;

		//将末尾的前一个的next置位NULL，然后释放原链表的末尾节点
		free(p->tail->next);
		p->tail->next = NULL;
	}
	//删除在中间
	else
	{
		//循环计数器，找到删除的位置
		int i = 1;
		while (i < position)
		{
			index = index->next;
			i++;
		}

		//当前删除节点的前一个节点next指向删除节点的next
		index->pre->next = index->next;

		//当前删除节点next的pre指向index的pre
		index->next->pre = index->pre;

		//释放空间
		free(index);
	}

	//有效元素减1
	p->count--;
	//删除成功
	return res;
}



//查找--按照值查询返回查找的地址
OrderHaveGoods* searchOrderHavaGoodsByGoodsid(const OrderHaveGoodsList list, const int value) {
	if (judge_Empoty_Double_Linked_List(list))
	{
		printf("双链表已经为空，不能查找\n");
		return NULL;
	}

	//临时指针变量保存找到的地址
	OrderHaveGoods* temp = list.head;

	while (temp != NULL)
	{
		if (temp->goodsId == value)
		{
			return temp;
		}
		//指向下一个查找的位置
		temp = temp->next;
	}

	return NULL;
}

//清空
void clearOrderHavaGoods(OrderHaveGoodsList* p) {
	if (p == NULL)
	{
		printf("清空双链表的参数为空\n");
		return;
	}
	if (judge_Empoty_Double_Linked_List(*p))
	{
		printf("双链表已经为空，无需再清空\n");
		return;
	}

	while (p->head != NULL)
	{
		//临时变量，用来释放空间
		OrderHaveGoods* temp = p->head;

		//头指针往后移动一个
		p->head = temp->next;

		//释放空间
		free(temp);

		temp = NULL;

	}

	//尾指针置为NULL
	p->tail = NULL;

	//有效元素置为0
	p->count = 0;
}


//打印
void printOrderHavaGoods(const OrderHaveGoodsList list) {
	if (judge_Empoty_Double_Linked_List(list))
	{
		printf("双链表为空，没有可以打印的元素\n");
		return;
	}

	//临时变量，用来存储打印节点
	OrderHaveGoods* temp = list.head;

	while (temp != NULL)
	{
		printf("商品ID:%d有%d个\n", temp->goodsId, temp->count);

		//指向下一个打印的节点元素
		temp = temp->next;
	}
	printf("\n");
}


//将订单中单个商品有多上个的信息保存到文件
void saveOrderHavaGoodsData(const OrderHaveGoodsList list) {
	FILE* file = fopen("../Order/goodsandorder.txt", "w");
	if (!file)
	{
		printf("文件打开失败\n");
		return;
	}

	
	OrderHaveGoods* node = list.head;

	//循环遍历写入文件
	while (node != NULL)
	{
		fprintf(file, "%d\t\%d\n", node->goodsId, node->count);
		node = node->next;
	}

	printf("保存成功\n");

	//文件关闭
	fclose(file);
}

//读取文件中单个商品在订单中的数量
void getOrderHavaGoodsData(OrderHaveGoodsList* p) {
	FILE* file = fopen("../Order/goodsandorder.txt", "r");
	if (!file)
	{
		printf("文件打开失败\n");
		return;
	}

	OrderHaveGoods* temp = NULL;


	//将文件内容读取出来
	while (!feof(file))
	{

		temp = (OrderHaveGoods*)malloc(sizeof(OrderHaveGoods));

		fscanf(file, "%d\t\%d\n", &temp->goodsId, &temp->count);
		insertPositionOrderHavaGoods(p, 1, temp->goodsId, temp->count);

	}

	//关闭文件
	fclose(file);
}



