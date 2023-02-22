#ifndef SHAREDSTACK_H
#define SHAREDSTACK_H
const int StackSize = 100; /*���干��ջ������*/
template <class ElemType> /*����ģ����SharedStack*/
class SharedStack{
public:
    SharedStack(); /*���캯��������ջ�ĳ�ʼ��*/
	~SharedStack(); /*��������*/
    void Push(int i, ElemType x); /*Ԫ��x��ջ*/
    ElemType Pop(int i); /*����ջ��Ԫ�ص�ֵ����ջ*/
    ElemType GetTop(int i); /*����ջ��Ԫ��*/
	int Empty(int i); /*�ж�ջi�Ƿ�Ϊ�գ���Ϊ�շ���1�����򷵻�0*/
private:
    ElemType data[StackSize]; /*���ջԪ�ص�����*/
    int top1; /*ջ1ջ��ָ��*/
	int top2; /*ջ2ջ��ָ��*/
};
#endif
