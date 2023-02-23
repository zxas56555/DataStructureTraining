#include <iostream>
using namespace std;
#include "MGraph.h"

template <class ElemType>
MGraph<ElemType>::MGraph(ElemType a[],int n,int e) {
	int i, j, k, weight;
	vertexNum = n;
	arcNum = e;
	/*用数组a给顶点数组赋值*/
	for(i = 0; i < vertexNum; i++) {
		vertex[i] = a[i];
	}
	/*邻接矩阵初始化*/
	for(i = 0; i < vertexNum; i++)
        for(j = 0; j < vertexNum; j++)
			arc[i][j] = MaxWeight;
	/*依次输入arcNum条边*/
	for(k = 0; k < arcNum; k++) {
		cout<<"请输入第"<<k + 1<<"条边的两个顶点的序号：";
		cin>>i>>j>>weight;
		arc[i][j] = weight; 
		arc[j][i] = weight;	
	}
}

template <class ElemType>
int MGraph<ElemType>::Min(int a[],int n) {
	int start = 0, min = a[0], k=0;
	/*寻找还没有访问过的顶点start*/
 	while(visited[start] == 1) {
  		start++;
  		min = a[start];
 	}
 	/*寻找依附于顶点start的边中权值最小的边依附的另一个顶点*/ 
 	for(; start < n; start++) {
  		if(visited[start] == 0 && min >= a[start]) {
   			k = start;
   			min = a[k];
  		}
 	}
 	return k;
} 

template <class ElemType>
void MGraph<ElemType>::TSP(int v) {
	int path = 0;
 	cout<<"路径为：";
 	cout<<vertex[v];
 	visited[v] = 1;
 	int i = 0, j = 0;
 	int log = 0;
 	for(; log < vertexNum; log++) {
  		j = Min(arc[i],vertexNum);
  		visited[j] = 1;
  		cout<<"->"<<vertex[j];
  		path += arc[i][j];
  		i = j;
 	}
 	cout<<endl;
 	cout<<"路径长度为："<<path<<endl;
}
