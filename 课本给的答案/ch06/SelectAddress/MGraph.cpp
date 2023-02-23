#include <iostream>
#include <iomanip>
#include <string>
#define INF 32767
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
void MGraph<ElemType>::SelectAddressByFloyd() {
	int dist[MaxSize][MaxSize];
	int maxShortest[MaxSize];
	int i, j, k;
	for(i = 0; i < vertexNum; i++)
		for(j = 0; j < vertexNum; j++) {
			dist[i][j] = arc[i][j];
		}
	/*依次使用顶点k作为中间顶点试探*/
	for(k = 0; k < vertexNum; k++) {
		for(i = 0; i < vertexNum; i++)
			for(j = 0; j < vertexNum; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
	}
	/*选择dist[][]每一行的最大值存入maxShortest[]*/
	for(i = 0; i < vertexNum; i++) {
		k = 0;
		for(j = k + 1; j < vertexNum; j++) {
			if(dist[i][j] > dist[i][k])
				k = j;
		}
		maxShortest[i] = dist[i][k];
	}
	/*在maxShortest[]中找最小值并输出对应的顶点*/
	k = 0;
	for(j = k + 1; j < vertexNum; j++) {
		if(maxShortest[j] < maxShortest[k])
			k = j;
	}
	cout<<endl<<"地址应选择在顶点"<<vertex[k]<<"处"<<endl;	
}

