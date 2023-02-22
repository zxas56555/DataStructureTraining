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
    /*获得前序遍历的第一个结点*/ 
    ElemType c = preOrder[0];
    /*创建根结点*/
    BiNode<ElemType> *node = new BiNode<ElemType>;
    node->data = c;
    node->lchild = NULL;
    node->rchild = NULL;
    int i;
    /*在中序遍历序列中寻找根结点的位置*/
    for(i = 0; i < n && inOrder[i] != c; i++)
		;
	/*左子树结点个数*/ 
    int lenLeft = i;
    /*右子树结点个数*/
    int lenRight = n - i - 1;
    /*左子树不为空，递归重建左子树*/ 
    if(lenLeft > 0)
        node->lchild = Rebuild(&preOrder[1], &inOrder[0], lenLeft);
    /*右子树不为空，递归重建右子树*/
    if(lenRight > 0)
        node->rchild = Rebuild(&preOrder[lenLeft+1], &inOrder[lenLeft+1], lenRight);
    return node;
}
