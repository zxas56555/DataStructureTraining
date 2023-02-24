#include<iostream>
using namespace std;
#include "LinkList.cpp"
int main() {
	int r[10] = {1,2,5,6,7,8,9,11,12,15};
    LinkList<int> L(r, 10);
    cout<<"执行逆置操作前的单链表数据为："<<endl;
    L.PrintList(); /*显示单链表中所有的元素*/
	/*逆置*/
	L.Reverse();
    cout<<"执行逆置操作后的单链表数据为："<<endl;
	L.PrintList();
	cout<<"\n此部分由刘宪铎完成"<<endl;
	return 0;
}
