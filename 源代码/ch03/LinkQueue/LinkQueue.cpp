#include <iostream>
using namespace std;
#include "LinkQueue.h"

template <class ElemType>
LinkQueue<ElemType>::LinkQueue() {
	front = new Node<ElemType>;
	front->next = NULL;
	rear = front;
}

template <class ElemType>
LinkQueue<ElemType>::~LinkQueue() {
	Node<ElemType> *p;
	while(front != NULL) {
		p = front;
		front = front->next;
		delete p;
	}
	rear = NULL;
} 

template <class ElemType>
void LinkQueue<ElemType>::EnQueue(ElemType x) {
	Node<ElemType> *s;
	s = new Node<ElemType>;
	s->data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
}

template <class ElemType>
ElemType LinkQueue<ElemType>::DeQueue() {
	Node<ElemType> *p;
	ElemType x;
	if(rear == front)
		throw "链队列为空！";
	/*p指向队头*/
	p = front->next;
	x = p->data;
	front->next = p->next;
	/*队列长度为1时，需要更改rear指针*/
	if(p->next == NULL)
		rear = front;
	delete p;
	return x;
}

template <class ElemType>
ElemType LinkQueue<ElemType>::GetQueue() {
	if(front == rear)
		throw "链队列为空！";
	return front->next->data;
}

template <class ElemType> 
int LinkQueue<ElemType>::Empty() {
	if(front == rear)
		return 1;
	else
		return 0;
} 
