#include <iostream>
using namespace std;
#include "MGraph.h"

template <class ElemType>
MGraph<ElemType>::MGraph(ElemType a[], int n, int e) {
	int i, j, k;
	vertexNum = n;
	arcNum = e;
	/*������a���������鸳ֵ*/
	for(i = 0; i < vertexNum; i++) {
		vertex[i] = a[i];
	}
	/*�ڽӾ����ʼ��*/
	for(i = 0; i < vertexNum; i++)
        for(j = 0; j < vertexNum; j++)
			arc[i][j] = 0;
	/*��������arcNum����*/
	for(k = 0; k < arcNum; k++) {
		cout<<"�������"<<k+1<<"���ߵ������������ţ�";
		cin>>i;
		cin>>j;
		arc[i][j]=1; 
		arc[j][i]=1;	
	}
}

template <class ElemType>
MGraph<ElemType>::~MGraph() {
} 

/*�Ӷ���v��ʼ����������ȱ���*/
template <class ElemType>
void MGraph<ElemType>::DFSTraverse(int v) {
	int j;
	/*�������v*/
	cout<<vertex[v]<<" "; 
	/*������v�ķ��ʱ�־��Ϊ1*/
	visited[v] = 1;
	for (j = 0; j < vertexNum; j++)
		if (arc[v][j] == 1 && visited[j] == 0) 
			DFSTraverse(j);
}

template <class ElemType>
void MGraph<ElemType>::DFS() {
	int i;
	/*�����ʱ�־����ֵ*/
	for(i = 0; i < vertexNum; i++)
		visited[i] = 0;
	for(i = 0; i < vertexNum; i++)
		if(visited[i] == 0)
			DFSTraverse(i);
}

template <class ElemType>
void MGraph<ElemType>::BFSTraverse(int v) {
	/*˳����У����費�ᷢ������*/
	int Q[MaxSize];
	int front = -1, rear = -1; /*��ʼ������*/
	/*���ʶ���v����v�ķ��ʱ�־��Ϊ1*/
	cout<<vertex[v]<<" "; 
	visited[v] = 1;  
	/*v���*/
	Q[++rear] = v;
	/*�����зǿ�ʱѭ��*/
	while(front != rear) {
		/*��ͷ����*/
		v = Q[++front];
		/*���ʶ�ͷ����û�з��ʹ����ڽӵ㣬�����*/
		for(int j = 0; j < vertexNum; j++)
			if(arc[v][j] == 1 && visited[j] == 0) {
				cout<<vertex[j]<<" "; 
				visited[j] = 1; 
				Q[++rear] = j;
			}
	}
}
 
template <class ElemType>
void MGraph<ElemType>::BFS() {
	int i;
	/*�����ʱ�־����ֵ*/
	for(i = 0; i < vertexNum; i++)
		visited[i] = 0;
	for(i = 0; i < vertexNum; i++)
		if(visited[i] == 0)
			BFSTraverse(i);
}
