#include <iostream>
#include "MGraph.cpp"
int main() {	
	char ch[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	int n, e;
	cout<<"����������ͼ�Ķ�����(<=10)��"<<endl;
	cin>>n;
	if(n < 0 || n > 10)
		throw "���������Ϸ���";
	cout<<"����������ͼ�ı�����"<<endl;
	cin>>e;
	if(e < 0 || e > n * (n - 1))
		throw "�������Ϸ���";
	MGraph<char> M(ch, n, e);
	M.SelectAddressByFloyd();
	return 0;
}
