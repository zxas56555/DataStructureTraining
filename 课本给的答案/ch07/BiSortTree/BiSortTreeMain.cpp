#include <iostream>
using namespace std;
#include "BiSortTree.cpp"
int main() {
	int a[] = {61, 87, 59, 47, 35, 73, 51, 98, 37, 93};
	int n, i, k;
	cout<<"���������������������(<=10)��";
	cin>>n;
	if(n < 0 || n > 10)
		throw "��������"; 
	BiSortTree T(a, n);
	cout<<"����Ķ��������������������Ϊ��"<<endl;
	T.InOrder();
	cout<<endl;
	cout<<"������Ҫ���ҵĹؼ���ֵ��";
	cin>>k;
	if(T.Search(k) == NULL)
		cout<<"�����������в����ڹؼ���"<<k<<"!";
	else
		cout<<"�����������д��ڹؼ���"<<k<<"!"; 
	cout<<endl;
	cout<<"ɾ���ؼ���47"<<endl;
	T.DeleteBST(T.Search(47),T.Search(59));
	cout<<"ɾ��47�Ժ�Ķ������������������Ϊ��"<<endl;
	T.InOrder();
	return 0;
}
