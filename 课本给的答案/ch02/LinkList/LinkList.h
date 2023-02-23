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
	LinkList(ElemType a[], int n); /*β�巨����������*/
	~LinkList(); /*��������*/
	int Length(); /*���ص�����ı�*/
	ElemType Get(int i); /*��λ���ң����ص�i��Ԫ�ص�ֵ*/
	int Locate(ElemType x); /*��ֵ����*/
	void Insert(int i, ElemType x); /*�������*/
	ElemType Delete(int i); /*ɾ������*/
	void PrintList(); /*��������*/
private:
	Node<ElemType> *first; /*ͷָ��*/
};
#endif

