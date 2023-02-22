#include <iostream>
using namespace std;
#include "Deque.h"

template <class ElemType>
Deque<ElemType>::Deque() {
	front = QueueSize - 1;
	rear = QueueSize - 1;
}

template <class ElemType>
Deque<ElemType>::~Deque() {
}

template <class ElemType>
void Deque<ElemType>::EnQueue(int i,ElemType x) {
	if((rear + 1) % QueueSize == front)
		throw "����";
	/*������*/ 
	if(i == 0) {
		data[front] = x;	
		front = (front - 1 + QueueSize) % QueueSize;
	}
	/*�Ҷ����*/ 
	if(i == 1) {
		rear = (rear + 1) % QueueSize;
		data[rear] = x;
	}
} 

template <class ElemType>
ElemType Deque<ElemType>::DeQueue(int i) {
	ElemType x;
	if(rear == front)
		throw "����";
	/*��˳���*/ 
	if(i == 0) {
		front = (front + 1) % QueueSize;
		x = data[front];	
	} 
	/*�Ҷ˳���*/ 
	if(i == 1) {
		x = data[rear];
		rear = (rear-1 + QueueSize) % QueueSize;
	}
	return x;
}

template <class ElemType>
ElemType Deque<ElemType>::GetQueue(int i) {
	if(front == rear)
		throw "����";
	ElemType x;
	/*���*/ 
	if(i == 0) {
		x = data[(front + 1) % QueueSize];	
	} 
	/*�Ҷ�*/ 
	if(i == 1) {
		x = data[rear];
	}
	return x;
	
}

template <class ElemType>
int Deque<ElemType>::Length() {
	return (rear - front + QueueSize) % QueueSize;
}

template <class ElemType>
int Deque<ElemType>::Empty() {
	if(front == rear)
		return 1;
	else
		return 0;
}

template <class ElemType>
void Deque<ElemType>::Print() {
	if(front == rear)
		cout<<"˫�˶���Ϊ�գ�"<<endl;
	else {
		int i = (front + 1) % QueueSize;
		int j = (rear + 1) % QueueSize;
		while(i != j) {
			cout<<data[i]<<" ";
			i= (i + 1) % QueueSize;
		} 
		cout<<endl;
	} 	
} 


