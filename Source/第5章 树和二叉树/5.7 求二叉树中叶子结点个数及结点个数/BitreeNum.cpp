#include "BitreeNum.h" 
//创建树
void CreateBiTree(BiTree &T)
{
	char ch;
	cin>>ch;
	if(ch == '#')
	{
		T = NULL;
		return;
	}		
	T = (BiTNode*)malloc(sizeof(BiTNode));
	T->data = ch;
	CreateBiTree(T->lchild);
	CreateBiTree(T->rchild);
}

//计算树中的叶子节点数
int LeafCount(BiTree T)
{
	if(NULL == T)
	{
		return 0;
	}
	else
	{
		if(NULL == T->lchild && NULL == T->rchild)
		{
			return 1;
		}
		else
		{
			return LeafCount(T->lchild) + LeafCount(T->rchild);
		}
	}
}

//树的节点个数
int Nodes(BiTree T)
{
	if(NULL == T)
		return 0;
	else
	{
		if(NULL == T->lchild && NULL == T->rchild)
			return 1;
		else
		{
			return Nodes(T->lchild) + Nodes(T->rchild) + 1;
		}
	}
}

