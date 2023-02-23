#include "LinkStack.h"

template <class ElemType>
LinkStack<ElemType>::LinkStack() {
	top = NULL;
}

template <class ElemType>  
LinkStack<ElemType>::~LinkStack() {
	Node<ElemType> *q;
	while(top != NULL) {
		q = top;
		top = top->next;
		delete q;
	}
}

template <class ElemType>  
void LinkStack<ElemType>::Push(ElemType x) {
	Node<ElemType> *s;
	s = new Node<ElemType>;
	s->data = x;
	s->next = top;
	top = s;
}

template <class ElemType>
ElemType LinkStack<ElemType>::Pop() {
	if(top == NULL)
		throw "Á´Õ»Îª¿Õ£¡";
	Node<ElemType> *q;
	ElemType x;
	x = top->data;
	q = top;
	top = top->next;
	delete q;
	return x;
}

template <class ElemType>
ElemType LinkStack<ElemType>::GetTop() {
	if(top != NULL)
		return top->data;
	else
		throw "Õ»Îª¿Õ£¡";
}

template <class ElemType>
int LinkStack<ElemType>::Empty() {
	if(top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
	
