

#include "Array_List.h"

//��ʼ��ȫ����ֵΪ0
void initArrayList(ArrayList* p) {
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < SIZE; i++)
	{
		p->arr[i] = NULL;
	}


	//��ЧԪ����Ϊ0
	p->count = 0;

}

//�ж��Ƿ�Ϊ��
int isEmpoty(const ArrayList array) {
	if (array.count == 0)
	{
		//printf("����Ϊ��!!\n");
		return 1;
	}
	else
	{
		//printf("���鲻Ϊ��!!\n");
		return 0;
	}
}

//����
int isFull(const ArrayList array) {
	if (array.count == SIZE)
	{
		//printf("��������!!\n");
		return 1;
	}
	else
	{
		//printf("����δ��!!\n");
		return 0;
	}
}

//����,������ĵ�position��λ�÷���value
void insertArrayList(ArrayList* p, const int position, const Element value) {
	if (isFull(*p))
	{
		return;
	}
	if (position<1 || position>p->count + 1)
	{
		printf("����λ�ò�����\n");
		return;
	}

	if (p->count != 0)
	{
		int i = p->count;
		//���������ƶ�
		for (i; i >= position - 1; i--)
		{
			p->arr[i] = p->arr[i - 1];
		}
	}

	//�ڵ�position��λ�ø�ֵ
	p->arr[position - 1] = value;

	//��ЧԪ�ؼ�1
	p->count++;
}

//ȡ��,ȡ�������еĵ�position��λ�õ�ֵ
Element getArrayList(ArrayList* p, const int position) {
	if (isEmpoty(*p))
	{
		return NULL;
	}

	if (position<1 || position>p->count + 1)
	{
		//printf("ȡ��λ�ò�����\n");
		return NULL;
	}

	//�����position��λ�õ�ֵ
	Element res = p->arr[position - 1];

	int i = position - 1;


	//����ǰ��
	for (i; i < p->count; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}

	p->count--;
	return res;
}

//���
void clearArrayList(ArrayList* p) {
	if (isEmpoty(*p))
	{
		return;
	}
	initArrayList(p);
}

//��ӡ
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

//����
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
