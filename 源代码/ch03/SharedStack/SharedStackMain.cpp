#include <iostream>
using namespace std;
#include "SharedStack.cpp"

int main() {    
    SharedStack<int> S; /*������ʵ��*/
	if(S.Empty(1) == 1)
		cout<<"ջ1Ϊ��"<<endl;
	else
        cout<<"ջ1��Ϊ��"<<endl;
	if(S.Empty(2) == 1)
		cout<<"ջ2Ϊ��"<<endl;
	else
        cout<<"ջ2��Ϊ��"<<endl;
    cout<<"1��ջ1"<<endl;
	S.Push(1, 1);
	cout<<"3��ջ1"<<endl;
	S.Push(1, 3);
	cout<<"5��ջ1"<<endl;
	S.Push(1, 5);
	cout<<"2��ջ2"<<endl;
	S.Push(2, 2);
	cout<<"4��ջ2"<<endl;
	S.Push(2, 4);
	cout<<"6��ջ2"<<endl;
	S.Push(2, 6);
	cout<<"ջ1ջ��Ԫ��Ϊ:"<<endl; 
	cout<<S.GetTop(1)<<endl;  
	cout<<"ջ2ջ��Ԫ��Ϊ:"<<endl; 
	cout<<S.GetTop(2)<<endl;  
	cout<<"ջ1��ջ"<<endl;
	S.Pop(1);
    cout<<"ջ1�µ�ջ��Ԫ��Ϊ:"<<endl; 
	cout<<S.GetTop(1)<<endl;  
	cout<<"ջ2��ջ"<<endl;
	S.Pop(2);
    cout<<"ջ2�µ�ջ��Ԫ��Ϊ:"<<endl; 
	cout<<S.GetTop(2)<<endl;  
	return 0;
}

