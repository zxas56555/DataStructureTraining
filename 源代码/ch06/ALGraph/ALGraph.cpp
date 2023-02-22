#include <iostream>
#include "ALGraph.h" /*����ͷ�ļ�*/

template <class ElemType>
ALGraph<ElemType>::ALGraph(ElemType a[], int n, int e) {
	ArcNode *s;
	int i, j, k;
	vertexNum = n; 
	arcNum = e;
	/*��ʼ�������*/
	for(i = 0; i < vertexNum; i++) { 
		adjList[i].vertex = a[i];
		adjList[i].firstEdge = NULL;      
	}
    /*���������*/
	for (k = 0; k < arcNum; k++) { 
		cout<<"�������"<<k + 1<<"���ߵ������������ţ�";
		cin>>i>>j;
		/*�����µı߱���s*/
		s = new ArcNode; 
		s->adjvex = j;
		/*ʹ��ͷ�巨��s���뵽�߱���*/
		s->next = adjList[i].firstEdge;
		adjList[i].firstEdge = s;
	}
}

/*�����������ͷ��ڽӱ��б߱�����н��*/
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
	/*���ʶ���v*/
	cout<<adjList[v].vertex<<" ";
	/*������v����Ϊ�ѷ���*/
	visited[v] = 1;
	/*Ѱ��v��û�б����ʹ����ڽӵ㣬���ݹ����������ȱ����㷨*/
	/*p����ָ�򶥵�v�ı߱��е�һ���߽��*/
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
	/*��ʼ������, ������в���˳��洢�Ҳ��ᷢ������*/
	int front = -1, rear = -1;   
	int Q[MaxSize];
    ArcNode *p;
	/*���ʶ���v*/
	cout<<adjList[v].vertex<<" "; 
	visited[v] = 1; 
	/*�������*/
	Q[++rear] = v;
	/*���зǿ�ʱѭ��*/
	while (front != rear) {
		/*��ͷ����*/
		v = Q[++front];
        /*����v������û�з��ʹ����ڽӵ�*/
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
