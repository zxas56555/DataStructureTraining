#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "MGraph.h" /*引入头文件*/

template <class ElemType>
MGraph<ElemType>::MGraph(ElemType a[], int n, int e) {
	int i, j, w, k;
	vertexNum = n;
	arcNum = e;
	/*用数组a给顶点数组赋值*/
	for(i = 0; i < vertexNum; i++) {
		vertex[i] = a[i];
	}
	/*邻接矩阵初始化*/
	for(i = 0; i < vertexNum; i++)
        for(j = 0; j < vertexNum; j++) {
			if(i == j)
				arc[i][j] = 0;
			else 
				arc[i][j] = INF;
		}
	/*依次输入arcNum条边*/
	for(k = 0; k < arcNum; k++) {
		cout<<"请输入第"<<k + 1<<"条边的两个顶点的序号及权值，使用空格隔开：";
		cin>>i;
		cin>>j;
		cin>>w;
		arc[i][j] = w; 
	}
}

template <class ElemType>
void MGraph<ElemType>::Floyd() {
	int dist[MaxSize][MaxSize];
	string path[MaxSize][MaxSize];
	int i, j, k;
	/*dist, path初始化*/
	for(i = 0; i < vertexNum; i++)
		for(j = 0; j < vertexNum; j++) {
			dist[i][j] = arc[i][j];
			if(dist[i][j] != INF)
				path[i][j] = vertex[i]+vertex[j];
			else 
				path[i][j] = "";
		}
	/*依次使用顶点k作为中间顶点试探*/
	for(k = 0; k < vertexNum; k++) {
		for(i = 0; i < vertexNum; i++)
			for(j = 0; j < vertexNum; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k] + vertex[j];
				}
	}
	/*输出结果*/
	cout<<"最短路径分别为："<<endl;
	for(i = 0; i < vertexNum; i++) {
		for(j = 0; j < vertexNum; j++) {
			if(i != j) {
				cout<<vertex[i]<<"-->"<<vertex[j]<<" : ";
				cout<<dist[i][j]<<"("<<path[i][j]<<")"<<" ";
				cout<<endl;
			}
		}
	}
}
