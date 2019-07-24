

#include "Double_Linked_List.h"

//��ʼ��
void init_Double_Linked_List(DL_List* p) {
	//ָ���п�
	if (p == NULL)
	{
		printf("��ʼ������Ϊ��\n");
		return;
	}

	//��ʱָ����������ͷ�˫������֮ǰ���ڵĿռ�
	Node* temp = p->head;
	while (p->head != NULL)
	{
		//��ͷ�����ƶ�һ��
		p->head = temp->next;

		//�ͷſռ�
		free(temp);

		//ָ����һ���ͷŵĿռ�
		temp = p->head;
	}

	//βָ����λNULL
	p->tail = NULL;

	//��ЧԪ����λ0
	p->count = 0;

}


//�п�
bool judge_Empoty_Double_Linked_List(const DL_List list) {
	if (list.count == 0)
	{
		printf("˫����Ϊ��\n");
		return true;
	}
	else
	{
		printf("˫����Ϊ��\n");
		return false;
	}
}


//���룬�ڵ�position��λ�ò���һ����num
int insert_Position_Double_Linked_List(DL_List* p, const const int position, const int num) {
	if (p == NULL)
	{
		printf("����˫����Ĳ���Ϊ��\n");
		return 0;
	}

	if (position < 1 || position > p->count + 1)
	{
		printf("����λ�ò�����\n");
		return 0;
	}

	//�²���Ľڵ�
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = num;

	//����Ϊ��
	if (p->count == 0)
	{
		//�½ڵ����ͷ���Ҳ��β���
		p->head = node;
		p->tail = node;

		//ͷ������һ����β����ǰһ����ΪNULL
		p->head->next = NULL;
		p->tail->pre = NULL;
	}
	//����ǿգ���ͷ��β����
	else if (p->count != 0 && (position == 1 || position == p->count + 1))
	{
		//��ͷ����
		if (position == 1)
		{
			//�½ڵ����һ���ڵ�Ϊͷ���
			node->next = p->head;

			//�½ڵ��ǰһ���ڵ���ͷ����ǰһ���ڵ㣨NULL��
			node->pre = p->head->pre;

			//ͷ�ڵ��ǰһ���ڵ����½ڵ�
			p->head->pre = node;

			//���½ڵ�����Ϊ�µ�ͷ���
			p->head = node;
		}
		//��β����
		else
		{
			//�½ڵ����һ���ڵ�Ϊβ������һ���ڵ㣨NULL��
			node->next = p->tail->next;

			//�½ڵ��ǰһ���ڵ���β���
			node->pre = p->tail;

			//β������һ���ڵ����½ڵ�
			p->tail->next = node;

			//���½ڵ�����Ϊ�µ�β���
			p->tail = node;
		}
	}
	//���м����
	else
	{
		//��¼�����λ��
		Node* index = p->head;

		//ѭ�����������ҵ������λ��
		int i = 1;
		while (i < position)
		{
			index = index->next;
			i++;
		}
		//�ȸı�next����Ϊ2��
		//1.�½ڵ����һ��ָ��index��λ��
		node->next = index;

		//2.����λ�õ�ǰһ��ָ���½ڵ�
		index->pre->next = node;


		//�ٸı�pre,��Ϊ2��
		//1.�½ڵ��ǰһ��ָ�����ڵ��ǰһ��
		node->pre = index->pre;

		//2.����λ�õ�ǰһ��ָ���½ڵ�
		index->pre = node;
	}

	//��ЧԪ�ؼ�1
	p->count++;

	return 1;
}


