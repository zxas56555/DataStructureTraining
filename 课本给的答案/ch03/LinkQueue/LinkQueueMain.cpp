#include <iostream>
using namespace std;
#include "LinkQueue.cpp"

int main() {    
    LinkQueue<int> Q; /*������ʵ��*/
	if(Q.Empty()==1)
		cout<<"��ʼ������Ϊ��"<<endl;
	else
        cout<<"��ʼ�����в�Ϊ��"<<endl;
	cout<<"7���"<<endl;
	Q.EnQueue(7);
    cout<<"8���"<<endl;
	Q.EnQueue(8);
	cout<<"9���"<<endl;
	Q.EnQueue(9);
	cout<<"10���"<<endl;
	Q.EnQueue(10);   
	cout<<"��ͷԪ��Ϊ��"<<endl; /*ȡ��ͷԪ��*/
	cout<<Q.GetQueue()<<endl;  
	cout<<"��ͷ����"<<endl;
	Q.DeQueue();
    cout<<"�µĶ�ͷԪ��Ϊ��"<<endl; /*ȡ��ͷԪ��*/
	cout<<Q.GetQueue()<<endl;  
	return 0;
}

