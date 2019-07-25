// ConsoleApplication24.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//二叉树

#include <stdio.h>
#include <stdlib.h>

typedef struct Node;

typedef int Element;

//树
typedef struct Tree
{
	Node* root;
} Tree;

//树节点
typedef struct Node
{
	Element data;

	Tree left;

	Tree right;

} Node;

//清空树
void ClearTree(Tree* p) {
	if (p==NULL)
	{
		return;
	}
	if (p->root != NULL)
	{
		//清空左子树
		ClearTree(&(p->root->left));

		//清空右子树
		ClearTree(&(p->root->right));

		//释放空间
		free(p->root);

		//节点指针置为NULL
		p->root = NULL;
	}
}


//初始化
void InitTree(Tree* p) {
	//指针判空
	if (p==NULL)
	{
		return;
	}
	ClearTree(p);
}

//查找  Tree.Node==NULL
Tree* SearchTree(const Tree* p,const Element value) {
	//指针判空
	if (p == NULL)
	{
		return NULL;
	}

	//空树，直接返回这个树的地址
	if (p->root==NULL)
	{
		return (Tree*)p;
	}
	//value小于当前节点值
	else if (p->root->data>value)
	{
		return SearchTree(&(p->root->left), value);
	}
	else if (p->root->data<value)
	{
		return SearchTree(&(p->root->right), value);
	}
	else
	{
		//p->root不是NULL
		return (Tree*)p;
	}

}

//插入
void InsertTree(Tree* p, const Element data) {
	if (p==NULL)
	{
		return;
	}

	//临时指针变量记录查找出来的位置
	Tree* index = SearchTree(p, data);

	//如果找到的位置已经有值
	if (index->root!=NULL)
	{
		printf("插入的值在当前二叉树中已经存在\n");
		return;
	}
	else
	{
		//创建一个新的树形节点空间
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->left.root = NULL;
		node->right.root = NULL;

		index->root = node;
		
	}

}

//遍历（前中后)
//前序遍历   中左右
void PreorderTraversal(const Tree tree) {

	//树为空
	if (tree.root==NULL)
	{
		return;
	}


	//打印中
	printf("%d ", tree.root->data);

	//打印左
	PreorderTraversal(tree.root->left);

	//打印右
	PreorderTraversal(tree.root->right);


}

//中序遍历  左中右
void IntermediateTraversal(const Tree tree) {
	//树为空
	if (tree.root == NULL)
	{
		return;
	}

	IntermediateTraversal(tree.root->left);

	printf("%d ", tree.root->data);

	IntermediateTraversal(tree.root->right);

}

//后序遍历  左右中
void PostorderTraversal(const Tree tree) {
	//树为空
	if (tree.root == NULL)
	{
		return;
	}
	PostorderTraversal(tree.root->left);

	PostorderTraversal(tree.root->right);

	printf("%d ", tree.root->data);


}

//统计节点个数
int GetCount(const Tree tree) {

	//如果为空返回0
	if (tree.root==NULL)
	{
		return 0;
	}

	return GetCount(tree.root->left) + GetCount(tree.root->right) + 1;

}

//删除
Element DeleteTree(Tree* p, Element value) {
	if (p==NULL)
	{
		return NULL;
	}

	Element res = NULL;

	//找到删除的位置
	Tree* index = SearchTree(p, value);

	Node* temp = index->root;

	//保存删除节点的值
	res = index->root->data;

	int count = GetCount(*index);


	if (count==0)
	{
		printf("删除节点不存在\n");
		return NULL;
	}

	//删除叶子节点
	/*if (count==1)
	{
		free(temp);
		index->root = NULL;
	}*/

		
	if (index->root->left.root!=NULL)
	{
		if (index->root->right.root!=NULL)
		{
			//寻找左子树的最右叶子节点
			Tree* leaf = &(index->root->left);//删除的节点的左子树
			while (leaf->root->right.root!=NULL)
			{
				leaf = &(leaf->root->right);
			}

			//将删除节点的右子树放到删除节点的左节点的最右子节点
			leaf->root->right.root = index->root->right.root;

			//将删除节点赋为删除节点的左节点
			index->root = index->root->left.root;

		}
		else
		{
			//直接将删除节点赋为删除节点的左节点
			index->root = index->root->left.root;
		}
	}
	else
	{
		if (index->root->left.root != NULL)
		{
			//寻找右子树的最左叶子节点
			Tree* leaf = &(index->root->right);//删除的节点的右子树
			while (leaf->root->left.root != NULL)
			{
				leaf = &(leaf->root->left);
			}

			//将删除节点的左子树放到删除节点的右节点的最左子节点
			leaf->root->left.root = index->root->left.root;

			//将删除节点赋为删除节点的右节点
			index->root = index->root->right.root;

		}
		else
		{
			//直接将删除节点赋为删除节点的右节点
			index->root = index->root->right.root;
		}
	}

	//释放节点空间
	free(temp);
	temp = NULL;

	return res;
}

int main()
{

	Tree tree = { 0 };

	InitTree(&tree);

	InsertTree(&tree, 36);
	InsertTree(&tree, 15);
	InsertTree(&tree, 52);
	InsertTree(&tree, 9);
	InsertTree(&tree, 28);
	InsertTree(&tree, 41);
	InsertTree(&tree, 70);
	InsertTree(&tree, 2);
	InsertTree(&tree, 13);
	InsertTree(&tree, 21);
	InsertTree(&tree, 30);
	InsertTree(&tree, 39);
	InsertTree(&tree, 45);
	InsertTree(&tree, 60);
	InsertTree(&tree, 77);

	printf("前序遍历:");
	PreorderTraversal(tree);
	printf("\n中序遍历:");
	IntermediateTraversal(tree);
	printf("\n后序遍历:");
	PostorderTraversal(tree);
	printf("\n-------------------\n");

	printf("二叉树的个数是:%d\n", GetCount(tree));

	int del = 30;

	printf("删除二叉树中的节点为:%d\n", DeleteTree(&tree, del));

	printf("查找二叉树的元素地址是:%p,%d\n",SearchTree(&tree, 15), SearchTree(&tree, 15)->root->data);

	printf("前序遍历:");
	PreorderTraversal(tree);
	printf("\n中序遍历:");
	IntermediateTraversal(tree);
	printf("\n后序遍历:");
	PostorderTraversal(tree);
	printf("\n二叉树的个数是:%d\n", GetCount(tree));
	printf("\n-------------------\n");

    return 0;
}
