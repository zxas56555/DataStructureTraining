#include<iostream>
using namespace std;
#include "LinkList.cpp"

int main() {
	int r[10] = {7,6,8,5,2,5,8,5,4,9};
    LinkList<int> L(r, 10);
    cout<<"������ԭ��������Ϊ��"<<endl;
	L.PrintList();
	L.LinkListDelNormalDup();
	cout<<"ɾ���ظ���Ԫ��֮��ĵ���������Ϊ��"<<endl;
	L.PrintList();
	cout<<"\n�˲��������������"<<endl;
	return 0;
}
