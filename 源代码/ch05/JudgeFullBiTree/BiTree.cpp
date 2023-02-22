#include <iostream>
using namespace std;
#include "BiTree.h"

template <class ElemType>
BiNode<ElemType> *BiTree<ElemType>::Creat(BiNode<ElemType> *bt) {
	char ch;
	cout<<"�����봴��һ�ö������Ľ�����ݣ�"<<endl;
	cin>>ch;
	/*'#'����ն�����*/
    if(ch == '#') 
		return NULL;
    else { 
		bt = new BiNode<ElemType>; /*�����½��*/
        bt->data = ch;
        bt->lchild = Creat(bt->lchild); /*�ݹ鴴��������*/
        bt->rchild = Creat(bt->rchild); /*�ݹ鴴��������*/
    } 
    return bt;
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
void BiTree<ElemType>::CountLeaf(BiNode<ElemType> *bt) {
	if(bt != NULL) {
		if(bt->lchild == NULL && bt->rchild == NULL)
			countLeaf++;
		CountLeaf(bt->lchild);
		CountLeaf(bt->rchild);
	}
}
