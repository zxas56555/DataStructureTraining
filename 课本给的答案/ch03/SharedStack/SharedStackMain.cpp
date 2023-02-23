#include <iostream>
using namespace std;
#include "SharedStack.cpp"

int main() {    
    SharedStack<int> S; /*创建类实例*/
	if(S.Empty(1) == 1)
		cout<<"栈1为空"<<endl;
	else
        cout<<"栈1不为空"<<endl;
	if(S.Empty(2) == 1)
		cout<<"栈2为空"<<endl;
	else
        cout<<"栈2不为空"<<endl;
    cout<<"1入栈1"<<endl;
	S.Push(1, 1);
	cout<<"3入栈1"<<endl;
	S.Push(1, 3);
	cout<<"5入栈1"<<endl;
	S.Push(1, 5);
	cout<<"2入栈2"<<endl;
	S.Push(2, 2);
	cout<<"4入栈2"<<endl;
	S.Push(2, 4);
	cout<<"6入栈2"<<endl;
	S.Push(2, 6);
	cout<<"栈1栈顶元素为:"<<endl; 
	cout<<S.GetTop(1)<<endl;  
	cout<<"栈2栈顶元素为:"<<endl; 
	cout<<S.GetTop(2)<<endl;  
	cout<<"栈1出栈"<<endl;
	S.Pop(1);
    cout<<"栈1新的栈顶元素为:"<<endl; 
	cout<<S.GetTop(1)<<endl;  
	cout<<"栈2出栈"<<endl;
	S.Pop(2);
    cout<<"栈2新的栈顶元素为:"<<endl; 
	cout<<S.GetTop(2)<<endl;  
	return 0;
}

