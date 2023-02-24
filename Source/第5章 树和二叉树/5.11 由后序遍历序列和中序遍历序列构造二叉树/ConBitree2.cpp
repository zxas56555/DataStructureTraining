#include"ConBitree2.h" 
#include <bits/stdc++.h>

using namespace std;

void CreateBiTree(BiTree *T, char *in, char *post, int len);
void PrintLevel(BiTree T);
void PreTraverse(BiTree T);
void PrintLevel(BiTree T)
{
	BiTree Queue[MAXSIZE];
	int front, rear;
	if (T==NULL)
	{
		return;
	}
	front = -1;
	rear = 0;
	Queue[rear] = T;
	while (front!=rear)
	{
		front++;
		printf("%4c",Queue[front]->data);
		if (Queue[front]->lchild!=NULL)
		{
			rear++;
			Queue[rear] = Queue[front]->lchild;
		}
		if (Queue[front]->rchild!=NULL)
		{
			rear++;
			Queue[rear] = Queue[front]->rchild;
		}
	}
}
void PreTraverse(BiTree T)
{
	if (T!=NULL)
	{
		printf("%4c", T->data);
		PreTraverse(T->lchild);
		PreTraverse(T->rchild);
	}
}
void CreateBiTree(BiTree *T, char *in, char *post, int len)
{
	int k;
	char *temp;
	if (len<=0)
	{
		*T = NULL;
		return;
	}
	for (temp = in; temp < in + len;temp++)
	{
		if (*(post+len-1)==*temp)
		{
			k = temp - in;
			(*T) = (BitNode *)malloc(sizeof(BitNode));
			(*T)->data = *temp;
			break;
		}
	}
	CreateBiTree(&((*T)->lchild), in, post, k);
	CreateBiTree(&((*T)->rchild), in + k + 1, post + k, len - k - 1);
}
void TreePrint(BiTree T, int level)
{
	int i;
	if (T==NULL)
	{
		return;
	}
	TreePrint(T->rchild, level + 1);
	for (i = 0; i < level;i++)
	{
		printf("    ");
	}
	printf("%c\n", T->data);
	TreePrint(T->lchild, level + 1);
}

