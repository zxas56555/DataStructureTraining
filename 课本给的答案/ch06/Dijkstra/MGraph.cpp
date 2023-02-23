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
void MGraph<ElemType>::Dijkstra(int v) {
	int dist[MaxSize]; /*存储路径长度*/ 
	string path[MaxSize]; /*存储路径*/
	int s[MaxSize]; /*已经求出最短路径的顶点*/ 
	int num; /*已经求出最短路径的顶点个数*/ 
	int i, j, k;
	/*初始化*/
	for(i = 0; i < vertexNum; i++) {
		dist[i] = arc[v][i];
		if(dist[i] != INF)
			path[i] = vertex[v] + " " + vertex[i];
		else
			path[i] = "";
	}
	/*顶点v加入集合s*/
	s[0] = v;
	num = 1;
	while(num<vertexNum) {
		/*从非零的dist[]中选取最小值*/
		/*找第一个非零的dist*/
		for(j = 0; j < vertexNum; j++) {
			if(dist[j] != 0)
				break;
		}
		/*假设第一个非零的dsit[]最小*/
		k = j;
		for(i = k + 1; i < vertexNum; i++)
			if((dist[i] != 0) && (dist[i] < dist[k]))
				k = i;
		/*v到k的最短路径求出，输出*/
		cout<<path[k]<<" : "<<dist[k]<<endl;
		/*k加入s*/
		s[num++] = k;
		/*以k作为中间顶点，更新dist[]和path[]*/ 
		for(i = 0;i < vertexNum; i++)
			if(dist[i] > dist[k] + arc[k][i]) {
				dist[i] = dist[k] + arc[k][i];
				path[i] = path[k] + " " + vertex[i];
			}
		/*避免dist[k]参与后续的比较*/ 
		dist[k] = 0;
	}	
}

