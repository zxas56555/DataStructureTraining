#include<iostream>
using namespace std;
#include "LinkList.cpp"
template <class ElemType>
void Merge(LinkList<ElemType> &L1, LinkList<ElemType> &L2) {
	/*将单链表L1和L2合并至L1*/
	Node<ElemType> *first1, *first2;
	first1 = L1.GetFirst(); /*获取单链表L1的头指针*/
	first2 = L2.GetFirst(); /*获取单链表L2的头指针*/ 
	Node<ElemType> *p,*q,*r;
	r = first1; /*单链表L1的尾指针*/
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
	/*第一个单链表的表长为5*/
	LinkList<int> L1(r1, 5);
	/*第二个单链表的表长为8*/
	LinkList<int> L2(r2, 8);
	cout<<"第一个单链表为："<<endl;
	L1.PrintList();
	cout<<"第二个单链表为："<<endl;
	L2.PrintList();
	cout<<"合并以后的单链表为："<<endl;
	Merge(L1, L2);
	L1.PrintList();
	return 0;
}
