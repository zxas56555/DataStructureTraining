#ifndef LINKQUEUE_H /*�����ظ�����ͷ�ļ�*/
#define LINKQUEUE_H


template <class ElemType>
struct Node{
    ElemType data;
    Node<ElemType> *next;
};

template <class ElemType>
class LinkQueue{
public:
	LinkQueue(); /*����ֻ����һ��ͷ����������*/
	~LinkQueue(); /*�ͷ������������е�Ԫ�ؽ��*/
	void EnQueue(ElemType x); /*��Ӳ���*/
	ElemType DeQueue(); /*���Ӳ���*/
	ElemType GetQueue(); /*ȡ��ͷ*/
	int Empty(); /*�ж��������Ƿ�Ϊ��*/
private:
	Node<ElemType> *front, *rear; /*�����е�ͷָ���βָ��*/
};
#endif

