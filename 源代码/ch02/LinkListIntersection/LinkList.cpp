#include "LinkList.h"

template <class ElemType>
LinkList<ElemType>::LinkList() {
	first = new Node<ElemType>; /*����ͷ���*/
	first->next = NULL; /*ͷ����ָ������Ϊ��*/
}

template <class ElemType>  
LinkList<ElemType>::LinkList(ElemType a[], int n) {
	Node<ElemType> *r,*s;
	first = new Node<ElemType>; /*����ͷ���*/
	r = first; /*βָ���ʼ��*/
	for(int i = 0; i < n; i++) { 
		s = new Node<ElemType>; /*�����½��*/
		s->data = a[i]; /*���½���������ֵ*/
		r->next = s; /*���½����뵽������ĩβ*/
		r = s; /*����βָ��r*/
	}
	r->next = NULL; /*���ն˽���ָ�����ÿ�*/
}

template <class ElemType>
int LinkList<ElemType>::Locate(ElemType x) {
	Node<ElemType> *p;
	p = first->next; /*����ָ��p��ʼ��*/
	int j = 1; /*�ۼ���j��ʼ��*/
	while(p != NULL) {
		if(p->data == x) 
			return j; /*���ҳɹ������������*/
		p = p->next;                   
		j++;
	}
	return 0; /*����ʧ�ܣ�����0*/
} 

template <class ElemType>
void LinkList<ElemType>::PrintList() {
	Node<ElemType> *p;
	p = first->next; /*����ָ��p��ʼ��*/
	while(p != NULL) {
		cout<<p->data<<" ";
		p = p->next; /*����ָ��p����*/
	}
	cout<<endl;
}

template <class ElemType>
Node<ElemType> *LinkList<ElemType>::GetFirst() {
	return first;
}
