#include <iostream>
using namespace std;
#include "LinkQueue.cpp"

int main() {    
    LinkQueue<int> Q; /*创建类实例*/
	if(Q.Empty()==1)
		cout<<"初始链队列为空"<<endl;
	else
        cout<<"初始链队列不为空"<<endl;
	cout<<"7入队"<<endl;
	Q.EnQueue(7);
    cout<<"8入队"<<endl;
	Q.EnQueue(8);
	cout<<"9入队"<<endl;
	Q.EnQueue(9);
	cout<<"10入队"<<endl;
	Q.EnQueue(10);   
	cout<<"队头元素为："<<endl; /*取队头元素*/
	cout<<Q.GetQueue()<<endl;  
	cout<<"队头出队"<<endl;
	Q.DeQueue();
    cout<<"新的队头元素为："<<endl; /*取队头元素*/
	cout<<Q.GetQueue()<<endl;  
	return 0;
}

