#include<iostream>
using namespace std;
#include "LinkList.cpp"
template <class ElemType>
void Merge(LinkList<ElemType> &L1, LinkList<ElemType> &L2) {
	/*��������L1��L2�ϲ���L1*/
	Node<ElemType> *first1, *first2;
	first1 = L1.GetFirst(); /*��ȡ������L1��ͷָ��*/
	first2 = L2.GetFirst(); /*��ȡ������L2��ͷָ��*/ 
	Node<ElemType> *p,*q,*r;
	r = first1; /*������L1��βָ��*/
	p = first1->next;
	q = first2->next;
	while(p != NULL && q != NULL) {
		if(p->data <= q->data) {
			r->next = p;
			r = p;
			p = p->next;
		}
		else {
			r->next = q;
			r = q;
			q = q->next;
		}
	}
	while(p != NULL) {
			r->next = p;
			r = p;
			p = p->next;
	}
	while(q != NULL) {
			r->next = q;
			r = q;
			q = q->next;
	}
	r->next = NULL;
}
int main() {
	int r1[5] = {1, 3, 5, 7, 9};
	int r2[8] = {2, 4, 6, 8, 10, 12, 14, 16};
	/*��һ��������ı�Ϊ5*/
	LinkList<int> L1(r1, 5);
	/*�ڶ���������ı�Ϊ8*/
	LinkList<int> L2(r2, 8);
	cout<<"��һ��������Ϊ��"<<endl;
	L1.PrintList();
	cout<<"�ڶ���������Ϊ��"<<endl;
	L2.PrintList();
	cout<<"�ϲ��Ժ�ĵ�����Ϊ��"<<endl;
	Merge(L1, L2);
	L1.PrintList();
	return 0;
}