//ɾ��--����λ��ɾ��
int delete_Position_Double_Linked_List(DL_List* p, const int position) {
	if (p == NULL)
	{
		printf("ɾ������Ϊ��\n");
		return 0;
	}

	if (judge_Empoty_Double_Linked_List(*p))
	{
		printf("˫������Ϊ��,�޷�ɾ��\n");
		return 0;
	}

	if (position < 1 || position > p->count)
	{
		printf("ɾ����λ�ò�����\n");
		return 0;
	}

	//��¼ɾ����λ��
	Node* index = p->head;

	//����ɾ��������
	int res = 0;

	//˫����ֻ��һ��Ԫ�أ�ֱ���ͷ�ͷ��ͷβ��NULL
	if (p->count == 1)
	{
		res = p->head->data;

		//�ͷſռ�
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
	}
	//ɾ��֮�󲻿գ�����ɾ����λ���ڵ�һ��
	else if (position == 1 && p->count > 1)
	{
		res = p->head->data;

		//��head����ƶ�һ��
		p->head = index->next;

		free(index);

		index = NULL;

		//�½ڵ��ǰһ���ڵ���λNULL
		p->head->pre = NULL;

		/*

		//ͷ��������ƶ�һ����Ϊ�µ�ͷ�ڵ�
		p->head = p->head->next;

		//�ͷžɵ�ͷ�ڵ�
		free(p->head->pre);

		//�µ�ͷ����preΪNULL
		p->head->pre = NULL;

		*/
	}
	//ɾ�����һ��������˫������ЧԪ�ش���1��
	else if (position == p->count && p->count > 1)
	{
		res = p->tail->data;

		//��tail��ǰ�ƶ�һ��
		p->tail = p->tail->pre;

		//��ĩβ��ǰһ����next��λNULL��Ȼ���ͷ�ԭ�����ĩβ�ڵ�
		free(p->tail->next);
		p->tail->next = NULL;
	}
	//ɾ�����м�
	else
	{
		//ѭ�����������ҵ�ɾ����λ��
		int i = 1;
		while (i < position)
		{
			index = index->next;
			i++;
		}
		res = index->data;

		//��ǰɾ���ڵ��ǰһ���ڵ�nextָ��ɾ���ڵ��next
		index->pre->next = index->next;

		//��ǰɾ���ڵ�next��preָ��index��pre
		index->next->pre = index->pre;

		//�ͷſռ�
		free(index);
	}

	//��ЧԪ�ؼ�1
	p->count--;
	printf("ɾ���ɹ�\n");
	return res;
}


//����--����ֵ���ң�����ֵ��λ��
int search_Value_Double_Linked_List(const DL_List list, const int num) {
	if (judge_Empoty_Double_Linked_List(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return 0;
	}

	//��ʱ����������˫�������
	Node* temp = list.head;

	int i = 1;

	while (temp != NULL)
	{
		//�ҵ��˷��أ����Ԫ����˫����ĵڼ���
		if (temp->data == num)
		{
			return i;
		}

		i++;
		temp = temp->next;
	}
	printf("û���ҵ�\n");
	return 0;
}

//����--����λ�ò��ң��������λ�õ�ֵ
int search_Position_Double_Linked_List(const DL_List list, const int position) {
	if (judge_Empoty_Double_Linked_List(list))
	{
		printf("˫������Ϊ��,�޷�����\n");
		return 0;
	}

	if (position < 1 || position > list.count)
	{
		printf("���ҵ�λ�ò�����\n");
		return 0;
	}

	//��ʱ������ѭ������˫����
	Node* temp = list.head;
	int i = 1;
	while (i < position)
	{
		temp = temp->next;
		i++;
	}

	return temp->data;
}

//����--����λ�ò������λ�õĵ�ַ
Node* search_Position_Return_Address_Single_Linked_List(const DL_List list, const int position) {
	if (judge_Empoty_Double_Linked_List(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return NULL;
	}

	if (position < 1 || position > list.count)
	{
		printf("���ҵ�λ�ò�����\n");
		return NULL;
	}

	//��ʱ������ѭ������˫����
	Node* temp = list.head;
	int i = 1;
	while (i < position)
	{
		temp = temp->next;
		i++;
	}

	return temp;
}


//����--����ֵ��ѯ���ز��ҵĵ�ַ
Node* search_Value_Return_Address_Single_Linked_List(const DL_List list, const int value) {
	if (judge_Empoty_Double_Linked_List(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return NULL;
	}

	//��ʱָ����������ҵ��ĵ�ַ
	Node* temp = list.head;

	while (temp != NULL)
	{
		if (temp->data == value)
		{
			return temp;
		}
		//ָ����һ�����ҵ�λ��
		temp = temp->next;
	}

	return NULL;
}

//���
void clear_Double_Linked_List(DL_List* p) {
	if (p == NULL)
	{
		printf("���˫����Ĳ���Ϊ��\n");
		return;
	}
	if (judge_Empoty_Double_Linked_List(*p))
	{
		printf("˫�����Ѿ�Ϊ�գ����������\n");
		return;
	}

	while (p->head != NULL)
	{
		//��ʱ�����������ͷſռ�
		Node* temp = p->head;

		//ͷָ�������ƶ�һ��
		p->head = temp->next;

		//�ͷſռ�
		free(temp);

		temp = NULL;

	}

	//βָ����ΪNULL
	p->tail = NULL;

	//��ЧԪ����Ϊ0
	p->count = 0;
}


//��ӡ
void print_Double_Linked_List(const DL_List list) {
	if (judge_Empoty_Double_Linked_List(list))
	{
		printf("˫����Ϊ�գ�û�п��Դ�ӡ��Ԫ��\n");
		return;
	}

	//��ʱ�����������洢��ӡ�ڵ�
	Node* temp = list.head;

	while (temp != NULL)
	{
		printf("%d  ", temp->data);

		//ָ����һ����ӡ�Ľڵ�Ԫ��
		temp = temp->next;
	}
	printf("\n");
}
