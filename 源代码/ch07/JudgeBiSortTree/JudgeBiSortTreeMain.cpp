#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree T;
	cout<<"�������������������Ϊ��";
	T.InOrder();
	cout<<endl;
	int flag = 1;
	flag = T.IsBiSortTree();
	if(flag)
		cout<<"�������Ƕ�����������";
	else
		cout<<"���������Ƕ�����������"; 
	return 0;
}
