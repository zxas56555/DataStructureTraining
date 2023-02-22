#include<iostream>
using namespace std;
#include "LinkList.cpp"

int main() {
	int r[10] = {7,5,7,9,5,2,3,5,7,9};
    LinkList<int> L(r, 10);
    cout<<"单链表原来的数据为："<<endl;
	L.PrintList();
	L.LinkListDelNormalDup();
	cout<<"删除重复的元素之后的单链表数据为："<<endl; 
	L.PrintList();
	return 0;
}
