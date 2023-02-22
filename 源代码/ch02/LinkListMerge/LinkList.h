#ifndef LINKLIST_H /*�����ظ�����ͷ�ļ�*/
#define LINKLIST_H

template <class ElemType>
struct Node{
	ElemType data;
	Node<ElemType> *next;  
};

template <class ElemType>
class LinkList{
public:
	LinkList(); /*����ֻ��ͷ���Ŀյ�����*/
	LinkList(ElemType a[],int n); /*β�巨����������*/
	void PrintList(); /*��������*/
	Node<ElemType> *GetFirst(); /*����ͷָ��*/
	//friend void Merge(LinkList<ElemType> &, LinkList<ElemType> &);
private:
	Node<ElemType> *first; /*�������ͷָ��*/
};
#endif

