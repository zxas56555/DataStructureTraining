#include<iostream>
using namespace std;
#include "LinkList.cpp"

int main() {
	int r[13] = {1, 2, 2, 5, 5, 5, 9, 11, 11, 13, 13, 17, 19};
    LinkList<int> L(r, 13);
    cout<<"������ԭ��������Ϊ��"<<endl;
	L.PrintList();
	L.LinkListDelDup();
	cout<<"ɾ���ظ���Ԫ��֮��ĵ���������Ϊ��"<<endl; 
	L.PrintList();
	return 0;
}
