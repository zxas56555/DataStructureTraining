#include<iostream>
using namespace std;
#include "LinkList.cpp"
int main() {
	int r[10] = {1,2,5,6,7,8,9,11,12,15};
    LinkList<int> L(r, 10);
    cout<<"ִ�����ò���ǰ�ĵ���������Ϊ��"<<endl;
    L.PrintList(); /*��ʾ�����������е�Ԫ��*/
	/*����*/
	L.Reverse();
    cout<<"ִ�����ò�����ĵ���������Ϊ��"<<endl;
	L.PrintList();
	cout<<"\n�˲��������������"<<endl;
	return 0;
}
