#include <iostream>
using namespace std;
#include "string"
#include "ALGraph.cpp"

int main() {
	string ch[] = {"v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9"};
	int n, e;
	cout<<"����������ͼ�Ķ�������"<<endl;
	cin>>n;
	cout<<"����������ͼ�ı�����"<<endl;
	cin>>e;
	ALGraph<string> ALG(ch, n, e);
	cout<<"������ȱ��������ǣ�";
	ALG.DFS();
	cout<<endl;
	cout<<"������ȱ��������ǣ�";
	ALG.BFS();
	cout<<endl;
	return 0;
} 
