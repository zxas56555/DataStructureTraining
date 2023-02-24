#ifndef CIRQUEUE_H
#define CIRQUEUE_H


const int QueueSize = 100; /*����ѭ�����е�����*/
template <class ElemType> /*����ģ����CirQueue*/
class CirQueue{
public:
    CirQueue(); /*���캯������ʼ��ѭ������*/
    ~CirQueue(); /*��������*/
    void EnQueue(ElemType x); /*��Ӳ���*/
    ElemType DeQueue();	/*���Ӳ��������س��ӵ�Ԫ��*/
    ElemType GetQueue(); /*ȡ��ͷ����*/
	int Length(); /*����ѭ�����е�Ԫ�ظ���*/
    int Empty(); /*�ж�ѭ�������Ƿ�Ϊ�գ��շ���1�����򷵻�0*/
private:
    ElemType data[QueueSize]; /*���ѭ������Ԫ�ص�����*/
    int front,rear; /*��ͷ����βָ��*/
};
#endif
