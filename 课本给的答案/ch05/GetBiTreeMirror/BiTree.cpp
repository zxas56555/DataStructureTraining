#include <iostream>
using namespace std;
#include "BiTree.h"

template <class ElemType>
BiNode<ElemType> *BiTree<ElemType>::Creat(BiNode<ElemType> *bt) {
	char ch;
	cout<<"请输入创建一棵二叉树的结点数据："<<endl;
	cin>>ch;
	/*'#'代表空二叉树*/
    if(ch == '#') 
		return NULL;
    else { 
		bt = new BiNode<ElemType>; /*生成新结点*/
        bt->data = ch;
        bt->lchild = Creat(bt->lchild); /*递归创建左子树*/
        bt->rchild = Creat(bt->rchild); /*递归创建右子树*/
    } 
    return bt;
}

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
void BiTree<ElemType>::GetMirror(BiNode<ElemType> *bt) {
	/*二叉树为空，空操作返回*/
	if(bt == NULL)
		return;
	/*二叉树的左右子树都为空，空操作返回*/
	if(bt->lchild == NULL && bt->rchild == NULL)
		return;
	/*交换左右子树*/
	BiNode<ElemType> *tmp;
	tmp = bt->lchild;
	bt->lchild = bt->rchild;
	bt->rchild = tmp;
	/*递归处理左子树*/
	GetMirror(bt->lchild);
	/*递归处理右子树*/
	GetMirror(bt->rchild); 
}


