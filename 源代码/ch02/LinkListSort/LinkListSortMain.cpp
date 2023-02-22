#include<iostream>
using namespace std;
#include "LinkList.cpp"

int main() {
	int r1[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    LinkList<int> L1(r1, 10);
    cout<<"单链表L1为："<<endl;
    L1.PrintList(); /*显示单链表中所有的元素*/
    cout<<"L1是否已有序？";
	if(L1.IsOrdering()) {
		cout<<"有序"<<endl; 
	}
	else {
		cout<<"无序"<<endl;
	}
	int r2[8]={10, 2, -5, 90, 8, 3, 20, 33};
	LinkList<int> L2(r2, 8);
	cout<<"单链表L2为："<<endl;
	L2.PrintList();
	cout<<"L1是否已有序？";
	if(L2.IsOrdering()) {
		cout<<"有序"<<endl; 
	}
	else {
		cout<<"无序"<<endl;
		L2.Sort();
		cout<<"排序之后的L2为："<<endl;
		L2.PrintList();
	}
    return 0;
}
