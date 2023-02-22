#include "LinkList.h"

template <class ElemType>
LinkList<ElemType>::LinkList() {
	first = new Node<ElemType>; /*生成头结点*/
	first->next = NULL; /*头结点的指针域置为空*/
}

template <class ElemType>  
LinkList<ElemType>::LinkList(ElemType a[], int n) {
	Node<ElemType> *r, *s;
	first = new Node<ElemType>; /*生成头结点*/
	r = first; /*尾指针初始化*/
	for(int i=0; i<n; i++) { 
		s = new Node<ElemType>; /*申请新结点*/
		s->data = a[i]; /*给新结点的数据域赋值*/
		r->next = s; /*将新结点插入到单链表末尾*/
		r = s; /*更新尾指针r*/
	}
	r->next = NULL; /*将终端结点的指针域置空*/
}

template <class ElemType>
LinkList<ElemType>::~LinkList() {
	Node<ElemType> *q;
	while(first != NULL) { /*当单链表不为空时*/
		q = first; /*暂存被释放结点*/
		first = first->next; /*继续处理下一个结点*/
		delete q; /*释放q*/  
	}
}

template <class ElemType>
void LinkList<ElemType>::LinkListDelNormalDup() {
	Node<ElemType> *p,*q,*r;
	p = first->next;
	while(p != NULL) {
		q = p;
		while(q->next != NULL) {
			if(p->data == q->next->data) {
				r = q->next;				
				q->next = r->next; 
				delete r;
			}
			else {
				q = q->next;	
			}
		}
		p = p->next;
	}
}

template <class ElemType>
void LinkList<ElemType>::PrintList() {
	Node<ElemType> *p;
	p = first->next; /*工作指针p初始化*/
	while(p != NULL) {
		cout<<p->data<<" ";
		p = p->next; /*工作指针p后移*/
	}
	cout<<endl;
}

