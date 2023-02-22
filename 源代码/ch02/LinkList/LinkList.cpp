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
	for(int i = 0;i < n;i++) { 
		s = new Node<ElemType>; /*申请新结点*/
		s->data = a[i]; /*给新结点的数据域赋值*/
		r->next = s; /*将新结点插入到单链表末尾*/
		r = s; /*更新尾指针r*/
	}
	r->next=NULL; /*将终端结点的指针域置空*/
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
int LinkList<ElemType>::Length() {
	Node<ElemType> *p = first->next;
	int count = 0;
	while(p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

template <class ElemType>
ElemType LinkList<ElemType>::Get(int i) {
	Node<ElemType> *p = first->next;
	int count = 1;
	while(p != NULL && count < i) {
		p = p->next;
		count++;
	}
	if(p!=NULL) 
		return p->data;
	else 
		throw  "参数非法";
}


template <class ElemType>  
void LinkList<ElemType>::Insert(int i, ElemType x)
{
	Node<ElemType> *p = first,*s;
	int j = 0; /*工作指针p应指向头结点*/
    while(p != NULL && j < i-1) { /*查找第i-1个结点*/
		p = p->next; /*工作指针p后移*/
		j++; /*计数器加1*/
    }
    /*没有找到第i-1个结点*/
    if (p == NULL) throw "参数不合法，不存在第i-1个结点";
    else {
		s = new Node<ElemType>; /*申请新结点*/
		s->data = x; /*数据域赋值*/
		s->next = p->next;
		p->next = s; /*将结点s插入到结点p之后*/
    }
}

template <class ElemType>  
ElemType LinkList<ElemType>::Delete(int i) {
	Node<ElemType> *p,*q;
	ElemType x;
	int j = 0; /*计数器初始化*/
	p = first; /*注意工作指针p要指向头结点*/
	while(p != NULL && j < i-1) { /*查找第i-1个结点*/
		p = p->next;
		j++;
	}
	if(p == NULL || p->next == NULL) /*结点p不存在或p存在但p的后继结点不存在*/
		throw "参数i不合法"; 
	else {
		q = p->next;
		x = q->data; /*暂存被删结点的数据域*/
		p->next = q->next; /*更改p结点的指针域*/
		delete q; /*释放q*/
		return x;
	}
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
