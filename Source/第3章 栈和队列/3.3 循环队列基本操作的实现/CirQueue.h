#ifndef CIRQUEUE_H
#define CIRQUEUE_H


const int QueueSize = 100; /*定义循环队列的容量*/
template <class ElemType> /*定义模板类CirQueue*/
class CirQueue{
public:
    CirQueue(); /*构造函数，初始化循环队列*/
    ~CirQueue(); /*析构函数*/
    void EnQueue(ElemType x); /*入队操作*/
    ElemType DeQueue();	/*出队操作，返回出队的元素*/
    ElemType GetQueue(); /*取队头操作*/
	int Length(); /*返回循环队列的元素个数*/
    int Empty(); /*判断循环队列是否为空，空返回1，否则返回0*/
private:
    ElemType data[QueueSize]; /*存放循环队列元素的数组*/
    int front,rear; /*队头，队尾指针*/
};
#endif
