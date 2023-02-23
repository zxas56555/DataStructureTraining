#include <iostream>
using namespace std; /*使用std命名空间，避免命名冲突*/
#include "SeqList.cpp"
int main() {
    int r[10] = {4, 2, 6, 8, 12, 10, 14, 16, 19, 18};
    SeqList<int> L(r, 10);
    cout<<"执行插入操作前数据为："<<endl;
    L.PrintList(); /*输出所有元素*/
    try{
		L.Insert(6, 11);
	}
    catch(char *str) {
        cout<<str<<endl;
    }
    cout<<"执行插入操作后数据为："<<endl;
    L.PrintList(); /*输出所有元素*/
    cout<<"值为16的元素位置为:";
    cout<<L.Locate(16)<<endl; /*查找元素16，并返回在顺序表中的位置*/
    cout<<"执行删除第7个元素操作，删除前数据为："<<endl;
    L.PrintList(); /*输出所有元素*/
    try{
		L.Delete(7); /*删除第7个元素*/
	}
    catch(char *str) {
		cout<<str<<endl;
	}
    cout<<"删除后数据为："<<endl;
    L.PrintList(); /*输出所有元素*/
    return 0;
}
