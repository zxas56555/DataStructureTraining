#include <iostream>
using namespace std;
#include "CirQueue.cpp"

int main() {
    CirQueue<int> Q; /*������ʵ��*/
	if(Q.Empty() == 1)
		cout<<"��ʼѭ������Ϊ��"<<endl;
	else
        cout<<"��ʼѭ�����в�Ϊ��"<<endl;
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
	cout<<"�����е�Ԫ�ظ���Ϊ��"<<endl;
	cout<<Q.Length()<<endl; /*ȡԪ�ظ���*/
	cout<<"��ͷ����"<<endl;
	Q.DeQueue();
    cout<<"�����е�Ԫ�ظ���Ϊ��"<<endl;
	cout<<Q.Length()<<endl; /*ȡԪ�ظ���*/
    cout<<"�µĶ�ͷԪ��Ϊ��"<<endl; /*ȡ��ͷԪ��*/
	cout<<Q.GetQueue()<<endl;
	cout<<"           -����Ԧ"<<endl;
	return 0;
}

