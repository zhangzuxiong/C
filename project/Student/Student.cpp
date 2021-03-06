﻿// Student.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//链表实现动态内存管理，学生信息保存到文件，每次启动时读取文件

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{

	//学号
	int ID;

	//年龄
	int age;

	//姓名
	char name[21];

	//邮箱
	char email[21];

	//指向下一个学生
	Student* next;
} Student;

typedef struct List
{
	//头指针
	Student* head;

	//学生个数
	int count;
} List;

//初始化
int init(List* p);

//判断是否为空
int is_empoty(const List list);

//插入学生
int insert_stu(List* p);

//修改学生信息
int update_stu(List* p, const int ID);

//删除学生
int delete_stu(List* p, const int ID);

//查找学生
int search_stu(const List list,const int ID);

//显示所有学生信息
int display_stu(const List list);

//将学生信息写入文件
int write_file(const List list);

//读取文件
int read_file(List* p);



int main()
{
	List students = { 0 };
	init(&students);
	//加载已经存在的学生，读取文件数据
	read_file(&students);

	int flag = 1;

	while (flag)
	{
		printf("\n=================欢迎进入学生信息管理系统============\n");
		printf("\t\t 0.退出系统\n");
		printf("\t\t 1.录入学生信息\n");
		printf("\t\t 2.查询学生信息\n");
		printf("\t\t 3.删除学生信息\n");
		printf("\t\t 4.修改学生信息\n");
		printf("\t\t 5.显示所有学生信息\n");
		printf("请选择:");
		
		scanf(" %d", &flag);
		printf("\n");
		
		int id = 0;
		int count = 0;

		switch (flag)
		{
		case 1:

			printf("请输入录入学生的个数:");
			scanf(" %d", &count);
			while (count>0)
			{
				insert_stu(&students);
				count-- ;
			}

			break;


		case 2:
			printf("请输入需要查询的学生的学号:");
			scanf(" %d", &id);
			search_stu(students, id);
			break;

		case 3:
			printf("请输入需要删除学生的学号:");
			scanf(" %d", &id);
			delete_stu(&students, id);
			break;
			
		case 4:
			printf("请输入需要修改学生的学号:");
			scanf(" %d", &id);
			update_stu(&students, id);
			break;
			
		case 5:
			display_stu(students);
			break;

		case 0:
			write_file(students);
			break;

		default:
			printf("输入有误\n");
			break;
		}
	}

    return 0;
}

//将学生信息写入文件
int write_file(const List list) {

	FILE* fp;//文件指针 
	Student* p;

	fp = fopen("student.txt", "w");
	if (!fp)
	{
		printf("文件打开错误！");
		return -1;
	}

	// 写在文件最上方第一行的内容就是一共有多少个学生的信息 
	//fprintf(fp, "%d\n", list.count);

	// 循环遍历内存中的数据结构（单链表）
	for (p = list.head; p != NULL; p = p->next)
	{
		// 将链表的每个结点的内容，按照标准输入的格式输入到文件中
		fprintf(fp, "%d\t%s\t%d\t%s\n",
			p->ID, p->name, p->age,p->email);
	}

	// 关闭文件
	fclose(fp);

	return 0;
}

//读取文件
int read_file(List* p) {

	FILE* fp;//文件指针 
	Student* p1;
	Student* p2;

	// 打开文件，读取的方式
	fp = fopen("student.txt", "r");
	if (!fp)
	{
		printf("文件打开错误！");
		return -1;
	}

	// 从文件的第一行，获取学生信息的个数
	//fscanf(fp, "%d\n", &(p->count));

	// 新建的结构体空间，之后会用来保存从文件中读取的一个学生信息的结构体内容
	p->head = p1 = p2 = (Student*)malloc(sizeof(Student));

	// 链表新建第一个结点的操作，单独处理
	fscanf(fp, "%d\t%s\t%d\t%s\n",
		&p1->ID, p1->name, &p1->age, p1->email);
	if (p1->ID<0)
	{
		//文件为空
		return 0;
	}
	p->count++;

	// 循环遍历文件，按学生信息类型的结构体取出对应的数据内容，赋值给新的结构体变量（在堆上新创建的结点）
	while (!feof(fp))
	{
		// 在堆上新建一个学生信息类型的结构体变量（新的结点）
		p1 = (Student*)malloc(sizeof(Student));

		// 从文件中读取一个学生信息类型的结构体内容，放入到刚才新建的学生信息类型的结构体变量中
		fscanf(fp, "%d\t%s\t%d\t%s\n",
			&p1->ID, p1->name, &p1->age, p1->email);

		// 将新建结点 关联到链表的末尾
		p2->next = p1;

		// 获取新链表末尾
		p2 = p1;

		p->count++;
	}

	// 将最后一个结点的 向后指针 置为空
	p2->next = NULL;

	// 关闭文件
	fclose(fp);
	return 0;
}


