#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct User
{
	//用户ID
	//int ID;


	//用户姓名
	char name[50];

	//用户密码
	char password[9];



	//联系电话
	//char phone[20];


	//收件地址
	//char address[50];

} User;

typedef struct UserNode
{
	User user;
	UserNode* next;
	UserNode* pre;

}UserNode;

typedef struct UserList
{
	//头指针
	UserNode* head;

	//尾指针
	UserNode* tail;

	int count;

}UserList;



//初始化
void initUserList(UserList* p);


//判空
bool judgeEmpotyUserList(const UserList list);


//插入
int insertUser(UserList* p, const const int position, const User user);


//删除--根据位置删除
int deletePositionUserList(UserList* p, const int position);


//查找--根据值查找，返回值的位置
int searchUserIndex(const UserList list, const char* name);


//查找--按照值查询返回查找的地址
User* searchUserByID(const UserList list, const char* name);

//清空
void clearUserList(UserList* p);


//打印
void printUserList(const UserList list);



//将用户信息保存到文件
void saveAllUserInfo(const UserList list);



//从文件中读取用户信息
void getAllUserInfo(UserList* p);

bool cmp(const char* s1, const char* s2);