#include <iostream>
using namespace std;
#include "MGraph.cpp"
//int visited[MaxSize]={0};

int main() {
	char ch[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	int n, e;
	cout<<"����������ͼ�Ķ�����(<=10)��";
	cin>>n;
	if(n < 0 || n > 10)
		throw "���������Ϸ���";
	cout<<"����������ͼ�ı�����";
	cin>>e;
	if(e < 0 || e > n * (n - 1) / 2)
		throw "�������Ϸ���";
	MGraph<char> M(ch, n, e);
	int v;
	cout<<"��������ʼ������±꣺";
	cin>>v;
	if(v < 0 || v > n-1)
		throw "��ʼ�����±겻�Ϸ���";
	M.TSP(v); 
	return 0;
}
