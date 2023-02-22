#include <iostream>
using namespace std;
#include "ALGraph.h"

template <class ElemType>
ALGraph<ElemType>::ALGraph(ElemType a[], int n, int e) {
	ArcNode *s;
	int i, j, k;
	vertexNum = n; 
	arcNum = e;
	/*初始化顶点表*/
	for(i = 0; i < n; i++) { 
		adjlist[i].in = 0;
		adjlist[i].vertex = a[i];
		adjlist[i].firstEdge = NULL;      
	}
    /*依次输入每一条边*/
	for (k = 0; k < e; k++) { 
		cout<<"请输入第"<<k + 1<<"条边的两个顶点的序号：";
		cin>>i>>j;
		/*生成新的边表结点s*/
		s = new ArcNode; 
		s->adjvex = j;
		/*顶点j的入度值加1*/
		adjlist[j].in++;
		/*使用头插法将s插入到边表中*/
		s->next = adjlist[i].firstEdge;
		adjlist[i].firstEdge = s;
	}
}

template <class ElemType>
void ALGraph<ElemType>::TopoSort() {
	int S[MaxSize]; /*顺序栈，假设不会产生上溢*/
	int top = -1;
	int count = 0; /*已进入拓扑序列中顶点的个数*/	
	/*将所有初始入度为零的顶点入栈*/
	int i, j, k;
	ArcNode *p;
	for(i = 0; i < vertexNum; i++) {
		if(adjlist[i].in == 0)
			S[++top] = i;
	}
	while(top != -1) {
		j = S[top--];
		cout<<adjlist[j].vertex<<" ";
		count++;
		p = adjlist[j].firstEdge;
		while(p != NULL) {
			k = p->adjvex;
			adjlist[k].in--;
			if(adjlist[k].in == 0)
				S[++top] = k;
			p = p->next;
		}
	}
	cout<<endl;
	if(count < vertexNum)
		cout<<"有向图中存在回路，拓扑序列不存在！"<<endl;
	else
		cout<<"有向图中不存在回路，拓扑序列存在！"<<endl;;
}
