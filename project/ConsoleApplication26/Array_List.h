#pragma once


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 100//数字的大小

typedef int Element;//数组保存的元素类型

typedef struct ArrayList
{
	//保存数据
	Element arr[SIZE];


	//有效元素
	int count;

}ArrayList;




//初始化全部赋值为0
void initArrayList(ArrayList* p);

//判断是否为空
int isEmpoty(const ArrayList array);

//判满
int isFull(const ArrayList array);

//放入,在数组的第position个位置放入value
void insertArrayList(ArrayList*p,const int position,const Element value);

//取出,取出数组中的第position个位置的值
Element getArrayList(ArrayList* p, const int position);

//清空
void clearArrayList(ArrayList* p);

//打印
void printArrayList(const ArrayList array);

//查找
Element searchArrayList(const ArrayList array, const Element value);

