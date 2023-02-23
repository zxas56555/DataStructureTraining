#include <iostream>
using namespace std;
#include "SeqStack.cpp"

int main() {    
    SeqStack<int> S; /*创建类实例*/
	if(S.Empty() == 1)
		cout<<"初始栈为空"<<endl;
	else
        cout<<"初始栈不为空"<<endl;
    cout<<"8入栈"<<endl;
	S.Push(8);
	cout<<"9入栈"<<endl;
	S.Push(9);
	cout<<"10入栈"<<endl;
	S.Push(10);   
	cout<<"栈顶元素为:"<<endl; /*取栈顶元素*/
	cout<<S.GetTop()<<endl;  
	cout<<"栈顶出栈"<<endl;
	S.Pop(); /*出栈*/
    cout<<"新的栈顶元素为:"<<endl;
    cout<<S.GetTop()<<endl;	
    return 0;
}

