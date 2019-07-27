
#include "Goods.h"

static int GOODSID = 1;

//��ʼ��
void initGoods(GoodsList* p) {
	// ָ���п�
	if (p == NULL)
	{
		//printf("��ʼ����Ʒ��Ϣ�ĺ����β�Ϊ��\n");

		return;
	}

	/*printf("��������Ʒ���еĳ���:");
	scanf(" %d", &(p->max));

	while (p->max <= 0)
	{
		printf("������������������:");
		scanf(" %d", &(p->max));
	}*/

	// ��ʱָ������������ͷŽ��ռ�
	GoodsNode* temp = p->head;



	// ѭ������������������һ�ͷ�ÿ�����
	while (p->head != NULL)
	{
		// �� ͷָ�� ָ���һ��������һ����㣨�ڶ�����
		p->head = temp->next;

		// �ͷ� temp ��ָ��Ľ�㣬ԭ������ĵ�һ�����
		free(temp);

		// �� temp �ٴ�ָ����һ����Ҫ�ͷŵĽ��
		// �ֵ������һ����㣬ԭ������ڶ������
		temp = p->head;
	}

}



//����������ֵ1:����ɹ�,0:����ʧ��
int insertGoods(GoodsList* p, const Goods goods) {
	if (p == NULL)
	{
		printf("������Ʒ����Ϊ��\n");
		return 0;
	}

	GoodsNode* index = p->head;

	//����Ʒ���浽ָ��ڵ�
	GoodsNode* data = (GoodsNode*)malloc(sizeof(GoodsNode));

	data->goods = goods;
	//�Զ�������ƷID
	data->goods.ID = GOODSID;

	//�������Ϊ�գ����ڵ�һ��λ�ò��룬��Ҫ���⴦��
	if (index == NULL)
	{
		p->head = data;
	}
	else
	{
		//����Ʒ����ĩβ����һ����Ʒ
		while (index->next != NULL)
		{
			index = index->next;
		}

		index->next = data;
	}

	//����ĩβָ����λNULL
	data->next = NULL;


	//��ƷID����
	GOODSID++;

	return 1;

}

//ͨ����ƷIDɾ����Ӧ����Ʒ
int deleteGoodsById(GoodsList* p, const int ID) {
	// ָ���п�
	if (p == NULL)
	{
		printf("ɾ�������β�Ϊ��\n");
		return 0;
	}


	if (ID < 1)
	{
		printf("�������ƷID������\n");
		return 0;
	}

	//һ����ʱ��������ɾ������Ʒ
	GoodsNode* temp = p->head;

	//����ɾ����Ʒ�ڵ��ǰһ���ڵ�
	GoodsNode* pre = temp;

	while (temp->next != NULL && temp->goods.ID != ID)
	{
		pre = temp;
		temp = temp->next;
	}
	if (temp->goods.ID != ID)
	{
		printf("û���ҵ���Ӧ����Ʒ\n");
		return 0;
	}

	//����ڵ�һ��
	if (temp = pre)
	{
		p->head = pre->next;
	}
	else
	{
		pre->next = temp->next;
	}

	free(temp);

	printf("ɾ���ɹ�\n");
	return 1;
}


//ȡ�����еĵ�һ���ڵ�Ԫ��,����ֵ��1��ɾ���ɹ���0��ɾ��ʧ��
int deleteGoods(GoodsList* p) {
	// ָ���п�
	if (p == NULL)
	{
		printf("ȡ�������β�Ϊ��\n");
		return 0;
	}


	//ɾ�����еĵ�һ����Ʒ
	GoodsNode* temp = p->head;

	//ͷָ��ָ��ڶ����ڵ�
	p->head = temp;

	//���ٵ�һ���ڵ�ռ�
	printf("ɾ����Ʒ[��ƷID:%d,��Ʒ����:%s,��Ʒ�۸�:%d]\n", temp->goods.ID, temp->goods.name, temp->goods.price);
	free(temp);


	printf("ɾ���ɹ�\n");
	return 1;
}

//�޸�,����ֵ��1:�޸ĳɹ�,0:�޸�ʧ��
int updateGoodsById(GoodsList* p, Goods goods) {


	//��ʱ������������Ʒ��Ϣ
	GoodsNode* temp = p->head;
	while (temp != NULL)
	{
		if (temp->goods.ID == goods.ID)
		{
			temp->goods = goods;
			printf("�޸ĳɹ�\n");
			return 1;
		}
		temp = temp->next;
	}

	printf("���������ƷID������\n");

	return 0;
}


