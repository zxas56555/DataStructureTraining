#include <iostream>
#include "LinkList.cpp"
using namespace std;
int main() {
	int r[10] = {3,6,8,9,1,12,16,18,20,19};
    LinkList<int> L(r, 10);
    cout<<"执行插入操作前的单链表数据为："<<endl;
    L.PrintList(); /*显示单链表中所有的元素*/
    try{
		L.Insert(3, 0);
	}
    catch (char *str) {
        cout<<str<<endl;
	}
    cout<<"执行插入操作后的单链表数据为："<<endl;
    L.PrintList(); /*显示单链表中所有元素*/
    cout<<"值为18的元素位置为:";
    cout<<L.Locate(18)<<endl; /*查找元素18，并返回在单链表中位置*/
    int length = L.Length();
	cout<<"当前单链表的表长为："<<length<<endl;
    cout<<"执行删除操作前数据为："<<endl;
    L.PrintList(); /*显示单链表中所有的元素*/
    try{
		L.Delete(8); /*删除第8个元素结点*/
	}
    catch (char *str) {
		cout<<str<<endl;
	}
    cout<<"执行删除操作后数据为："<<endl;
    L.PrintList(); /*显示单链表中所有元素*/
    cout<<"\n此部分由刘宪铎完成"<<endl;
    return 0;
}
