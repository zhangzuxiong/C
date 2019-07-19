// ConsoleApplication6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
	//学号
	int ID = 0;

	//姓名
	char name[21] = { 0 };

	//年龄
	int age = 0;


	//联系方式
	char phone[12] = { 0 };

} Student;

static int num = 0;


//字符串复制 将source复制给arr
void cp(char source[200], char arr[200]) {
	int i = 0;
	while (source[i] != 0)
	{
		arr[i] = source[i];
		i++;
	}
	arr[i] = '\0';
}

//显示单个学生信息
void display(Student** student) {
	if ((*student)->ID == 0)
	{
		printf("该生不存在");
		return;
	}
	//printf("%p:", student);
	printf(" 学号:%d  姓名:%s  年龄:%d  联系方式:%s\n", (*student)->ID, (*student)->name, (*student)->age, (*student)->phone);
}

//显示所有学生信息
void show(Student** student) {
	if (student == NULL)
	{
		printf("学生不存在!!\n");
		return;
	}
	int i = 0;

	while (i < num)
	{
		if ((student[i])->ID > 0 && (student[i])->ID <= num)
		{
			//printf("%p:", &student[i]);
			printf(" 学号:%d  姓名:%s  年龄:%d  联系方式:%s\n", student[i]->ID, student[i]->name, student[i]->age, student[i]->phone);
		}
		i++;
	}


	printf("------------\n");
	for (i = 0; i < num; i++)
	{
		if ((*student)->ID > 0 && (*student)->ID <= num)
		{
			printf("学号:%d  姓名:%s  年龄:%d  联系方式:%s\n", (*student)->ID, (*student)->name, (*student)->age, (*student)->phone);
		}
		student++;
	}
}


//查找----ID
void search(const Student* student, int ID) {

}


//删除----ID
void remove(Student* student, int ID) {

}


//插入
void insert(Student*** student) {
	int n = 0;
	printf("请输入要录入的学生个数:");
	scanf(" %d", &n);
	*student = (Student * *)malloc(sizeof(Student*) * n);


	int i = 0;
	for (i = 0; i < n; i++)
	{

		(*student)[i] = (Student*)malloc(sizeof(Student));


		(*student)[i]->ID = num + 1;

		printf("请输入姓名:");
		//char name[21] = { 0 };
		scanf(" %s", &((*student)[i]->name));
		//cp(name, student[i]->name);


		printf("请输入年龄:");
		int age = 0;
		scanf(" %d", &age);
		(*student)[i]->age = age;

		printf("请输入联系方式:");
		/*char phone[12] = { 0 };
		scanf("%s", &phone);
		cp(phone, student[i]->phone);*/

		scanf(" %s", &((*student)[i]->phone));

		num++;


		display(&(*student)[i]);

	}
}


int main()
{
	Student** student = NULL;

	insert(&student);

	printf("\n");
	show(student);



	free(student);
	return 0;
}
