/*���л�������ͷ�ļ�*/
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
		*T = (BiTNode * )malloc(sizeof(BiTNode)); /*���������*/
		(*T)->data = c; /*����������������*/
		CreatBiTree(&((*T)->lchild)); /*�ݹ�ش���������*/
		CreatBiTree(&((*T)->rchild)); /*�ݹ�ش���������*/
	}
}

//��������������
int getBitreeDepth(BiTree T)
{
	int leftHeight, rightHeight, maxHeight;//����������������������
	if (T != NULL) //���Ϊ����
	{
		leftHeight = getBitreeDepth(T->lchild);//���������
		rightHeight = getBitreeDepth(T->rchild);//���������
		maxHeight = leftHeight>rightHeight?leftHeight:rightHeight;//������
		return maxHeight+1;//���������=������+1
	}
	else
	{
		return 0;
	}
}

