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
		bt = new BiNode<ElemType>;       /*生成新结点*/
        bt->data = ch;
        bt->lchild = Creat(bt->lchild); /*递归创建左子树*/
        bt->rchild = Creat(bt->rchild); /*递归创建右子树*/
    } 
    return bt;
}

template <class ElemType>
int BiTree<ElemType>::IsStructureSymmetric(BiNode<ElemType> *bt) {
	if(bt == NULL)
		return 1;
	return IsCheck(bt->lchild, bt->rchild);
}

template <class ElemType>
int BiTree<ElemType>::IsCheck(BiNode<ElemType> *lchild, BiNode<ElemType> *rchild) {
	if(lchild == NULL && rchild == NULL)
		return 1;
	if(lchild == NULL || rchild == NULL)
		return 0;
	return IsCheck(lchild->lchild, rchild->rchild) && IsCheck(lchild->rchild, rchild->lchild);
}