//插入学生
//返回值：-1表示传入的参数为空,1:表示学生添加成功,0表示学生学号已经存在
int insert_stu(List* p) {
	if (p == NULL)
	{
		return -1;
	}

	//创建一个学生，并为学生输入信息
	Student* student = (Student*)malloc(sizeof(Student));
	printf("请输入学生ID:");
	scanf(" %d", &(student->ID));
	printf("请输入学生年龄:");
	scanf(" %d", &(student->age));
	printf("请输入学生姓名:");
	scanf(" %s", &(student->name));
	printf("请输入学生邮箱:");
	scanf(" %s", &(student->email));

	printf("学生ID：%d,学生年龄:%d,学生姓名:%s,学生邮箱:%s\n",
		student->ID, student->age, student->name, student->email);

	//临时变量，记录学生应该存放的位置
	Student* index = p->head;

	//记录存放位置的前一个位置
	Student* pre = index;


	//如果链表没有学生
	if (p->count == 0)
	{
		p->head = student;
		student->next = NULL;
		p->count++;
		return 1;
	}



	while (index != NULL && student->ID > index->ID)
	{
		pre = index;
		index = index->next;
	}
	//新加入的节点在头节点，或者链表里面已经存在一个数据
	if (pre == index)
	{
		//学生ID小于头指针元素ID
		if (pre->ID > student->ID)
		{
			p->head = student;
			student->next = index;

			//index->next = NULL;

			p->count++;
			return 1;
		}
		//学生ID大于头指针元素ID
		else if (pre->ID == student->ID)
		{
			printf("您输入的学生学号已经存在\n");
			return 0;
		}
		else
		{
			index->next = student;
			//student->next = NULL;
			p->count++;
			return 1;
		}
	}
	// 1	2	4	5	7
	//如果在末尾插入
	if (index==NULL)
	{
		pre->next = student;
		student->next = NULL;
		return 1;
		p->count++;
	}

	printf("pre->ID:%d index->ID:%d    student->ID:%d\n", pre->ID, index->ID, student->ID);
	if (index->ID==student->ID)
	{
		printf("您输入的学生学号已经存在\n");
		return 0;
	}



	pre->next = student;
	student->next = index;

	p->count++;

	return 1;

}

//查找学生,返回值：-1表示学生信息为空,
//				  0表示没有找到学生，1表示找到学生正常返回
int search_stu(const List list, const int ID) {
	if (is_empoty(list))
	{
		return -1;
	}

	//记录查找的学生
	Student* student = list.head;

	while (student != NULL && student->ID < ID)
	{
		student = student->next;
	}

	if (student == NULL)
	{
		printf("没有找到您输入的ID对应的学生\n");
		return 0;
	}

	printf("学生ID：%d,学生年龄:%d,学生姓名:%s,学生邮箱:%s\n",
		student->ID, student->age, student->name, student->email);

	return 1;

}

//修改学生信息
int update_stu(List* p, const int ID) {

	if (p == NULL)
	{
		return -1;
	}
	if (is_empoty(*p))
	{
		return -2;
	}

	//记录修改的学生
	Student* index = p->head;


	while (index != NULL && index->ID != ID)
	{
		index = index->next;
	}


	if (index == NULL)
	{
		printf("您想要修改的学生不存在\n");
		return -3;
	}


	printf("请输入学生新的年龄:");
	scanf(" %d", &(index->age));
	printf("请输入学生新的姓名:");
	scanf(" %s", &(index->name));
	printf("请输入学生新的邮箱:");
	scanf(" %s", &(index->email));

	printf("修改成功\n");
	return 1;
}

//删除学生,返回值：-1表示传入参数为空，-2表示学生信息为空,
//				  -3表示没有找到学生，1表示删除成功正常返回
int delete_stu(List* p, const int ID) {

	if (p==NULL)
	{
		return -1;
	}
	if (is_empoty(*p))
	{
		return -2;
	}

	//记录删除的学生
	Student* index = p->head;

	//记录删除学生的前一个学生
	Student* pre = index;

	while (index!=NULL&&index->ID!=ID)
	{
		pre = index;
		index = index->next;
	}


	if (index==NULL)
	{
		printf("您想要删除的学生不存在\n");
		return -3;
	}

	//如果删除的位置在第一个
	if (pre==index)
	{
		p->head = index->next;

		free(index);
		//index = NULL;
	}
	if (pre!=index)
	{
		pre->next = index->next;

		free(index);
		//index = NULL;
	}
	p->count--;
	printf("删除成功\n");
	return 1;
}


//显示所有学生信息.返回值：-1表示学生信息为空,1表示正常返回
int display_stu(const List list) {
	if (is_empoty(list))
	{
		return -1;
	}

	//临时变量保存一个学生信息
	Student* stu = list.head;

	while (stu!=NULL)
	{
		printf("学生ID：%d,学生年龄:%d,学生姓名:%s,学生邮箱:%s\n",
			stu->ID, stu->age, stu->name, stu->email);
		stu = stu->next;
	}

	return 1;
}



//判断是否为空,
//返回值：1表示学生信息为空，0表示学生信息不为空
int is_empoty(const List list) {
	if (list.count==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//初始化
//返回值：-1表示传入的参数为NULL，1表示初始化成功
int init(List* p) {
	if (p == NULL)
	{
		printf("初始化参数为空\n");
		return -1;
	}

	//临时指针变量，释放空间
	Student* temp = p->head;
	while (p->head != NULL)
	{
		p->head = temp->next;
		free(temp);

		//将temp指向下一个释放的节点
		temp = p->head;
	}
	p->count = 0;
	return 1;
}
