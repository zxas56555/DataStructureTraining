#include <iostream>
using namespace std;
#include "Deque.cpp"

int main() {    
    Deque<int> Q; /*创建类实例*/
	if(Q.Empty() == 1)
		cout<<"初始双端队列为空"<<endl;
	else
        cout<<"初始双端队列不为空"<<endl;
	cout<<"1从右侧入队"<<endl;
	Q.EnQueue(1, 1);
    cout<<"2从右侧入队"<<endl;
	Q.EnQueue(1, 2);
	cout<<"3从右侧入队"<<endl;
	Q.EnQueue(1, 3);
	cout<<"4从左侧入队"<<endl;
	Q.EnQueue(0, 4); 
	cout<<"6从左侧入队"<<endl;
	Q.EnQueue(0, 6); 
	cout<<"5从右侧入队"<<endl;
	Q.EnQueue(1, 5);
	cout<<"双端队列为："; 
	Q.Print();
	cout<<"双端队列中的元素个数为：";
	cout<<Q.Length()<<endl;
	cout<<"左侧队头为：";
	cout<<Q.GetQueue(0)<<endl;
	cout<<"右侧队头为：";
	cout<<Q.GetQueue(1)<<endl;
	cout<<"左侧队头出队"<<endl;
	Q.DeQueue(0);
	cout<<"双端队列为：";
	Q.Print();
	cout<<"右侧队头出队"<<endl;
	Q.DeQueue(1);
	cout<<"双端队列为：";
	Q.Print();
	return 0;
}

