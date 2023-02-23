#ifndef LINKLIST_H
#define LINKLIST_H

template <class ElemType>
struct Node{
	ElemType data;
	Node *next;
};

template <class ElemType>
class LinkList{
public:
	LinkList();
	LinkList(ElemType a[], int n);
	~LinkList();
	void PrintList();
	Node<ElemType>* GetFirst();
private:
	Node<ElemType> *first;
};
#endif
