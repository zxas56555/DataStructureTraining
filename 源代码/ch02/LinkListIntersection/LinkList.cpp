#include "LinkList.h"

template <class ElemType>
LinkList<ElemType>::LinkList() {
	first = new Node<ElemType>; /*生成头结点*/
	first->next = NULL; /*头结点的指针域置为空*/
}

template <class ElemType>  
LinkList<ElemType>::LinkList(ElemType a[], int n) {
	Node<ElemType> *r,*s;
	first = new Node<ElemType>; /*生成头结点*/
	r = first; /*尾指针初始化*/
	for(int i = 0; i < n; i++) { 
		s = new Node<ElemType>; /*申请新结点*/
		s->data = a[i]; /*给新结点的数据域赋值*/
		r->next = s; /*将新结点插入到单链表末尾*/
		r = s; /*更新尾指针r*/
	}
	r->next = NULL; /*将终端结点的指针域置空*/
}

template <class ElemType>
int LinkList<ElemType>::Locate(ElemType x) {
	Node<ElemType> *p;
	p = first->next; /*工作指针p初始化*/
	int j = 1; /*累加器j初始化*/
	while(p != NULL) {
		if(p->data == x) 
			return j; /*查找成功，返回其序号*/
		p = p->next;                   
		j++;
	}
	return 0; /*查找失败，返回0*/
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

template <class ElemType>
Node<ElemType> *LinkList<ElemType>::GetFirst() {
	return first;
}
