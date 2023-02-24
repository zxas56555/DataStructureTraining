#include <iostream>
#include "LinkListPoly.h"
using namespace std;

/*实现一元多项式相加，结果存入LA*/
void PolyAdd(LinkListPoly &LA, LinkListPoly &LB) {
	/*p指向单链表LA的首元结点*/
	/*q指向单链表LB的首元结点*/
	Node *p, *q;
	/*p_pre为p的前驱结点*/
	/*q_pre为q的前驱结点*/
	Node *p_pre,*q_pre;
	Node *tmp;
	p_pre = LA.GetFirst();
	q_pre = LB.GetFirst();
	p = p_pre->next;
	q = q_pre->next;
	while(p != NULL && q != NULL) {
		/*p后移,q不动*/
		if(p->exp < q->exp) {
			p_pre = p;
			p = p->next;
		}
		/*p不动，q插入到p之前，p_pre指向q，q指向原位置的下一个结点*/
		else if(p->exp > q->exp) {
			tmp = q->next;
			q_pre->next = q->next;
			q->next = p;
			p_pre->next = q;
			p_pre = q;
			q = tmp;
		}
		/*指数相等，合并结点p和q的系数*/
		else if(p->exp == q->exp) {
			p->coef = p->coef + q->coef;
			if(p->coef == 0) {
			  /*系数为0时，删除p*/
			  tmp = p;
			  p = p->next;
			  p_pre->next = p;
			  delete tmp;
			}
			/*删除q*/
			tmp = q;
			q = q->next;
			q_pre->next = q;
			delete tmp;
		}
	}
	/*p已为空，如果q不为空，则将q连接到p_pre的后面*/
	/*此时p为空，p_pre不为空*/
	if(q != NULL) {
		p_pre->next = q;
	}
}

int main() {
	int c1[4] = {1, 2, -100, 4};
	int p1[4] = {0, 2, 4, 6};
	LinkListPoly LA(c1, p1, 4);
	cout<<"第一个多项式为："<<endl;
	LA.PrintList();
	int c2[6]={7, 20, -9, 5, 30, 40};
	int p2[6]={0, 1, 2, 4, 6, 10};
	cout<<"第二个多项式为："<<endl;
	LinkListPoly LB(c2, p2, 6);
	LB.PrintList();
	PolyAdd(LA, LB);
	cout<<"相加以后的多项式为："<<endl;
	LA.PrintList();
	cout<<"\n此部分由刘宪铎完成"<<endl;
	return 0;
}

