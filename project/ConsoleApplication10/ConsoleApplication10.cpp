// ConsoleApplication10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//---单链表

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

typedef struct Node
{
	int data;

	Node* next;
} Node;

typedef struct Single_Linked_List
{
	//方式1：头指针
	Node* node;

	//方式2：头结点
	Node head;


	//有效节点的个数
	int count;

} SL_List;

//链表初始化
void init(SL_List* p) {
	if (p == NULL)
	{
		printf("初始化参数为空\n");
		return;
	}

	while (p->head.next != NULL)
	{
		//临时指针变量，释放空间
		Node* temp = p->head.next;
		//p->head.next = p->head.next->next;
		p->head.next = temp->next;
		free(temp);

		//将temp指向下一个释放的节点，上一次释放的下一个节点
		temp = p->head.next;
	}
	p->count = 0;

	//头结点指针置位NULL
	p->head.next = NULL;

	//头结点里面存放的数值置位0
	p->head.data = 0;
}

//判空
int judge_empoty_Single_Linked_List(const Single_Linked_List list) {
	if (list.count==0)
	{
		printf("链表为空\n");
		return 1;
	}
	else
	{
		printf("链表不为空\n");
		return 0;
	}
}

//插入--在index节点之前插入一个节点，num为该节点的数据
void insert_Single_Linked_List(SL_List* p,int index,int num) {
	if (p == NULL)
	{
		printf("插入的指针为空\n");
		return;
	}

	//判断插入位置是否合法
	if (index>p->count+1||index<=0)
	{
		printf("插入的位置不合理\n");
		return;
	}

	//if (index<p->count+2&&index>0)
	
	//定位插入位置的前一个位置
	int i = 1;
	Node* temp = &(p->head);
	while (i<index)
	{
		temp = temp->next;
		i++;
	}

	//创建新节点
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = num;
	node->next = temp->next;
	
	//将插入的节点加入链表
	temp->next = node;
	 
	//有效个数加1
	p->count++;
}

//删除--index删除的位置  返回值：删除节点的值
int delete_Single_Linked_List(SL_List* p, int index) {
	if (p == NULL)
	{
		printf("删除参数为空\n");
		return -1;
	}
	if (judge_empoty_Single_Linked_List(*p))
	{
		printf("链表已经为空，不需要再删除\n");
		return -2;
	}

	if (index>p->count||index<=0)
	{
		printf("删除的位置不合理\n");
		return -3;
	}

	int i = 1;
	//删除的前一个节点
	Node* temp = &(p->head);
	while (i<index)
	{
		temp = temp->next;
		i++;
	}
	Node* index_del = temp->next;
	int data_del = index_del->data;
	temp->next = index_del->next;
	free(index_del);
	index_del = NULL;
	p->count--;
	return data_del;
}

//查询
int lookup_Single_Linked_List(const SL_List list,int index) {
	if (judge_empoty_Single_Linked_List(list))
	{
		printf("链表已经为空，不需要查询\n");
		return -1;
	}
	if (index>list.count||index<1)
	{
		printf("删除位置不合理\n");
		return -2;
	}

	Node* index_look = (Node*)&(list.head);
	int i = 0;
	while (i<index)
	{
		index_look = index_look->next;
		i++;
	}

	return index_look->data;
}

// 按数值查询结点为位置
int lookup_value_Single_Linked_List(const SL_List list, const int value) {

	// 判空
	if (judge_empoty_Single_Linked_List(list))
	{
		printf(" 单链表为空，没有查询的必要\n");

		return -1;
	}

	// 用临时指针变量 index 遍历单链表进行定位
	// index 先定位在头结点的地址上
	Node* index = (Node*) & (list.head.next);

	// 用来计数
	int i = 1;

	while (index != NULL)
	{
		if (index->data == value)
		{
			return i;
		}

		index = index->next;

		i++;
	}

	printf(" 查询的数值，不在单链表的长度范围内\n");

	return -2;
}


// 按位置查询结点的地址
// 按数值查询结点的地址

//清空
void clear_Single_Linked_List(SL_List* p) {
	if (p==NULL)
	{
		printf("清空参数为空\n");
		return;
	}
	if (judge_empoty_Single_Linked_List(*p))
	{
		printf("链表已经为空，不需要再清空\n");
		return;
	}

	while (p->head.next!=NULL)
	{
		//临时指针变量，释放空间
		Node* temp = p->head.next;
		//p->head.next = p->head.next->next;
		p->head.next = temp->next;
		free(temp);

		//将temp指向下一个释放的节点，上一次释放的下一个节点
		temp = p->head.next;
	}
	p->count=0;

}

//打印
void print_Single_Linked_List(const SL_List list) {
	if (judge_empoty_Single_Linked_List(list))
	{
		printf("单链表为空，没有可以打印的元素\n");
		return;
	}
	
	Node* temp = list.head.next;
	while (temp!=NULL)
	{
		printf(" %d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	SL_List list = { 0 };
	insert_Single_Linked_List(&list, 1, 1);
	print_Single_Linked_List(list);
	insert_Single_Linked_List(&list, 2, 2);
	print_Single_Linked_List(list);
	insert_Single_Linked_List(&list, 3, 3);
	print_Single_Linked_List(list);
    return 0;
}
