#include <iostream>
using namespace std;
#include "LinkListPoly.h"

LinkListPoly::LinkListPoly() {
	first=new Node;
	first->next=NULL;
}

LinkListPoly::LinkListPoly(int c[], int e[], int n) {
	Node *r,*s;
	first = new Node;
	r = first;
	for(int i = 0; i < n; i++) {
		s = new Node;
		s->coef = c[i];
		s->exp = e[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

LinkListPoly::~LinkListPoly() {
	Node *q = NULL;
	while(first != NULL) {
		q = first;
		first = first->next;
		delete q;
	}
}

Node *LinkListPoly::GetFirst() {
	return first;
}

void LinkListPoly::PrintList() {
	Node *p = first->next;
	int count = 0;
	while(p != NULL) {
		if(count != 0 && p->coef > 0) {
			cout<<"+";
		}
		cout<<p->coef;
		if(p->exp != 0) {
			cout<<"X";
			if(p->exp != 1) {
				cout<<p->exp;
		    }
		}
		p = p->next;
		count++;
	}
	cout<<endl;
}
