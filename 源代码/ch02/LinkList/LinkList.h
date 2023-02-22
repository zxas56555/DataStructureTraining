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
	~LinkList(); /*析构函数*/
	int Length(); /*返回单链表的表长*/
	ElemType Get(int i); /*按位查找，返回第i个元素的值*/
	int Locate(ElemType x); /*按值查找*/
	void Insert(int i, ElemType x); /*插入操作*/
	ElemType Delete(int i); /*删除操作*/
	void PrintList(); /*遍历操作*/
private:
	Node<ElemType> *first; /*头指针*/
};
#endif

