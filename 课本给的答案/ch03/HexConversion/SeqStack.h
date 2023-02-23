#ifndef SEQSTACK_H
#define SEQSTACK_H
const int StackSize = 100; /*����˳��ջ������*/
template <class ElemType> /*����ģ����SeqStack*/
class SeqStack{
public:
    SeqStack(); /*���캯����ջ�ĳ�ʼ��*/
    ~SeqStack(); /*��������*/
    void Push(ElemType x); /*Ԫ��x��ջ*/
    ElemType Pop(); /*����ջ��Ԫ�ص�ֵ����ջ*/
    ElemType GetTop(); /*����ջ��Ԫ��*/
	int Empty(); /*�ж�ջ�Ƿ�Ϊ�գ���Ϊ�շ���1�����򷵻�0*/
private:
    ElemType data[StackSize]; /*���ջԪ�ص�����*/
    int top; /*ջ��ָ��*/
};
#endif
