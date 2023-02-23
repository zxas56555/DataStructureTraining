#include <iostream>
using namespace std;
#include "string"
#include "ALGraph.cpp"

int main() {
	string ch[] = {"v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9"};
	int n, e;
	cout<<"请输入有向图的顶点数："<<endl;
	cin>>n;
	if(n < 0 || n > 10)
		throw "顶点数不合法！";
	cout<<"请输入有向图的边数："<<endl;
	cin>>e;
	if(e < 0 || e > n * (n - 1))
		throw "边数不合法！";
	ALGraph<string> ALG(ch, n, e);
	ALG.TopoSort();
	return 0;
}
