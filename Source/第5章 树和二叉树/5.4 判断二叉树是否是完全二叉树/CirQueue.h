#ifndef CIRQUEUE_H
#define CIRQUEUE_H

using namespace std;

const int QueueSize = 100; /*定义循环队列的容量*/
template <class ElemType> /*定义模板类CirQueue*/
class CirQueue{
public:
    CirQueue(); /*构造函数，循环队列的初始化*/
    void EnQueue(ElemType x); /*入队操作*/
    ElemType DeQueue(); /*出队操作*/
    int Empty(); /*判断队列是否为空，若为空返回1，否则返回0*/
private:
    ElemType data[QueueSize]; /*存放队列元素的数组*/
    int front, rear; /*队头，队尾指针*/
};
#endif
