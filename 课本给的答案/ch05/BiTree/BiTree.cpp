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
void BiTree<ElemType>::Release(BiNode<ElemType> *bt) {
	/*���պ��������˳���ͷŶ�����*/
	if(bt != NULL) {                  
		Release(bt->lchild); /*�ͷ�������*/
		Release(bt->rchild); /*�ͷ�������*/
        delete bt; /*ɾ�������*/
	}  
}

template <class ElemType>
void BiTree<ElemType>::PreOrder(BiNode<ElemType> *bt) {
	if(bt == NULL) /*�ݹ���õı߽�����*/
		return;
	else {		
		cout<<bt->data<<" "; /*���ʸ����*/
        PreOrder(bt->lchild); /*ǰ��ݹ����������*/
		PreOrder(bt->rchild); /*ǰ��ݹ����������*/
	}
}

template <class ElemType>
void BiTree<ElemType>::InOrder(BiNode<ElemType> *bt) {
	if(bt == NULL)  
		return; /*�ݹ���õı߽�����*/	          
    else {	
        InOrder(bt->lchild); /*����ݹ����������*/
        cout<<bt->data<<" "; /*���ʸ����*/
        InOrder(bt->rchild); /*����ݹ������������*/
	}
}

template <class ElemType>
void BiTree<ElemType>::PostOrder(BiNode<ElemType> *bt) {
	if(bt == NULL)  
		return; /*�ݹ���õı߽�����*/
    else {	
        PostOrder(bt->lchild); /*����ݹ����������*/
        PostOrder(bt->rchild); /*����ݹ����������*/
        cout<<bt->data<<" "; /*���ʸ����*/
	}
}

template <class ElemType>
void BiTree<ElemType>::LevelOrder(BiNode<ElemType> *bt) {
	const int MaxSize = 100;
	/*����˳����У����費�ᷢ�����*/
	int front = -1, rear = -1;  
	BiNode<ElemType> *Q[MaxSize], *q;
	if(bt == NULL) 
		return;
	else {
		Q[rear++] = bt; /*bt���*/
		/*���зǿ�ʱѭ��*/
		while(front != rear) {
			q = Q[front++]; /*��ͷ����*/
			cout<<q->data<<" "; /*���ʶ�ͷ*/	
			if(q->lchild != NULL) /*�����ͷ�����ӣ��������*/
				Q[rear++] = q->lchild;		
			if(q->rchild != NULL) /*�����ͷ���Һ��ӣ��Һ������*/
				Q[rear++] = q->rchild;
		}
	}
}

