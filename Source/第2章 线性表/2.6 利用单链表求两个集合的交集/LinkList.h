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
	LinkList(); /*�޲ι��캯��������ֻ��ͷ���Ŀյ�����*/
	LinkList(ElemType a[], int n); /*�вι��캯����ʹ��β�巨������n��Ԫ�ؽ��ĵ�����*/
	int Locate(ElemType x); /*�ڵ������а�ֵ���ң������ڣ��������*/
	void PrintList(); /*������������������������Ԫ��*/
	Node<ElemType> *GetFirst(); /*����ͷָ��*/
private:
	Node<ElemType> *first; /*�������ͷָ��*/
};
#endif

