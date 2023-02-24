#ifndef LINKSTACK_H /*�����ظ�����ͷ�ļ�*/
#define LINKSTACK_H
template <class ElemType>
struct Node{
	ElemType data;
	Node<ElemType> *next;
};

template <class ElemType>
class LinkStack{
public:
	LinkStack(); /*���캯������ʼ���յ���ջ*/
	~LinkStack(); /*�����������ͷ���ջ�����еĽ��*/
	void Push(ElemType x); /*��x��ջ*/
	ElemType Pop(); /*����ջ��Ԫ�أ�����ջ*/
	ElemType GetTop(); /*ȡջ��ֵ*/
	int Empty(); /*�ж��Ƿ�Ϊ��ջ*/
private:
	Node<ElemType> *top; /*ջ��ָ��*/
};
#endif

