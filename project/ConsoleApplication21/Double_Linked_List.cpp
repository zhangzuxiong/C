
#include "Double_Linked_List.h"


//初始化
void initDoubleLinkedList(DL_List* p) {
	//指针判空
	if (p == NULL)
	{
		printf("初始化参数为空\n");
		return;
	}

	//如果已经是空，只要将头尾互联
	if (p->head.next == NULL)
	{
		p->head.next = &(p->tail);
		p->tail.pre = &(p->head);

		return;
	}

	//临时指针变量，来释放双链表中之前存在的空间
	Node* temp = p->head.next;
	while (p->head.next->next != NULL)
	{
		//把头往后移动一个
		p->head.next = temp->next;

		//释放空间
		free(temp);

		//指向下一个释放的空间
		temp = p->head.next;
	}

	//尾节点和头节点相连
	p->head.pre = NULL;
	p->head.data = 0;
	p->tail.next = NULL;
	p->tail.pre = &(p->head);
	p->tail.data = 0;

	//有效元素置位0
	p->count = 0;

}


//判空
bool judgeEmpotyDoubleLinkedList(const DL_List list) {
	if (list.count == 0)
	{
		printf("双链表为空\n");
		return true;
	}
	else
	{
		printf("双链表不为空\n");
		return false;
	}
}


//插入，在第position个位置插入一个数num
int insertPositionDoubleLinkedList(DL_List* p, const const int position, const int num) {
	if (p == NULL)
	{
		printf("插入双链表的参数为空\n");
		return 0;
	}

	if (position < 1 || position > p->count + 1)
	{
		printf("插入位置不合理\n");
		return 0;
	}

	//新插入的节点
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = num;

	int i = 0;

	Node* index = &(p->head);

	while (i < position)
	{
		index = index->next;

		i++;
	}

	// 将 新结点的 next 指向 定位的结点
	node->next = index;

	// 将 新结点的 pre 指向 定位的结点的前一个结点
	node->pre = index->pre;

	// 将 定位结点的前一个结点的 next 指向 新结点
	index->pre->next = node;

	// 将 定位结点的 pre 指向 新结点
	index->pre = node;

	//有效元素加1
	p->count++;

	return 1;
}


//删除--根据位置删除
int deletePositionDoubleLinkedList(DL_List* p, const int position) {
	if (p == NULL)
	{
		printf("删除参数为空\n");
		return 0;
	}

	if (judgeEmpotyDoubleLinkedList(*p))
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
	Node* index = p->head.next;

	//保存删除的数据
	int res = 0;

	int i = 1;
	while (i < position)
	{
		index = index->next;
		i++;
	}

	//前一个节点的next指向后一个节点
	index->pre->next = index->next;

	//后一个节点的pre指向前一个节点
	index->next->pre = index->pre;

	// 保存需要返回的数值
	res = index->data;

	// 释放 index
	free(index);

	//有效元素减1
	p->count--;
	printf("删除成功\n");
	return res;
}


//查找--根据值查找，返回值的位置
int searchValueDoubleLinkedList(const DL_List list, const int num) {
	if (judgeEmpotyDoubleLinkedList(list))
	{
		printf("双链表已经为空，不能查找\n");
		return 0;
	}

	//临时变量，遍历双链表查找
	Node* temp = list.head.next;

	int i = 1;

	while (temp->next != NULL)
	{
		//找到了返回，这个元素是双链表的第几个
		if (temp->data == num)
		{
			return i;
		}

		i++;
		temp = temp->next;
	}

	return 0;
}

//查找--根据位置查找，返回这个位置的值
int searchPositionDoubleLinkedList(const DL_List list, const int position) {
	if (judgeEmpotyDoubleLinkedList(list))
	{
		printf("双向链表为空,无法查找\n");
		return 0;
	}

	if (position < 1 || position > list.count)
	{
		printf("查找的位置不合理\n");
		return 0;
	}

	//临时变量，循环遍历双链表
	Node* temp = list.head.next;
	int i = 1;
	while (i < position)
	{
		temp = temp->next;
		i++;
	}

	return temp->data;
}

//查找--根据位置查找这个位置的地址
Node* searchPositionReturnAddressSingleLinkedList(const DL_List list, const int position) {
	if (judgeEmpotyDoubleLinkedList(list))
	{
		printf("双链表已经为空，不能查找\n");
		return NULL;
	}

	if (position < 1 || position > list.count)
	{
		printf("查找的位置不合理\n");
		return NULL;
	}

	//临时变量，循环遍历双链表
	Node* temp = list.head.next;
	int i = 1;
	while (i < position)
	{
		temp = temp->next;
		i++;
	}

	return temp;
}


//查找--按照值查询返回查找的地址
Node* searchValueReturnAddressSingleLinkedList(const DL_List list, const int value) {
	if (judgeEmpotyDoubleLinkedList(list))
	{
		printf("双链表已经为空，不能查找\n");
		return NULL;
	}

	//临时指针变量保存找到的地址
	Node* temp = list.head.next;

	while (temp->next != NULL)
	{
		if (temp->data == value)
		{
			return temp;
		}
		//指向下一个查找的位置
		temp = temp->next;
	}

	return NULL;
}

//清空
void clearDoubleLinkedList(DL_List* p) {
	if (p == NULL)
	{
		printf("清空双链表的参数为空\n");
		return;
	}
	if (judgeEmpotyDoubleLinkedList(*p))
	{
		printf("双链表已经为空，无需再清空\n");
		return;
	}

	while (p->head.next->next != NULL)
	{
		// 用一个临时指针变量保存需要释放的当前结点的内存空间的地址
		Node* temp = p->head.next;

		// 将 头结点 向后 挪一格 指向 原双链表的第二个结点
		p->head.next = p->head.next->next;

		// 释放 原双链表的第一个结点，就是temp指向的结点
		free(temp);

		temp = NULL;
	}

	// 将尾指针向前 指向头结点
	p->tail.pre = &(p->head);

	//有效元素置为0
	p->count = 0;
}


//打印
void printDoubleLinkedList(const DL_List list) {
	if (judgeEmpotyDoubleLinkedList(list))
	{
		printf("双链表为空，没有可以打印的元素\n");
		return;
	}

	//临时变量，用来存储打印节点
	Node* temp = list.head.next;

	while (temp->next != NULL)
	{
		printf("%d  ", temp->data);

		//指向下一个打印的节点元素
		temp = temp->next;
	}
	printf("\n");
}
