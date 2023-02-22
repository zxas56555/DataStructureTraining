#include <iostream>
using namespace std;
#include "string"
#include "ALGraph.cpp"

int main() {
	string ch[] = {"v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9"};
	int n, e;
	cout<<"请输入有向图的顶点数："<<endl;
	cin>>n;
	cout<<"请输入有向图的边数："<<endl;
	cin>>e;
	ALGraph<string> ALG(ch, n, e);
	cout<<"深度优先遍历序列是：";
	ALG.DFS();
	cout<<endl;
	cout<<"广度优先遍历序列是：";
	ALG.BFS();
	cout<<endl;
	return 0;
} 
