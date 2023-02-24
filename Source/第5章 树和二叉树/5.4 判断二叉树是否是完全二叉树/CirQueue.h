#ifndef CIRQUEUE_H
#define CIRQUEUE_H

using namespace std;

const int QueueSize = 100; /*����ѭ�����е�����*/
template <class ElemType> /*����ģ����CirQueue*/
class CirQueue{
public:
    CirQueue(); /*���캯����ѭ�����еĳ�ʼ��*/
    void EnQueue(ElemType x); /*��Ӳ���*/
    ElemType DeQueue(); /*���Ӳ���*/
    int Empty(); /*�ж϶����Ƿ�Ϊ�գ���Ϊ�շ���1�����򷵻�0*/
private:
    ElemType data[QueueSize]; /*��Ŷ���Ԫ�ص�����*/
    int front, rear; /*��ͷ����βָ��*/
};
#endif
