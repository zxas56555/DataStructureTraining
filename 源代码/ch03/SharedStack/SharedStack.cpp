#include <iostream>
using namespace std;
#include "SharedStack.h"

template <class ElemType>
SharedStack<ElemType>::SharedStack() {
	top1 = -1;
	top2 = StackSize;
}

template <class ElemType>
SharedStack<ElemType>::~SharedStack() {
} 

template <class ElemType> 
void SharedStack<ElemType>::Push(int i, ElemType x) {
    if(top1 == top2 - 1) 
		throw "����ջ���������磡";
	if(i == 1) 
		data[++top1]=x; /*ջ1��ջ*/
	if(i == 2) 
		data[--top2]=x; /*ջ2��ջ*/
}

template <class ElemType>
ElemType SharedStack<ElemType>::Pop(int i) { 
    if(i == 1) {
		if(top1 == -1)
			throw "ջ1Ϊ�գ�";
		return data[top1--];
	}
	else if(i == 2) {
		if(top2 == StackSize)
			throw "ջ2Ϊ�գ�";
		return data[top2++];
	}
    else
        throw "�������Ϸ���1��ʾջ1��2��ʾջ2��";
}

template <class ElemType> 
ElemType SharedStack<ElemType>::GetTop(int i) {
	if(i == 1) {
		if(top1 == -1)
			throw "ջ1Ϊ�գ�";
		return data[top1];
	}
	else if(i == 2) {
		if(top2 == StackSize)
			throw "ջ2Ϊ�գ�";
		return data[top2];
	}
	else
		throw "�������Ϸ���1��ʾջ1��2��ʾջ2��";
}

template <class ElemType> 
int SharedStack<ElemType>::Empty(int i) {
	if(i == 1) {
		if(top1 == -1)
			return 1;
		else
			return 0;
	}
	if(i == 2) {
		if(top2 == StackSize)
			return 1;
		else
			return 0;
	}
} 
