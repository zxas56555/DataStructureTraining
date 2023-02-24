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
	LinkList(ElemType a[],int n);
	~LinkList();
	void PrintList();
	int IsOrdering(); /*判断单链表是否升序排序*/
	void Sort(); /*将单链表按升序排序*/
private:
	Node<ElemType> *first;
};
#endif