//����--������ƷID������Ʒ������ֵ��Ʒ
Goods* searchGoodsById(const GoodsList list, int ID) {


	//��ʱ������������Ʒ��Ϣ
	GoodsNode* temp = list.head;
	while (temp != NULL)
	{
		if (temp->goods.ID == ID)
		{
			printf("��ƷID:%d,��Ʒ����:%s,��Ʒ�۸�:%d\n", temp->goods.ID, temp->goods.name, temp->goods.price);
			return &(temp->goods);
		}
		temp = temp->next;
	}

	printf("û���ҵ�\n");
	return NULL;
}


//��ʾ��Ʒ��Ϣ
void displayGoods(const GoodsList list,int* count) {

	//��ʱ��Ʒ�ڵ㱣����Ʒ��Ϣ
	GoodsNode* temp = list.head;

	if (temp!=NULL)
	{
		if (count!=NULL)
		{
			printf("\t%-10s%-10s%-14s%-5s\n", "��ƷID", "��Ʒ����", "��Ʒ�۸�(Ԫ)","����(��)");
		}
		else
		{
			printf("\t%-10s%-10s%-5s\n", "��ƷID","��Ʒ����","��Ʒ�۸�(Ԫ)");
		}
	}
	int i = 0;
	while (temp != NULL)
	{
		if (count!=NULL)
		{
			printf("\t%-10d%-10s%-14d%-5d\n", temp->goods.ID, temp->goods.name, temp->goods.price,count[i]);
			i++;
			temp = temp->next;
		}
		else
		{
			//printf("��ƷID:%d,��Ʒ����:%s,��Ʒ�۸�:%d\n", temp->goods.ID, temp->goods.name, temp->goods.price);
			printf("\t%-10d%-10s%-5d\n", temp->goods.ID, temp->goods.name, temp->goods.price);
			temp = temp->next;
		}
		
		

	}
}



//���
void clearGoods(GoodsList* p) {
	// ָ���п�
	if (p == NULL)
	{
		printf("��պ����β�Ϊ��\n");
		return;
	}


	// ��ʱָ������������ͷŽ��ռ�
	GoodsNode* temp = p->head;

	// ѭ������������������һ�ͷ�ÿ�����
	while (p->head != NULL)
	{
		// ��ͷָ��ָ���һ��������һ����㣨�ڶ�����
		//p->head = p->head->next;
		p->head = temp->next;

		// �ͷ� temp ��ָ��Ľ�㣬ԭ������ĵ�һ�����
		free(temp);

		// �� temp �ٴ�ָ����һ����Ҫ�ͷŵĽ��
		temp = p->head;
	}

}

//����Ʒ��Ϣ���浽�ļ�
void saveGoods(const GoodsList list) {
	FILE* file = fopen("../Order/goods.txt", "w");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	//������Ʒ�Ľڵ�
	GoodsNode* node = list.head;

	//ѭ��������ÿһ����Ʒд���ļ�
	while (node != NULL)
	{
		fprintf(file, "%d\t%s\t\%d\n", node->goods.ID, node->goods.name, node->goods.price);
		node = node->next;
	}

	printf("��Ʒ����ɹ�\n");

	//�ļ��ر�
	fclose(file);
}


//���ļ��е���Ʒ��ȡ������
void getGoodsData(GoodsList* p) {
	FILE* file = fopen("../Order/goods.txt", "r");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	GoodsNode* temp = NULL;

	//ͷ������⴦��
	GoodsNode* index;

	p->head = index = (GoodsNode*)malloc(sizeof(GoodsNode));

	fscanf(file, "%d\t%s\t\%d\n", &index->goods.ID, &index->goods.name, &index->goods.price);
	if (index->goods.ID < 1)
	{
		printf("�ļ�Ϊ��\n");
		return;
	}
	GOODSID++;

	//���ļ����ݶ�ȡ����
	while (!feof(file))
	{
		//û��ȡһ����Ʒ����ƷID��1
		GOODSID++;

		temp = (GoodsNode*)malloc(sizeof(GoodsNode));

		fscanf(file, "%d\t%s\t\%d\n", &temp->goods.ID, &temp->goods.name, &temp->goods.price);
		index->next = temp;

		index = index->next;

	}

	//����ĩβ��λNULL
	temp->next = NULL;


	//�ر��ļ�
	fclose(file);
}