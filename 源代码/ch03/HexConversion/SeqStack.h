#ifndef SEQSTACK_H
#define SEQSTACK_H
const int StackSize = 100; /*定义顺序栈的容量*/
template <class ElemType> /*定义模板类SeqStack*/
class SeqStack{
public:
    SeqStack(); /*构造函数，栈的初始化*/
    ~SeqStack(); /*析构函数*/
    void Push(ElemType x); /*元素x入栈*/
    ElemType Pop(); /*返回栈顶元素的值并出栈*/
    ElemType GetTop(); /*返回栈顶元素*/
	int Empty(); /*判断栈是否为空，若为空返回1，否则返回0*/
private:
    ElemType data[StackSize]; /*存放栈元素的数组*/
    int top; /*栈顶指针*/
};
#endif
