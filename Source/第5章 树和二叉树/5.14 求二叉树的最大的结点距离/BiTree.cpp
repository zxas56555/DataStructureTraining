#include <bits/stdc++.h>

using namespace std;

#include "BiTree.h"
/*ȫ�ֱ�������¼�����������Ľ�����*/ 
int maxLen = 0;
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
void BiTree<ElemType>::GetMaxPathLength(BiNode<ElemType> *bt) {
	/*������Ϊ�գ��ղ�������*/
	if(bt == NULL) {
		return;
	}
	/*������������Ϊ�գ�������������������Ϊ0*/
	if(bt->lchild == NULL) {
		bt->maxLeft = 0;
	} 
	/*������������Ϊ�գ�������������������Ϊ0*/ 
	if(bt->rchild == NULL) {
		bt->maxRight = 0;
	}
	/*�����������Ϊ�գ��ݹ�Ѱ������������������*/
	if(bt->lchild != NULL) {
		GetMaxPathLength(bt->lchild);
	}
	/*�����������Ϊ�գ��ݹ�Ѱ������������������*/
	if(bt->rchild != NULL) {
		GetMaxPathLength(bt->rchild);
	}
	/*������������������*/
	if(bt->lchild != NULL) {
		int temp = 0;
		int ll = bt->lchild->maxLeft;
		int lr = bt->lchild->maxRight;
		temp = ll > lr ? ll : lr;
		bt->maxLeft = temp + 1;
	} 
	/*������������������*/ 
	if(bt->rchild != NULL) {
		int temp = 0;
		int rl = bt->rchild->maxLeft;
		int rr = bt->rchild->maxRight;
		temp = rl > rr ? rl : rr;
		bt->maxRight = temp + 1;
	} 
	/*������������*/
	if(bt->maxLeft + bt->maxRight > maxLen) {
		maxLen = bt->maxLeft + bt->maxRight;
	}
}
