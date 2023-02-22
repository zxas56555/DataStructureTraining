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
BiNode<ElemType>* BiTree<ElemType>::Rebuild(ElemType *postOrder, ElemType *inOrder, int n) {
    if(n == 0) 
		return NULL;
    /*��ú�����������һ�����*/ 
    ElemType c = postOrder[n-1];
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
    /*��������Ϊ�գ��ؽ�������*/ 
    if(lenLeft > 0)
        node->lchild = Rebuild(&postOrder[0], &inOrder[0], lenLeft);
    /*��������Ϊ�գ��ؽ�������*/
    if(lenRight > 0)
        node->rchild = Rebuild(&postOrder[lenLeft], &inOrder[lenLeft+1], lenRight);
    return node;
}
