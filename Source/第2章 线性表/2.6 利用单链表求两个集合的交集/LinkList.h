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
	LinkList(); /*无参构造函数，建立只有头结点的空单链表*/
	LinkList(ElemType a[], int n); /*有参构造函数，使用尾插法建立有n个元素结点的单链表*/
	int Locate(ElemType x); /*在单链表中按值查找，若存在，返回序号*/
	void PrintList(); /*遍历操作，按序号依次输出各元素*/
	Node<ElemType> *GetFirst(); /*返回头指针*/
private:
	Node<ElemType> *first; /*单链表的头指针*/
};
#endif

