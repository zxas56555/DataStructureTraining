#include<iostream>
using namespace std;
#include "LinkList.cpp"

int main() {
	int r1[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    LinkList<int> L1(r1, 10);
    cout<<"������L1Ϊ��"<<endl;
    L1.PrintList(); /*��ʾ�����������е�Ԫ��*/
    cout<<"L1�Ƿ�������";
	if(L1.IsOrdering()) {
		cout<<"����"<<endl; 
	}
	else {
		cout<<"����"<<endl;
	}
	int r2[8]={10, 2, -5, 90, 8, 3, 20, 33};
	LinkList<int> L2(r2, 8);
	cout<<"������L2Ϊ��"<<endl;
	L2.PrintList();
	cout<<"L1�Ƿ�������";
	if(L2.IsOrdering()) {
		cout<<"����"<<endl; 
	}
	else {
		cout<<"����"<<endl;
		L2.Sort();
		cout<<"����֮���L2Ϊ��"<<endl;
		L2.PrintList();
	}
    return 0;
}
