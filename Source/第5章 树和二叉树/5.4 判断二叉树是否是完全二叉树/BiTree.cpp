#include <bits/stdc++.h>

using namespace std;

#include "BiTree.h"
#include "CirQueue.cpp"

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
int BiTree<ElemType>::IsCompleteBiTree(BiNode<ElemType> *bt) {
	CirQueue<BiNode<ElemType> *> Q;
	BiNode<ElemType> *p;
	if(bt == NULL) return 1; /*�ն�����*/
	Q.EnQueue(bt);
	/*�����ӵĶ�ͷָ�벻Ϊ��ʱ����������ָ�����*/ 
	while((p = Q.DeQueue()) != NULL) {
		Q.EnQueue(p->lchild);
		Q.EnQueue(p->rchild);	
	}
	/*��������ָ��ʱ���ж϶������Ƿ��зǿ�ָ��*/
	/*����У�������ȫ������*/
	/*û�У���Ϊ��ȫ������*/
	while(!Q.Empty()) {
		p = Q.DeQueue();
		if(p != NULL)
			return 0;
	}
	return 1;
}
