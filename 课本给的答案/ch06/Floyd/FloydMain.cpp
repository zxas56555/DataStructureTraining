#include <iostream>
#include <iomanip>
#include <string>
#include "MGraph.cpp"
int main() {	
	string ch[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
	int n, e;
	cout<<"����������ͼ�Ķ�����(<=10)��"<<endl;
	cin>>n;
	if(n < 0 || n > 10)
		throw "���������Ϸ���";
	cout<<"����������ͼ�ı�����"<<endl;
	cin>>e;
	if(e < 0 || e > n * (n - 1))
		throw "�������Ϸ���";
	MGraph<string> M(ch, n, e);
	M.Floyd();
	return 0;
}
