#include <iostream>
#include <iomanip>
using namespace std;
#include "EdgeGraph.h"  
#include "FindRoot.cpp"

template <class ElemType>
EdgeGraph<ElemType>::EdgeGraph(ElemType a[], int n, int e) {
	int i, k;
	vertexNum = n;
	edgeNum = e;
	/*用数组a给顶点数组赋值*/
	for(i = 0; i < vertexNum; i++) {
		vertex[i] = a[i];
	}
	/*依次输入edgeNum条边*/
	for(k = 0; k < edgeNum; k++) {
		cout<<"请输入第"<<k + 1<<"条边的两个顶点的序号及权值，用空格隔开：";
		cin>>edge[k].from;
		cin>>edge[k].to;
		cin>>edge[k].weight;
	}
}

template <class ElemType>
void EdgeGraph<ElemType>::Sort() {
	/*利用冒泡排序对无向连通网的边集数组进行排序*/
	int exchange, bound;
	int j;
	EdgeType temp;
	exchange = edgeNum-1;
	while(exchange != -1) {
		bound = exchange;
		exchange = -1;
		for(j = 0; j < bound; j++)
			if(edge[j].weight > edge[j+1].weight) {
				temp = edge[j];
				edge[j] = edge[j+1];
				edge[j+1] = temp;
				exchange = j;
			}
	}
}

template <class ElemType>
void EdgeGraph<ElemType>::Print() {
	cout<<"顶点数为："<<vertexNum<<endl;
	cout<<"边数为："<<edgeNum<<endl;
	cout<<"边集数组为："<<endl;
	int i;
	for(i = 0; i < edgeNum; i++) {
		cout<<setw(3)<<edge[i].from<<setw(3)<<edge[i].to<<setw(3)<<edge[i].weight<<endl;
	}
}

template <class ElemType>
void EdgeGraph<ElemType>::Kruscal() {
	int parent[MaxSize];
	int i, num;
	/*初始化parent[]数组*/
	for(i = 0; i < vertexNum; i++)
		parent[i] = -1;
	/*记录合并连通分量的次数*/
	num = 0;
	int vex1, vex2;
	cout<<"Kruscal算法求解的最小生成树中包括的边为："<<endl;
	/*按权值从小到大处理已排好序的边集数组的每一条边*/
	for(i = 0; i < edgeNum; i++) {
		/*寻找两个顶点所在连通分量的根*/
		vex1 = FindRoot(parent, edge[i].from);
		cout<<"vex1="<<vex1<<endl;
		vex2 = FindRoot(parent, edge[i].to);
		cout<<"vex2="<<vex2<<endl;
		/*边的两个顶点不在同一个连通分量*/ 
		if(vex1 != vex2) {
			/*输出边*/ 
			cout<<"("<<vertex[edge[i].from]<<", "<<vertex[edge[i].to]<<"), "<<edge[i].weight<<endl;
			/*合并连通分量*/
			parent[vex2] = vex1;
			num++;
			/*已合并n - 1次，结束*/
			if(num == vertexNum - 1)
				return;
		}
	}
}
