#include<iostream>
using namespace std;
#include "LinkList.cpp"

int main() {
	int r1[10] = {3,4,5,6,7,8,9,10,11,12};
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
	int r2[8]={0,-1,2,-3,4,-5,6,-7};
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
		cout<<"\n�˲��������������"<<endl;
    return 0;
}
