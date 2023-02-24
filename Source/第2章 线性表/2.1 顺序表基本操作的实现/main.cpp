#include <iostream>
using namespace std; /*使用std命名空间，避免命名冲突*/
#include "SeqList.cpp"

int main() {
    int r[10] = {3,6,9,15,17,13,12,15,11,20};
    SeqList<int> L(r, 10);
    cout<<"执行插入操作前数据为："<<endl;
    L.PrintList(); /*输出所有元素*/
    try{
		L.Insert(6, 16);
	}
    catch(char *str) {
        cout<<str<<endl;
    }
    cout<<"执行插入操作后数据为："<<endl;
    L.PrintList(); /*输出所有元素*/
    cout<<"值为16的元素位置为:";
    cout<<L.Locate(11)<<endl; /*查找元素11，并返回在顺序表中的位置*/
    cout<<"执行删除第7个元素操作，删除前数据为："<<endl;
    L.PrintList(); /*输出所有元素*/
    try{
		L.Delete(9); /*删除第9个元素*/
	}
    catch(char *str) {
		cout<<str<<endl;
	}
    cout<<"删除后数据为："<<endl;
    L.PrintList(); /*输出所有元素*/
    cout<<"\n此部分由刘宪铎完成"<<endl;
    return 0;
}
