// ConsoleApplication15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//双向链表--头节点和尾节点

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	//前一个
	Node* pre;

	//下一个
	Node* next;

	//数据
	int data;

} Node;

typedef struct Double_Linked_List
{
	//头节点
	Node head;

	//尾节点
	Node tail;

	//有效元素个数
	int count;
} DL_List;


//初始化
void init_Double_Linked_List(DL_List* p) {
	//指针判空
	if (p == NULL)
	{
		printf("初始化参数为空\n");
		return;
	}

	//如果已经是空，只要将头尾互联
	if (p->head.next==NULL)
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
bool judge_Empoty_Double_Linked_List(const DL_List list) {
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
int insert_Position_Double_Linked_List(DL_List* p, const const int position, const int num) {
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
int delete_Position_Double_Linked_List(DL_List* p, const int position) {
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
	Node* index = p->head.next;

	//保存删除的数据
	int res = 0;

	int i = 1;
	while (i<position)
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
int search_Value_Double_Linked_List(const DL_List list, const int num) {
	if (judge_Empoty_Double_Linked_List(list))
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
int search_Position_Double_Linked_List(const DL_List list, const int position) {
	if (judge_Empoty_Double_Linked_List(list))
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
Node* search_Position_Return_Address_Single_Linked_List(const DL_List list, const int position) {
	if (judge_Empoty_Double_Linked_List(list))
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
Node* search_Value_Return_Address_Single_Linked_List(const DL_List list, const int value) {
	if (judge_Empoty_Double_Linked_List(list))
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
void clear_Double_Linked_List(DL_List* p) {
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
void print_Double_Linked_List(const DL_List list) {
	if (judge_Empoty_Double_Linked_List(list))
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



int main()
{

	DL_List list = { 0 };
	init_Double_Linked_List(&list);

	insert_Position_Double_Linked_List(&list, 1, 1);
	insert_Position_Double_Linked_List(&list, 2, 2);
	print_Double_Linked_List(list);
	insert_Position_Double_Linked_List(&list, 3, 3);
	insert_Position_Double_Linked_List(&list, 4, 4);
	print_Double_Linked_List(list);

	Node* res = search_Value_Return_Address_Single_Linked_List(list, 1);
	printf("按照值查询地址结果：%p:%d\n", res, res->data);

	Node* res1 = search_Position_Return_Address_Single_Linked_List(list, 1);
	printf("按照位置查询地址结果：%p:%d\n", res1, res1->data);

	printf("search value 1:%d\n", search_Value_Double_Linked_List(list, 1));
	printf("search value 2:%d\n", search_Value_Double_Linked_List(list, 2));
	printf("search value 4:%d\n", search_Value_Double_Linked_List(list, 4));
	printf("search value 5:%d\n", search_Value_Double_Linked_List(list, 5));

	printf("search position 1:%d\n", search_Position_Double_Linked_List(list, 1));
	printf("search position 2:%d\n", search_Position_Double_Linked_List(list, 2));
	printf("search position 4:%d\n", search_Position_Double_Linked_List(list, 4));
	printf("search position 5:%d\n", search_Position_Double_Linked_List(list, 5));

	printf("删除的值为：%d\n", delete_Position_Double_Linked_List(&list, 1));
	printf("删除的值为：%d\n", delete_Position_Double_Linked_List(&list, 3));
	printf("删除的值为：%d\n", delete_Position_Double_Linked_List(&list, 2));
	printf("删除的值为：%d\n", delete_Position_Double_Linked_List(&list, 2));
	print_Double_Linked_List(list);


	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
