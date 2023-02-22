#include <iostream>
using namespace std;
#include "InThrBiTree.h"

template <class ElemType>
ThrBiNode<ElemType> *InThrBiTree<ElemType>::Creat(ThrBiNode<ElemType> *bt) {
	char ch;
	cout<<"�����봴��һ�ö������Ľ�����ݣ�"<<endl;
	cin>>ch;
	/*'#'����ն�����*/
    if(ch == '#') 
		return NULL;
    else { 
		bt = new ThrBiNode<ElemType>; /*�����½��*/
        bt->data = ch;
		bt->ltag = 0; /*��ʼ����־��*/
		bt->rtag = 0;
        bt->lchild = Creat(bt->lchild); /*�ݹ鴴��������*/
        bt->rchild = Creat(bt->rchild); /*�ݹ鴴��������*/
    } 
    return bt;
}

template <class ElemType>
void InThrBiTree<ElemType>::ThrBiTree(ThrBiNode<ElemType> *bt) {
	if(bt == NULL)
		return;
	ThrBiTree(bt->lchild); /*����������������*/
	if(bt->lchild == NULL) { /*����bt��ǰ������*/
		bt->ltag = 1;
		bt->lchild = pre;
	}
	if(bt->rchild == NULL) { /*�޸�bt���ұ�־��*/
		bt->rtag = 1;
	}
	if(pre != NULL && pre->rtag == 1) { /*����pre�ĺ������*/
		pre->rchild = bt;
	}
	pre = bt; /*����pre*/
	ThrBiTree(bt->rchild); /*����������������*/
}

/*���캯��*/
template <class ElemType>
InThrBiTree<ElemType>::InThrBiTree() {
	/*����δ�������Ķ�����*/
	root = Creat(root);
	/*Ϊpre����ֵ*/
	pre = NULL;
	/*����������������*/
	ThrBiTree(root);
}

/*������������������Ѱ�ҽ��p�ĺ�̽��*/
template <class ElemType>
ThrBiNode<ElemType> *InThrBiTree<ElemType>::Next(ThrBiNode<ElemType> *p) {
	ThrBiNode<ElemType> *q;
	if(p->rtag == 1) /*p���Һ��ӣ�rchildΪ������ָ��p�ĺ��*/
		q = p->rchild;
	else { /*p���Һ��ӣ����Ϊp�������������µĽ��*/
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
	while(p->ltag == 0) /*���������½��*/
		p = p->lchild;
	cout<<p->data<<" ";
	while(p->rchild != NULL) { /*������һ�����*/
		p = Next(p);
		cout<<p->data<<" ";
	}
	cout<<endl;
}
