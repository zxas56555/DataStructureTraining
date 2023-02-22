#include <iostream>
using namespace std;
#include "BiTree.h"

template <class ElemType>
void BiTree<ElemType>::PostOrder(BiNode<ElemType> *bt) {
	if(bt == NULL)
		return;
	PostOrder(bt->lchild);
	PostOrder(bt->rchild);
	cout<<bt->data<<" ";
}

template <class ElemType>
void BiTree<ElemType>::PreOrder(BiNode<ElemType> *bt) {
	if(bt == NULL)
		return;
	cout<<bt->data<<" ";
	PreOrder(bt->lchild);
	PreOrder(bt->rchild);
}

template <class ElemType>
void BiTree<ElemType>::InOrder(BiNode<ElemType> *bt) {
	if(bt == NULL)
		return;
	InOrder(bt->lchild);
	cout<<bt->data<<" ";
	InOrder(bt->rchild);	
}

template <class ElemType>
BiNode<ElemType>* BiTree<ElemType>::Rebuild(ElemType *preOrder, ElemType *inOrder, int n) {
    if(n == 0) 
		return NULL;
    /*���ǰ������ĵ�һ�����*/ 
    ElemType c = preOrder[0];
    /*���������*/
    BiNode<ElemType> *node = new BiNode<ElemType>;
    node->data = c;
    node->lchild = NULL;
    node->rchild = NULL;
    int i;
    /*���������������Ѱ�Ҹ�����λ��*/
    for(i = 0; i < n && inOrder[i] != c; i++)
		;
	/*������������*/ 
    int lenLeft = i;
    /*������������*/
    int lenRight = n - i - 1;
    /*��������Ϊ�գ��ݹ��ؽ�������*/ 
    if(lenLeft > 0)
        node->lchild = Rebuild(&preOrder[1], &inOrder[0], lenLeft);
    /*��������Ϊ�գ��ݹ��ؽ�������*/
    if(lenRight > 0)
        node->rchild = Rebuild(&preOrder[lenLeft+1], &inOrder[lenLeft+1], lenRight);
    return node;
}
