
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
Node<ElemType>* LinkList<ElemType>::GetFirst() {
	return first;
}

template <class ElemType>
void LinkList<ElemType>::PrintList() {
	Node<ElemType> *p = first->next;
	while(p!=NULL) {
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}
