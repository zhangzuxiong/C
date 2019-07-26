

#include "Array_List.h"

//初始化全部赋值为0
void initArrayList(ArrayList* p) {
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < SIZE; i++)
	{
		p->arr[i] = NULL;
	}


	//有效元素置为0
	p->count = 0;

}

//判断是否为空
int isEmpoty(const ArrayList array) {
	if (array.count == 0)
	{
		//printf("数组为空!!\n");
		return 1;
	}
	else
	{
		//printf("数组不为空!!\n");
		return 0;
	}
}

//判满
int isFull(const ArrayList array) {
	if (array.count == SIZE)
	{
		//printf("数组已满!!\n");
		return 1;
	}
	else
	{
		//printf("数组未满!!\n");
		return 0;
	}
}

//放入,在数组的第position个位置放入value
void insertArrayList(ArrayList* p, const int position, const Element value) {
	if (isFull(*p))
	{
		return;
	}
	if (position<1 || position>p->count + 1)
	{
		printf("放入位置不合理\n");
		return;
	}

	if (p->count != 0)
	{
		int i = p->count;
		//数组往后移动
		for (i; i >= position - 1; i--)
		{
			p->arr[i] = p->arr[i - 1];
		}
	}

	//在第position个位置赋值
	p->arr[position - 1] = value;

	//有效元素加1
	p->count++;
}

//取出,取出数组中的第position个位置的值
Element getArrayList(ArrayList* p, const int position) {
	if (isEmpoty(*p))
	{
		return NULL;
	}

	if (position<1 || position>p->count + 1)
	{
		//printf("取出位置不合理\n");
		return NULL;
	}

	//保存第position个位置的值
	Element res = p->arr[position - 1];

	int i = position - 1;


	//数组前移
	for (i; i < p->count; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}

	p->count--;
	return res;
}

//清空
void clearArrayList(ArrayList* p) {
	if (isEmpoty(*p))
	{
		return;
	}
	initArrayList(p);
}

//打印
void printArrayList(const ArrayList array) {
	if (isEmpoty(array))
	{
		return;
	}
	for (int i = 0; i < array.count; i++)
	{
		printf("%d ", array.arr[i]);
	}
	printf("\n");
}

//查找
Element searchArrayList(const ArrayList array, const Element value) {
	if (isEmpoty(array))
	{
		return NULL;
	}
	for (size_t i = 0; i < array.count; i++)
	{
		if (array.arr[i] == value)
		{
			return array.arr[i];
		}
	}
	return NULL;
}
