#include <iostream>
#include "ALGraph.h" /*引入头文件*/

template <class ElemType>
ALGraph<ElemType>::ALGraph(ElemType a[], int n, int e) {
	ArcNode *s;
	int i, j, k;
	vertexNum = n; 
	arcNum = e;
	/*初始化顶点表*/
	for(i = 0; i < vertexNum; i++) { 
		adjList[i].vertex = a[i];
		adjList[i].firstEdge = NULL;      
	}
    /*依次输入边*/
	for (k = 0; k < arcNum; k++) { 
		cout<<"请输入第"<<k + 1<<"条边的两个顶点的序号：";
		cin>>i>>j;
		/*生成新的边表结点s*/
		s = new ArcNode; 
		s->adjvex = j;
		/*使用头插法将s插入到边表中*/
		s->next = adjList[i].firstEdge;
		adjList[i].firstEdge = s;
	}
}

/*析构函数，释放邻接表中边表的所有结点*/
template <class ElemType>
ALGraph<ElemType>::~ALGraph() {
	ArcNode *p;
	for(int i = 0; i < vertexNum; i++) {
		p = adjList[i].firstEdge;
		while(p != NULL) {
			adjList[i].firstEdge = p->next;
			delete p;
			p = adjList[i].firstEdge;
		}
	}
}

template <class ElemType>
void ALGraph<ElemType>::DFSTraverse(int v) {
	ArcNode *p; 
	int j;
	/*访问顶点v*/
	cout<<adjList[v].vertex<<" ";
	/*将顶点v设置为已访问*/
	visited[v] = 1;
	/*寻找v的没有被访问过的邻接点，并递归调用深度优先遍历算法*/
	/*p首先指向顶点v的边表中第一个边结点*/
    p = adjList[v].firstEdge;            
	while(p != NULL) {
		j = p->adjvex;
		if(visited[j] == 0) 
			DFSTraverse(j);
		p = p->next;           
	}
}

template <class ElemType>
void ALGraph<ElemType>::BFSTraverse(int v) {
	/*初始化队列, 假设队列采用顺序存储且不会发生上溢*/
	int front = -1, rear = -1;   
	int Q[MaxSize];
    ArcNode *p;
	/*访问顶点v*/
	cout<<adjList[v].vertex<<" "; 
	visited[v] = 1; 
	/*顶点入队*/
	Q[++rear] = v;
	/*队列非空时循环*/
	while (front != rear) {
		/*队头出队*/
		v = Q[++front];
        /*访问v的所有没有访问过的邻接点*/
		p = adjList[v].firstEdge;
		while(p != NULL) {
			int j = p->adjvex;
			if(visited[j] == 0) {
				cout<<adjList[j].vertex<<" "; 
				visited[j] = 1;
				Q[++rear] = j;
			}
			p = p->next;
		}
	}
}

template <class ElemType>
void ALGraph<ElemType>::BFS() {
	int i;
	for(i = 0; i < vertexNum; i++) {
		visited[i] = 0;
	}
	for(i = 0; i < vertexNum; i++) {
		if(visited[ i] == 0)
			BFSTraverse(i);
	}
}

template <class ElemType>
void ALGraph<ElemType>::DFS() {
	int i;
	for(i = 0; i < vertexNum; i++) {
		visited[i] = 0;
	}
	for(i = 0; i < vertexNum; i++) {
		if(visited[i] == 0)
			DFSTraverse(i);
	}
}
