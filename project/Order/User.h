#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct User
{
	//�û�ID
	//int ID;


	//�û�����
	char name[50];

	//�û�����
	char password[9];



	//��ϵ�绰
	//char phone[20];


	//�ռ���ַ
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
	//ͷָ��
	UserNode* head;

	//βָ��
	UserNode* tail;

	int count;

}UserList;



//��ʼ��
void initUserList(UserList* p);


//�п�
bool judgeEmpotyUserList(const UserList list);


//����
int insertUser(UserList* p, const const int position, const User user);


//ɾ��--����λ��ɾ��
int deletePositionUserList(UserList* p, const int position);


//����--����ֵ���ң�����ֵ��λ��
int searchUserIndex(const UserList list, const char* name);


//����--����ֵ��ѯ���ز��ҵĵ�ַ
User* searchUserByID(const UserList list, const char* name);

//���
void clearUserList(UserList* p);


//��ӡ
void printUserList(const UserList list);



//���û���Ϣ���浽�ļ�
void saveAllUserInfo(const UserList list);



//���ļ��ж�ȡ�û���Ϣ
void getAllUserInfo(UserList* p);

bool cmp(const char* s1, const char* s2);