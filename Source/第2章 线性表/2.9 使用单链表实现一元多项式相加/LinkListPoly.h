#ifndef LINKLISTPOLY_H
#define LINKLISTPOLY_H

struct Node{
	float coef;	/*系数*/
	int exp; /*指数*/
	Node *next;
};

class LinkListPoly{
public:
	LinkListPoly();
	LinkListPoly(int c[], int e[], int n);
	~LinkListPoly();
	void PrintList();
	Node *GetFirst();
private:
	Node *first;
};
#endif
