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
	~LinkList(); /*��������*/
	void Reverse(); /*���ò���*/
	void PrintList(); /*��������*/
private:
	Node<ElemType> *first; /*�������ͷָ��*/
};
#endif

