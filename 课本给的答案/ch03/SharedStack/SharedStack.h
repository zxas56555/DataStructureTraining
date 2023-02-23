#ifndef SHAREDSTACK_H
#define SHAREDSTACK_H
const int StackSize = 100; /*定义共享栈的容量*/
template <class ElemType> /*定义模板类SharedStack*/
class SharedStack{
public:
    SharedStack(); /*构造函数，共享栈的初始化*/
	~SharedStack(); /*析构函数*/
    void Push(int i, ElemType x); /*元素x入栈*/
    ElemType Pop(int i); /*返回栈顶元素的值并出栈*/
    ElemType GetTop(int i); /*返回栈顶元素*/
	int Empty(int i); /*判断栈i是否为空，若为空返回1，否则返回0*/
private:
    ElemType data[StackSize]; /*存放栈元素的数组*/
    int top1; /*栈1栈顶指针*/
	int top2; /*栈2栈顶指针*/
};
#endif
