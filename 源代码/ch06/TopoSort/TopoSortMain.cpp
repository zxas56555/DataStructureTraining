#include <iostream>
using namespace std;
#include "string"
#include "ALGraph.cpp"

int main() {
	string ch[] = {"v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9"};
	int n, e;
	cout<<"����������ͼ�Ķ�������"<<endl;
	cin>>n;
	if(n < 0 || n > 10)
		throw "���������Ϸ���";
	cout<<"����������ͼ�ı�����"<<endl;
	cin>>e;
	if(e < 0 || e > n * (n - 1))
		throw "�������Ϸ���";
	ALGraph<string> ALG(ch, n, e);
	ALG.TopoSort();
	return 0;
}
