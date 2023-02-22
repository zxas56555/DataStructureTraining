#include <iostream>
#include <iomanip>
using namespace std;
#include "MGraph.h" /*引入头文件

/*候选最短边集元素*/
struct element{
	int lowcost;
	int adjvex;
};

template <class ElemType>
MGraph<ElemType>::MGraph(ElemType a[], int n, int e) {
	int i, j, k, w;
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
				arc[i][j] = 32767;
		}
	/*依次输入arcNum条边*/
	for(k = 0; k < arcNum; k++) {
		cout<<"请输入第"<<k + 1<<"条边的两个顶点的序号及权值，用空格隔开：";
		cin>>i;
		cin>>j;
		cin>>w;
		arc[i][j] = w; 
		arc[j][i] = w;	
	}
}

template <class ElemType>
void MGraph<ElemType>::Print() {
	cout<<"顶点数为："<<vertexNum<<endl;
	cout<<"边数为："<<arcNum<<endl;
	cout<<"邻接矩阵为："<<endl;
	int i, j;
	for(i = 0; i < vertexNum; i++) {
		for(j=0; j < vertexNum; j++) {
			cout<<setw(6)<<arc[i][j];
		}
		cout<<endl;
	}
}

template <class ElemType>
void MGraph<ElemType>::Prim() {
	element shortEdge[MaxSize];
    int k, i, j;
	/*初始化辅助数组shortEdge*/
	for(i = 1; i < vertexNum; i++) {
		shortEdge[i].lowcost = arc[0][i];
		shortEdge[i].adjvex = 0;
	}
	/*顶点0加入集合U*/
	shortEdge[0].lowcost = 0;
	cout<<"Prim算法求解的最小生成树包括的边为："<<endl;
	for(i = 1; i < vertexNum; i++) {
		/*寻找最短边的邻接点k*/
		/*k设初值*/
		for(j = 1; j < vertexNum; j++) {
			if(shortEdge[j].lowcost != 0) {
				k = j;
				break;
			}
		}
		/*选取k*/
		for(j = 1; j < vertexNum; j++) {
			if(shortEdge[j].lowcost != 0 && shortEdge[j].lowcost < shortEdge[k].lowcost)
				k = j;
		}
		cout<<"("<<vertex[k]<<", "<<vertex[shortEdge[k].adjvex]<<"), "<<shortEdge[k].lowcost<<endl;
		/*顶点k加入集合U中*/
		shortEdge[k].lowcost = 0;
		/*调整数组shortEdge*/
		for(j = 1; j < vertexNum; j++) {
			if(arc[k][j] < shortEdge[j].lowcost) {
				shortEdge[j].lowcost = arc[k][j];
				shortEdge[j].adjvex = k;
			}
		}
	}
}
