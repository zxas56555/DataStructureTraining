#include <iostream>
using namespace std;
#include "CirQueue.h"

template <class ElemType>
CirQueue<ElemType>::CirQueue() {
	front = QueueSize - 1;
    rear = QueueSize - 1;
}

template <class ElemType>
CirQueue<ElemType>::~CirQueue() {
} 

template <class ElemType>
void CirQueue<ElemType>::EnQueue(ElemType x) {
	if((rear + 1) % QueueSize == front)
		throw "ѭ���������������磡";
	rear = (rear + 1) % QueueSize;
	data[rear] = x;
}

template <class ElemType>
ElemType CirQueue<ElemType>::DeQueue() {
	if(rear == front)
		throw "ѭ������Ϊ�գ�";
	front = (front + 1) % QueueSize;
	return data[front];
}

template <class ElemType>
ElemType CirQueue<ElemType>::GetQueue() {
	if(rear == front)
		throw "ѭ������Ϊ�գ�";
	return data[(front + 1) % QueueSize];
}

template <class ElemType>
int CirQueue<ElemType>::Length() {
	return (rear - front + QueueSize) % QueueSize;
}

template <class ElemType> 
int CirQueue<ElemType>::Empty() {
	if(front == rear) 
		return 1;
	else 
		return 0;
} 
