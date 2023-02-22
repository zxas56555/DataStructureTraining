#include <iostream>
using namespace std;
#include "ALGraph.h"

template <class ElemType>
ALGraph<ElemType>::ALGraph(ElemType a[], int n, int e) {
	ArcNode *s;
	int i, j, k, w;
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
		cout<<"请输入第"<<k + 1<<"条边的两个顶点的序号及权值：";
		cin>>i>>j>>w;
		/*生成新的边表结点s*/
		s = new ArcNode; 
		s->adjvex = j;
		s->weight = w;
		/*顶点j的入度值加1*/
		adjlist[j].in++;
		/*使用头插法将s插入到边表中*/
		s->next = adjlist[i].firstEdge;
		adjlist[i].firstEdge = s;
	}
}

template <class ElemType>
int ALGraph<ElemType>::TopoSort() {
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
		//cout<<adjlist[j].vertex<<" ";
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
	//cout<<endl;
	//cout<<"count="<<count<<endl;
	if(count < vertexNum)
		return 0;
	else
		return 1;
}

template <class ElemType>
int ALGraph<ElemType>::getFirstNeighbor(int i) {
	ArcNode *p;
	p = adjlist[i].firstEdge;
	if(p == NULL)
		return -1;
	else 
		return p->adjvex;
} 

template <class ElemType>
int ALGraph<ElemType>::getNextNeighbor(int i, int j) {
	ArcNode *p;
	p = adjlist[i].firstEdge;
	while(p && p->adjvex != j)
		p = p->next;
	if(p == NULL || p->next == NULL)
		return -1;
	else
		return p->next->adjvex;	
}

template <class ElemType>
int ALGraph<ElemType>::getWeight(int i, int j) {
	ArcNode *p;
	p = adjlist[i].firstEdge;
	while(p && p->adjvex != j)
		p = p->next;
	if(p)
		return p->weight;
	else
		return INF; 
}

template <class ElemType>
void ALGraph<ElemType>::GetCriticalPath() {
	if(!TopoSort()) {
		cout<<"有向图中存在回路，拓扑序列不存在，关键路径不存在！"<<endl;
		return; 
	}
	int ve[MaxSize], vl[MaxSize];
	int ae, al;
	int i, j, w, k;
	/*初始化事件的最早发生时间*/
	for(i = 0; i < vertexNum; i++)
		ve[i] = 0;
	/*求所有事件的最早发生时间*/ 
	for(i = 0; i < vertexNum; i++) {
		j = getFirstNeighbor(i);
		while(j != -1) {
			w = getWeight(i, j);
			if(ve[i] + w > ve[j])
				ve[j] = ve[i] + w;
			j = getNextNeighbor(i, j);
		}
	}
	/*初始化事件的最迟发生时间*/
	for(i = 0; i < vertexNum; i++)
		vl[i] = ve[vertexNum - 1];
	/*求所有事件的最迟发生时间*/
	for(j = vertexNum - 2; j >= 0; j--) {
		k = getFirstNeighbor(j);
		while(k != -1) {
			w = getWeight(j, k);
			if(vl[k] - w < vl[j]) {
				vl[j] = vl[k]-w;
			}
			k = getNextNeighbor(j, k);
		}
	}
	/*求所有活动的最早开始时间和最晚开始时间*/
	/*输出最早开始时间和最晚开始时间相等的活动*/
	for(i = 0; i < vertexNum; i++) {
		j = getFirstNeighbor(i);
		while(j != -1) {
			ae = ve[i];
			w = getWeight(i, j);
			al = vl[j] - w;
			if(ae == al) {
				cout<<"<"<<adjlist[i].vertex<<","<<adjlist[j].vertex<<"> "<<w<<endl;
			}
			j = getNextNeighbor(i, j);
		} 
	} 
} 
