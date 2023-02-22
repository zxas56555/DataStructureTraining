#ifndef LINKLIST_H /*避免重复引用头文件*/ 
#define LINKLIST_H

template <class ElemType>
struct Node{
    ElemType data;
    Node<ElemType> *next;  
};

template <class ElemType>
class LinkList{
public:
	LinkList(); /*建立只有头结点的空单链表*/
	LinkList(ElemType a[], int n); /*尾插法建立单链表*/
	int Locate(ElemType x); /*按值查找*/
	void PrintList(); /*遍历操作*/
	Node<ElemType> *GetFirst(); /*返回头指针*/
private:
	Node<ElemType> *first; 
};
#endif

