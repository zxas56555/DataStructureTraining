#include <iostream>
using namespace std;
#include "LinkList.cpp"
int main() {
	int r[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    LinkList<int> L(r, 10);
    cout<<"执行插入操作前的单链表数据为："<<endl;
    L.PrintList(); /*显示单链表中所有的元素*/
    try{
		L.Insert(7, 12);
	}
    catch (char *str) {
        cout<<str<<endl;
	}
    cout<<"执行插入操作后的单链表数据为："<<endl;
    L.PrintList(); /*显示单链表中所有元素*/
    cout<<"值为15的元素位置为:";
    cout<<L.Locate(15)<<endl; /*查找元素15，并返回在单链表中位置*/
    int length = L.Length();
	cout<<"当前单链表的表长为："<<length<<endl;
    cout<<"执行删除操作前数据为："<<endl;     
    L.PrintList(); /*显示单链表中所有的元素*/
    try{
		L.Delete(6); /*删除第6个元素结点*/
	}
    catch (char *str) {
		cout<<str<<endl;
	}
    cout<<"执行删除操作后数据为："<<endl; 
    L.PrintList(); /*显示单链表中所有元素*/
    return 0;
}
