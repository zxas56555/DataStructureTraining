#include "LinkList.h"
#include<iostream>
using namespace std;
template <class ElemType>
LinkList<ElemType>::LinkList() {
	first = new Node<ElemType>; /*����ͷ���*/
	first->next = NULL; /*ͷ����ָ������Ϊ��*/
}

template <class ElemType>
LinkList<ElemType>::LinkList(ElemType a[], int n) {
	Node<ElemType> *r, *s;
	first = new Node<ElemType>; /*����ͷ���*/
	r = first; /*βָ���ʼ��*/
	for(int i = 0; i < n; i++) {
		s = new Node<ElemType>; /*�����½��*/
		s->data = a[i]; /*���½���������ֵ*/
		r->next = s; /*���½����뵽������ĩβ*/
		r = s; /*����βָ��r*/
	}
	r->next = NULL; /*���ն˽���ָ�����ÿ�*/
}

template <class ElemType>
LinkList<ElemType>::~LinkList() {
	Node<ElemType> *q;
	while(first != NULL) { /*��������Ϊ��ʱ*/
		q = first; /*�ݴ汻�ͷŽ��*/
		first = first->next; /*����������һ�����*/
		delete q; /*�ͷ�q*/
	}
}

template <class ElemType>
void LinkList<ElemType>::Reverse() {
	Node<ElemType> *p,*q;
	p = first->next;
	first->next = NULL;
	while(p != NULL) {
		q = p->next;
		p->next = first->next;
		first->next = p;
		p = q;
	}
}

template <class ElemType>
void LinkList<ElemType>::PrintList( ) {
	Node<ElemType> *p;
	p = first->next; /*����ָ��p��ʼ��*/
	while(p != NULL) {
		cout<<p->data<<" ";
		p = p->next; /*����ָ��p����*/
	}
	cout<<endl;
}

