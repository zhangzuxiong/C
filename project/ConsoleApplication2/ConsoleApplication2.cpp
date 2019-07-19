// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

int arr[SIZE] = { 0 };
int num = 0;


//初始化全部赋值为0
void Init_arr() {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = 0;
	}
}

//判断是否为空
int is_empoty() {
	if (num == 0)
	{
		printf("数组为空!!\n");
		return 1;
	}
	else
	{
		printf("数组不为空!!\n");
		return 0;
	}
}

//判满
int is_full() {
	if (num == SIZE)
	{
		printf("数组已满!!\n");
		return 1;
	}
	else
	{
		printf("数组未满!!\n");
		return 0;
	}
}

//放入
void insert(int n) {
	if (is_full())
	{
		return;
	}
	else
	{
		arr[num] = n;
		num++;
	}
}

//取出最后一个
int get_one() {
	if (is_empoty())
	{
		return -1;
	}
	else
	{
		num--;
		return arr[num];
	}
}

//清空
void empoty() {
	if (is_empoty())
	{
		return;
	}
	Init_arr();
	num = 0;
}

void display() {
	if (is_empoty())
	{
		return;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void search(int n) {
	if (is_empoty())
	{
		return;
	}
	for (size_t i = 0; i < num; i++)
	{
		if (arr[i] == n)
		{
			printf("找到了%d\n", arr[i]);
			return;
		}
	}
	printf("没有找到!\n");
}



int main()
{
	printf("初始化...\n");
	Init_arr();
	display();
	is_empoty();
	is_full();

	printf("\n取出最后插入的数\n");
	printf("%d\n", get_one());
	display();
	is_empoty();
	is_full();

	printf("\n插入一个数10\n");
	insert(10);
	insert(11);
	insert(12);
	display();
	is_empoty();
	is_full();

	printf("\n取出最后插入的数\n");
	printf("%d\n", get_one());
	display();
	is_empoty();
	is_full();

	printf("\n查找20\n");
	search(20);

	printf("\n查找10\n");
	search(10);

	printf("\n清空\n");
	display();
	is_empoty();
	is_full();


	return 0;
}
