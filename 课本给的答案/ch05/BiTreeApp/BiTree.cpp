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
void BiTree<ElemType>::Release(BiNode<ElemType> *bt) {
	/*按照后序遍历的顺序释放二叉树*/
	if(bt != NULL) {                  
		Release(bt->lchild); /*释放左子树*/
		Release(bt->rchild); /*释放右子树*/
        delete bt;
	}  
}

template <class ElemType>
int BiTree<ElemType>::Depth(BiNode<ElemType> *bt) {
	if(bt == NULL)
		return 0;
	else {
		int dep1 = Depth(bt->lchild);
		int dep2 = Depth(bt->rchild);
		return (dep1 > dep2) ? (dep1 + 1) : (dep2 + 1);
	}
}

template <class ElemType>
void BiTree<ElemType>::Count(BiNode<ElemType> *bt) {
	if(bt != NULL) {
		Count(bt->lchild);
		countNode++;
		Count(bt->rchild);
	}
}

template <class ElemType>
void BiTree<ElemType>::CountLeaf(BiNode<ElemType> *bt) {
	if(bt != NULL) {
		if(bt->lchild == NULL && bt->rchild == NULL)
			countLeaf++;
		CountLeaf(bt->lchild);
		CountLeaf(bt->rchild);
	}
}

template <class ElemType>
void BiTree<ElemType>::PrintLeaf(BiNode<ElemType> *bt) {
	if(bt != NULL) {
		if(bt->lchild == NULL && bt->rchild == NULL) {
			cout<<bt->data<<" ";
		}
		PrintLeaf(bt->lchild);
		PrintLeaf(bt->rchild);
	}
}
