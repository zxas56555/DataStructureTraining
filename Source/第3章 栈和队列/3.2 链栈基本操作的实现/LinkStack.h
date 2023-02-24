#ifndef LINKSTACK_H /*避免重复引用头文件*/
#define LINKSTACK_H
template <class ElemType>
struct Node{
	ElemType data;
	Node<ElemType> *next;
};

template <class ElemType>
class LinkStack{
public:
	LinkStack(); /*构造函数，初始化空的链栈*/
	~LinkStack(); /*析构函数，释放链栈中所有的结点*/
	void Push(ElemType x); /*将x入栈*/
	ElemType Pop(); /*返回栈顶元素，并出栈*/
	ElemType GetTop(); /*取栈顶值*/
	int Empty(); /*判断是否为空栈*/
private:
	Node<ElemType> *top; /*栈顶指针*/
};
#endif

