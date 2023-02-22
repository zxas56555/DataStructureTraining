#include <iostream>
using namespace std;
#include "SeqStack.h"

template <class ElemType>
SeqStack<ElemType>::SeqStack() {
	top = -1;
}

template <class ElemType>
SeqStack<ElemType>::~SeqStack() {
} 

template <class ElemType> 
void SeqStack<ElemType>::Push(ElemType x) {
    if(top == StackSize-1) 
		throw "Ë³ÐòÕ»ÒÑÂú£¬ÉÏÒç£¡";
    top++;
    data[top] = x;
}

template <class ElemType>
ElemType SeqStack<ElemType>::Pop() { 
    ElemType x;
    if(top == -1) 
		throw "Ë³ÐòÕ»Îª¿Õ£¬ÏÂÒç£¡";
    x = data[top--];
    return x;
}

template <class ElemType> 
ElemType SeqStack<ElemType>::GetTop() {
	if(top != -1)  
		return data[top];
	else
		throw "Ë³ÐòÕ»Îª¿Õ£¡";
}

template <class ElemType> 
int SeqStack<ElemType>::Empty() {
	if(top==-1) 
		return 1;
	else 
		return 0;
} 
