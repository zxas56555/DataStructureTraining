/*队列基本操作头文件*/
#include <bits/stdc++.h>
#include"Depth.h"

void CreatBiTree(BiTree *T)
{

	char c;
	cin>>c;
	if(c == '#') 
		*T = NULL;
	else
	{
		*T = (BiTNode * )malloc(sizeof(BiTNode)); /*创建根结点*/
		(*T)->data = c; /*向根结点中输入数据*/
		CreatBiTree(&((*T)->lchild)); /*递归地创建左子树*/
		CreatBiTree(&((*T)->rchild)); /*递归地创建右子树*/
	}
}

//计算二叉树的深度
int getBitreeDepth(BiTree T)
{
	int leftHeight, rightHeight, maxHeight;//左子树，右子树，最大深度
	if (T != NULL) //如果为空树
	{
		leftHeight = getBitreeDepth(T->lchild);//左子树深度
		rightHeight = getBitreeDepth(T->rchild);//右子树深度
		maxHeight = leftHeight>rightHeight?leftHeight:rightHeight;//最大深度
		return maxHeight+1;//二叉树深度=最大深度+1
	}
	else
	{
		return 0;
	}
}

