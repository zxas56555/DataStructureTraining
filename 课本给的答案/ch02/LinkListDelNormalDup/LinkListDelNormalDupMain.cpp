#include<iostream>
using namespace std;
#include "LinkList.cpp"

int main() {
	int r[10] = {7,5,7,9,5,2,3,5,7,9};
    LinkList<int> L(r, 10);
    cout<<"������ԭ��������Ϊ��"<<endl;
	L.PrintList();
	L.LinkListDelNormalDup();
	cout<<"ɾ���ظ���Ԫ��֮��ĵ���������Ϊ��"<<endl; 
	L.PrintList();
	return 0;
}
