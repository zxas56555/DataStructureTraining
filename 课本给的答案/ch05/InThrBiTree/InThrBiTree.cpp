#include <iostream>
using namespace std;
#include "InThrBiTree.h"

template <class ElemType>
ThrBiNode<ElemType> *InThrBiTree<ElemType>::Creat(ThrBiNode<ElemType> *bt) {
	char ch;
	cout<<"请输入创建一棵二叉树的结点数据："<<endl;
	cin>>ch;
	/*'#'代表空二叉树*/
    if(ch == '#') 
		return NULL;
    else { 
		bt = new ThrBiNode<ElemType>; /*生成新结点*/
        bt->data = ch;
		bt->ltag = 0; /*初始化标志域*/
		bt->rtag = 0;
        bt->lchild = Creat(bt->lchild); /*递归创建左子树*/
        bt->rchild = Creat(bt->rchild); /*递归创建右子树*/
    } 
    return bt;
}

template <class ElemType>
void InThrBiTree<ElemType>::ThrBiTree(ThrBiNode<ElemType> *bt) {
	if(bt == NULL)
		return;
	ThrBiTree(bt->lchild); /*对左子树建立线索*/
	if(bt->lchild == NULL) { /*设置bt的前驱线索*/
		bt->ltag = 1;
		bt->lchild = pre;
	}
	if(bt->rchild == NULL) { /*修改bt的右标志域*/
		bt->rtag = 1;
	}
	if(pre != NULL && pre->rtag == 1) { /*设置pre的后继线索*/
		pre->rchild = bt;
	}
	pre = bt; /*更新pre*/
	ThrBiTree(bt->rchild); /*对右子树建立线索*/
}

/*构造函数*/
template <class ElemType>
InThrBiTree<ElemType>::InThrBiTree() {
	/*创建未线索化的二叉树*/
	root = Creat(root);
	/*为pre赋初值*/
	pre = NULL;
	/*中序线索化二叉树*/
	ThrBiTree(root);
}

/*在中序线索二叉树上寻找结点p的后继结点*/
template <class ElemType>
ThrBiNode<ElemType> *InThrBiTree<ElemType>::Next(ThrBiNode<ElemType> *p) {
	ThrBiNode<ElemType> *q;
	if(p->rtag == 1) /*p无右孩子，rchild为线索，指向p的后继*/
		q = p->rchild;
	else { /*p有右孩子，后继为p的右子树最左下的结点*/
		q = p->rchild;
		while(q->ltag == 0)
			q = q->lchild;
	}
	return q;
}

template <class ElemType>
void InThrBiTree<ElemType>::InOrder() {
	ThrBiNode<ElemType> *p;
	if(root == NULL) 
		return;
	p = root;
	while(p->ltag == 0) /*查找最左下结点*/
		p = p->lchild;
	cout<<p->data<<" ";
	while(p->rchild != NULL) { /*查找下一个结点*/
		p = Next(p);
		cout<<p->data<<" ";
	}
	cout<<endl;
}
