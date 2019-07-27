
#include "User.h"

//��ʼ��
void initUserList(UserList* p) {
	//ָ���п�
	if (p == NULL)
	{
		//printf("��ʼ������Ϊ��\n");
		return;
	}

	//��ʱָ����������ͷ�˫������֮ǰ���ڵĿռ�
	UserNode* temp = p->head;
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
bool judgeEmpotyUserList(const UserList list) {
	if (list.count == 0)
	{
		//printf("˫����Ϊ��\n");
		return true;
	}
	else
	{
		//printf("˫����Ϊ��\n");
		return false;
	}
}


//����
int insertUser(UserList* p, const const int position, const User user) {
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

	//�����Id�Ѿ�����
	if (searchUserByID(*p, user.ID)!=NULL)
	{
		printf("�û�Id�Ѿ�����\n");
		return 0;
	}

	//�²���Ľڵ�
	UserNode* node = (UserNode*)malloc(sizeof(UserNode));

	node->user = user;
	//node->next = NULL;
	//node->pre = NULL;

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
		UserNode* index = p->head;

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
int deletePositionUserList(UserList* p, const int position) {
	if (p == NULL)
	{
		//printf("ɾ������Ϊ��\n");
		return 0;
	}

	if (judgeEmpotyUserList(*p))
	{
		//printf("˫������Ϊ��,�޷�ɾ��\n");
		return 0;
	}

	if (position < 1 || position > p->count)
	{
		//printf("ɾ����λ�ò�����\n");
		return 0;
	}

	//��¼ɾ����λ��
	UserNode* index = p->head;

	//����ɾ��������
	//int res = 0;

	//˫����ֻ��һ��Ԫ�أ�ֱ���ͷ�ͷ��ͷβ��NULL
	if (p->count == 1)
	{
		//res = p->head->data;

		//�ͷſռ�
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
	}
	//ɾ��֮�󲻿գ�����ɾ����λ���ڵ�һ��
	else if (position == 1 && p->count > 1)
	{
		//res = p->head->data;

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
		//res = p->tail->data;

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
		//res = index->data;

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
	return 1;
}


//����--����ֵ���ң�����ֵ��λ��
int searchUserIndex(const UserList list, const int Id) {
	if (judgeEmpotyUserList(list))
	{
		//printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return 0;
	}

	//��ʱ����������˫�������
	UserNode* temp = list.head;

	int i = 1;

	while (temp != NULL)
	{
		//�ҵ��˷��أ����Ԫ����˫����ĵڼ���
		if (temp->user.ID == Id)
		{
			return i;
		}

		i++;
		temp = temp->next;
	}
	printf("û���ҵ�\n");
	return 0;
}


//����--����ֵ��ѯ���ز��ҵĵ�ַ
User* searchUserByID(const UserList list, const int id) {
	if (judgeEmpotyUserList(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return NULL;
	}

	//��ʱָ����������ҵ��ĵ�ַ
	UserNode* temp = list.head;

	while (temp != NULL)
	{
		if (temp->user.ID == id)
		{
			return &(temp->user);
		}
		//ָ����һ�����ҵ�λ��
		temp = temp->next;
	}

	return NULL;
}

//���
void clearUserList(UserList* p) {
	if (p == NULL)
	{
		printf("���˫����Ĳ���Ϊ��\n");
		return;
	}
	if (judgeEmpotyUserList(*p))
	{
		printf("˫�����Ѿ�Ϊ�գ����������\n");
		return;
	}

	while (p->head != NULL)
	{
		//��ʱ�����������ͷſռ�
		UserNode* temp = p->head;

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
void printUserList(const UserList list) {
	if (judgeEmpotyUserList(list))
	{
		printf("˫����Ϊ�գ�û�п��Դ�ӡ��Ԫ��\n");
		return;
	}

	//��ʱ�����������洢��ӡ�ڵ�
	UserNode* node = (UserNode*)malloc(sizeof(UserNode));

	node = list.head;


	if (list.head != NULL)
	{
		printf("%-10s%-10s%-10s%-10s%-10s\n", "�û�ID", "�û�����", "�û�����", "��ϵ�绰", "�ռ���ַ");
	}

	while (node != NULL)
	{
		printf("%-10d%-10s%-10s%-10s%-10s\n", node->user.ID, node->user.password, node->user.name, node->user.phone, node->user.address);

		//ָ����һ����ӡ�Ľڵ�Ԫ��
		//user = NULL;
		node = node->next;
	}
	printf("\n");
}




//���û���Ϣ���浽�ļ�
void saveAllUserInfo(const UserList list) {
	if (judgeEmpotyUserList(list))
	{
		return;
	}

	FILE* file = fopen("../Order/user.txt", "w");
	if (!file)
	{
		printf("���ļ�ʧ��\n");
		return;
	}

	UserNode* node = list.head;
	while (node!=NULL)
	{
		fprintf(file,"%d\t%s\t%s\t%s\t%s\n",node->user.ID,node->user.password,node->user.name,node->user.phone,node->user.address );
		node = node->next;
	}

	fclose(file);
}



//���ļ��ж�ȡ�û���Ϣ
void getAllUserInfo(UserList* p) {
	if (p==NULL)
	{
		return;
	}
	FILE* file = fopen("../Order/user.txt", "r");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	UserNode* node = p->head = (UserNode*)malloc(sizeof(UserNode));

	while (!feof(file))
	{
		node = (UserNode*)malloc(sizeof(UserNode));
		fscanf(file, "%d\t%s\t%s\t%s\t%s\n", &node->user.ID, node->user.password, node->user.name, node->user.phone, node->user.address);
		if (node->user.ID<1)
		{
			continue;
		}
		insertUser(p, 1, node->user);
	}

	fclose(file);

}


