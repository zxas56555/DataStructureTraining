#include<iostream>
using namespace std;
#include "LinkList.cpp"

int main() {
	int r[13] = {1, 2, 2, 5, 5, 5, 9, 11, 11, 13, 13, 17, 19};
    LinkList<int> L(r, 13);
    cout<<"单链表原来的数据为："<<endl;
	L.PrintList();
	L.LinkListDelDup();
	cout<<"删除重复的元素之后的单链表数据为："<<endl; 
	L.PrintList();
	return 0;
}
