#ifndef LINKQUEUE_H /*避免重复引用头文件*/
#define LINKQUEUE_H


template <class ElemType>
struct Node{
    ElemType data;
    Node<ElemType> *next;
};

template <class ElemType>
class LinkQueue{
public:
	LinkQueue(); /*创建只包含一个头结点的链队列*/
	~LinkQueue(); /*释放链队列中所有的元素结点*/
	void EnQueue(ElemType x); /*入队操作*/
	ElemType DeQueue(); /*出队操作*/
	ElemType GetQueue(); /*取队头*/
	int Empty(); /*判断链队列是否为空*/
private:
	Node<ElemType> *front, *rear; /*链队列的头指针和尾指针*/
};
#endif

