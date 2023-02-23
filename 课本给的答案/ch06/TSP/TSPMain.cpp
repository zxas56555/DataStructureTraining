#include <iostream>
using namespace std;
#include "MGraph.cpp"
//int visited[MaxSize]={0};

int main() {
	char ch[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	int n, e;
	cout<<"请输入无向图的顶点数(<=10)：";
	cin>>n;
	if(n < 0 || n > 10)
		throw "顶点数不合法！";
	cout<<"请输入无向图的边数：";
	cin>>e;
	if(e < 0 || e > n * (n - 1) / 2)
		throw "边数不合法！";
	MGraph<char> M(ch, n, e);
	int v;
	cout<<"请输入起始顶点的下标：";
	cin>>v;
	if(v < 0 || v > n-1)
		throw "起始顶点下标不合法！";
	M.TSP(v); 
	return 0;
}
