#include <iostream>
#include <string>
#include "EdgeGraph.cpp"
int main() {	
	string ch[] = {"v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9"};
	int n, e;
	cout<<"����������ͼ�Ķ�����(<=10)��"<<endl;
	cin>>n;
	if(n < 0 || n > 10)
		throw "���������Ϸ���";
	cout<<"����������ͼ�ı�����"<<endl;
	cin>>e;
	if(e < 0 || e > n * (n - 1) / 2)
		throw "�������Ϸ���";
	EdgeGraph<string> M(ch, n, e);
	M.Sort();
	M.Kruscal();
	return 0;
}
