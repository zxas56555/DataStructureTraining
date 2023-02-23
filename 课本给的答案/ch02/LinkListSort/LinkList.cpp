#include <iostream>
#include "LinkList.h"
using namespace std;
template <class ElemType>
LinkList<ElemType>::LinkList() {
	first = new Node<ElemType>;
	first->next = NULL;
}

template <class ElemType>
LinkList<ElemType>::LinkList(ElemType a[], int n) {
	Node<ElemType> *r,*s;
	first = new Node<ElemType>;
	r = first;
	for(int i = 0; i < n; i++) {
		s = new Node<ElemType>;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

template <class ElemType>
LinkList<ElemType>::~LinkList() {
	Node<ElemType> *q = NULL;
	while(first != NULL) {
		q = first;
		first = first->next;
		delete q;
	}
}

template <class ElemType>
void LinkList<ElemType>::PrintList() {
	Node<ElemType> *p = first->next;
	while(p != NULL) {
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

template <class ElemType>
int LinkList<ElemType>::IsOrdering() {
	Node<ElemType> *p,*q = NULL;
	p = first->next;
	int flag = 1;
	if(p) {
		q = p->next;
	}
	/*�Ƚ����ڵĽ���Ƿ�����*/
	while((p != NULL) && (q != NULL)) {
		if(p->data > q->data) {
			flag = 0;
			break;
		}
		else {
			p = q;
			q = q->next;
		}
	}
	return flag;
}

template <class ElemType>
void LinkList<ElemType>::Sort() {
	/*ʹ��ֱ�Ӳ�������Ե������������*/
	Node<ElemType> *p,*q,*r,*s;
	p = first->next;
	/*���������ǿ�*/ 
	if(p != NULL) {
		/*����Ԫ����Ͽ�*/
		q = p->next;
		p->next = NULL; 
		/*���ν�q���뵽����������*/ 
		while(q) {
			r = q->next;
			/*�ڵ������в��ҽ��q�Ĳ���λ��*/
			s = first;
			/*��s�ĺ�̽����ڣ�������������С��q��������ʱ����s*/ 
			while((s->next) && ((s->next->data) < (q->data))) {
				s = s->next;
			}
			/*��q���뵽s֮��*/ 
			q->next = s->next;
			s->next = q;
			/*q����*/
			q = r; 
		}
	} 	 
}
