#include <iostream>
using namespace std;
#include "Deque.cpp"

int main() {    
    Deque<int> Q; /*������ʵ��*/
	if(Q.Empty() == 1)
		cout<<"��ʼ˫�˶���Ϊ��"<<endl;
	else
        cout<<"��ʼ˫�˶��в�Ϊ��"<<endl;
	cout<<"1���Ҳ����"<<endl;
	Q.EnQueue(1, 1);
    cout<<"2���Ҳ����"<<endl;
	Q.EnQueue(1, 2);
	cout<<"3���Ҳ����"<<endl;
	Q.EnQueue(1, 3);
	cout<<"4��������"<<endl;
	Q.EnQueue(0, 4); 
	cout<<"6��������"<<endl;
	Q.EnQueue(0, 6); 
	cout<<"5���Ҳ����"<<endl;
	Q.EnQueue(1, 5);
	cout<<"˫�˶���Ϊ��"; 
	Q.Print();
	cout<<"˫�˶����е�Ԫ�ظ���Ϊ��";
	cout<<Q.Length()<<endl;
	cout<<"����ͷΪ��";
	cout<<Q.GetQueue(0)<<endl;
	cout<<"�Ҳ��ͷΪ��";
	cout<<Q.GetQueue(1)<<endl;
	cout<<"����ͷ����"<<endl;
	Q.DeQueue(0);
	cout<<"˫�˶���Ϊ��";
	Q.Print();
	cout<<"�Ҳ��ͷ����"<<endl;
	Q.DeQueue(1);
	cout<<"˫�˶���Ϊ��";
	Q.Print();
	return 0;
}

