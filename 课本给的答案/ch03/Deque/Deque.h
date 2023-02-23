#ifndef DEQUE_H 
#define DEQUE_H
const int QueueSize = 100; /*����˫�˶��е�����*/
/*����ģ����Deque*/
template <class ElemType> 
class Deque{
public:
    Deque(); /*���캯����˫�˶��еĳ�ʼ��*/
    ~Deque(); /*��������*/
    void EnQueue(int i, ElemType x); /*��Ӳ�����i=0��ʾ��ˣ�i=1��ʾ�Ҷ�*/ 
    ElemType DeQueue(int i); /*���Ӳ�����i=0��ʾ��ˣ�i=1��ʾ�Ҷ�*/
    ElemType GetQueue(int i); /*ȡ��ͷ������i=0��ʾ��ˣ�i=1��ʾ�Ҷ�*/
	int Length(); /*����˫�˶����а�����Ԫ�ظ���*/
    int Empty(); /*�ж�˫�˶����Ƿ�Ϊ�գ��շ���1�����򷵻�0*/
    void Print(); /*��ӡ˫�˶����е�Ԫ��*/ 
private:
    ElemType data[QueueSize]; /*���˫�˶���Ԫ�ص�����*/
    int front, rear; /*��ͷ����βָ�룬�趨��ѭ��������ͬ*/ 
};
#endif
