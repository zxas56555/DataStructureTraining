#ifndef DEQUE_H 
#define DEQUE_H
const int QueueSize = 100; /*定义双端队列的容量*/
/*定义模板类Deque*/
template <class ElemType> 
class Deque{
public:
    Deque(); /*构造函数，双端队列的初始化*/
    ~Deque(); /*析构函数*/
    void EnQueue(int i, ElemType x); /*入队操作，i=0表示左端，i=1表示右端*/ 
    ElemType DeQueue(int i); /*出队操作，i=0表示左端，i=1表示右端*/
    ElemType GetQueue(int i); /*取队头操作，i=0表示左端，i=1表示右端*/
	int Length(); /*返回双端队列中包含的元素个数*/
    int Empty(); /*判断双端队列是否为空，空返回1，否则返回0*/
    void Print(); /*打印双端队列中的元素*/ 
private:
    ElemType data[QueueSize]; /*存放双端队列元素的数组*/
    int front, rear; /*队头，队尾指针，设定与循环队列相同*/ 
};
#endif
