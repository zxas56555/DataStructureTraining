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
	/*比较相邻的结点是否逆序*/
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
	/*使用直接插入排序对单链表进行排序*/
	Node<ElemType> *p,*q,*r,*s;
	p = first->next;
	/*如果单链表非空*/ 
	if(p != NULL) {
		/*在首元结点后断开*/
		q = p->next;
		p->next = NULL; 
		/*依次将q插入到有序单链表中*/ 
		while(q) {
			r = q->next;
			/*在单链表中查找结点q的插入位置*/
			s = first;
			/*若s的后继结点存在，并且其数据域小于q的数据域时后移s*/ 
			while((s->next) && ((s->next->data) < (q->data))) {
				s = s->next;
			}
			/*将q插入到s之后*/ 
			q->next = s->next;
			s->next = q;
			/*q后移*/
			q = r; 
		}
	} 	 
}
