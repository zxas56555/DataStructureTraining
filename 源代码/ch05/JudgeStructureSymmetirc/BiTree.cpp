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
		bt = new BiNode<ElemType>;       /*�����½��*/
        bt->data = ch;
        bt->lchild = Creat(bt->lchild); /*�ݹ鴴��������*/
        bt->rchild = Creat(bt->rchild); /*�ݹ鴴��������*/
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
