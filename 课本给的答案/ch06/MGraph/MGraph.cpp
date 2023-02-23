#include <iostream>
using namespace std;
#include "MGraph.h"

template <class ElemType>
MGraph<ElemType>::MGraph(ElemType a[], int n, int e) {
	int i, j, k;
	vertexNum = n;
	arcNum = e;
	/*用数组a给顶点数组赋值*/
	for(i = 0; i < vertexNum; i++) {
		vertex[i] = a[i];
	}
	/*邻接矩阵初始化*/
	for(i = 0; i < vertexNum; i++)
        for(j = 0; j < vertexNum; j++)
			arc[i][j] = 0;
	/*依次输入arcNum条边*/
	for(k = 0; k < arcNum; k++) {
		cout<<"请输入第"<<k+1<<"条边的两个顶点的序号：";
		cin>>i;
		cin>>j;
		arc[i][j]=1; 
		arc[j][i]=1;	
	}
}

template <class ElemType>
MGraph<ElemType>::~MGraph() {
} 

/*从顶点v开始进行深度优先遍历*/
template <class ElemType>
void MGraph<ElemType>::DFSTraverse(int v) {
	int j;
	/*输出顶点v*/
	cout<<vertex[v]<<" "; 
	/*将顶点v的访问标志设为1*/
	visited[v] = 1;
	for (j = 0; j < vertexNum; j++)
		if (arc[v][j] == 1 && visited[j] == 0) 
			DFSTraverse(j);
}

template <class ElemType>
void MGraph<ElemType>::DFS() {
	int i;
	/*给访问标志赋初值*/
	for(i = 0; i < vertexNum; i++)
		visited[i] = 0;
	for(i = 0; i < vertexNum; i++)
		if(visited[i] == 0)
			DFSTraverse(i);
}

template <class ElemType>
void MGraph<ElemType>::BFSTraverse(int v) {
	/*顺序队列，假设不会发生上溢*/
	int Q[MaxSize];
	int front = -1, rear = -1; /*初始化队列*/
	/*访问顶点v并将v的访问标志设为1*/
	cout<<vertex[v]<<" "; 
	visited[v] = 1;  
	/*v入队*/
	Q[++rear] = v;
	/*当队列非空时循环*/
	while(front != rear) {
		/*队头出队*/
		v = Q[++front];
		/*访问队头所有没有访问过的邻接点，并入队*/
		for(int j = 0; j < vertexNum; j++)
			if(arc[v][j] == 1 && visited[j] == 0) {
				cout<<vertex[j]<<" "; 
				visited[j] = 1; 
				Q[++rear] = j;
			}
	}
}
 
template <class ElemType>
void MGraph<ElemType>::BFS() {
	int i;
	/*给访问标志赋初值*/
	for(i = 0; i < vertexNum; i++)
		visited[i] = 0;
	for(i = 0; i < vertexNum; i++)
		if(visited[i] == 0)
			BFSTraverse(i);
}
