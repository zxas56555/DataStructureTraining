#include<iostream>
using namespace std;
#include "LinkList.cpp"
int main() {
	int r[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    LinkList<int> L(r, 10);
    cout<<"执行逆置操作前的单链表数据为："<<endl;
    L.PrintList(); /*显示单链表中所有的元素*/
	/*逆置*/
	L.Reverse();
    cout<<"执行逆置操作后的单链表数据为："<<endl;
	L.PrintList();
	return 0;
}
