#include <iostream>
using namespace std;
#include "SeqStack.cpp"

int main() {    
    SeqStack<int> S; /*������ʵ��*/
	if(S.Empty() == 1)
		cout<<"��ʼջΪ��"<<endl;
	else
        cout<<"��ʼջ��Ϊ��"<<endl;
    cout<<"8��ջ"<<endl;
	S.Push(8);
	cout<<"9��ջ"<<endl;
	S.Push(9);
	cout<<"10��ջ"<<endl;
	S.Push(10);   
	cout<<"ջ��Ԫ��Ϊ:"<<endl; /*ȡջ��Ԫ��*/
	cout<<S.GetTop()<<endl;  
	cout<<"ջ����ջ"<<endl;
	S.Pop(); /*��ջ*/
    cout<<"�µ�ջ��Ԫ��Ϊ:"<<endl;
    cout<<S.GetTop()<<endl;	
    return 0;
}

