#include <iostream>
using namespace std;
#include "ALGraph.cpp"

int main() {
	char ch[MaxSize] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	int n, e;
	cout<<"请输入有向图的顶点数：(<=10)"<<endl;
	cin>>n;
	if(n < 0 || n > 10) 
		throw "顶点数异常！";
	int i;
	cout<<"请输入有向图的边数："<<endl;
	cin>>e;
	if(e < 0 || e > n * (n - 1))
		throw "边数异常！";
	ALGraph<char> ALG(ch, n, e);
	int path[100];
	/*ALG.PrintALGraph();*/
	ALG.Find(0, 9, visited, path, -1);
	return 0;
}

