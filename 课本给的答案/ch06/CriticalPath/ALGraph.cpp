#include <iostream>
using namespace std;
#include "ALGraph.h"

template <class ElemType>
ALGraph<ElemType>::ALGraph(ElemType a[], int n, int e) {
	ArcNode *s;
	int i, j, k, w;
	vertexNum = n; 
	arcNum = e;
	/*��ʼ�������*/
	for(i = 0; i < n; i++) { 
		adjlist[i].in = 0;
		adjlist[i].vertex = a[i];
		adjlist[i].firstEdge = NULL;      
	}
    /*��������ÿһ����*/
	for (k = 0; k < e; k++) { 
		cout<<"�������"<<k + 1<<"���ߵ������������ż�Ȩֵ��";
		cin>>i>>j>>w;
		/*�����µı߱���s*/
		s = new ArcNode; 
		s->adjvex = j;
		s->weight = w;
		/*����j�����ֵ��1*/
		adjlist[j].in++;
		/*ʹ��ͷ�巨��s���뵽�߱���*/
		s->next = adjlist[i].firstEdge;
		adjlist[i].firstEdge = s;
	}
}

template <class ElemType>
int ALGraph<ElemType>::TopoSort() {
	int S[MaxSize]; /*˳��ջ�����費���������*/
	int top = -1;
	int count = 0; /*�ѽ������������ж���ĸ���*/	
	/*�����г�ʼ���Ϊ��Ķ�����ջ*/
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
		cout<<"����ͼ�д��ڻ�·���������в����ڣ��ؼ�·�������ڣ�"<<endl;
		return; 
	}
	int ve[MaxSize], vl[MaxSize];
	int ae, al;
	int i, j, w, k;
	/*��ʼ���¼������緢��ʱ��*/
	for(i = 0; i < vertexNum; i++)
		ve[i] = 0;
	/*�������¼������緢��ʱ��*/ 
	for(i = 0; i < vertexNum; i++) {
		j = getFirstNeighbor(i);
		while(j != -1) {
			w = getWeight(i, j);
			if(ve[i] + w > ve[j])
				ve[j] = ve[i] + w;
			j = getNextNeighbor(i, j);
		}
	}
	/*��ʼ���¼�����ٷ���ʱ��*/
	for(i = 0; i < vertexNum; i++)
		vl[i] = ve[vertexNum - 1];
	/*�������¼�����ٷ���ʱ��*/
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
	/*�����л�����翪ʼʱ�������ʼʱ��*/
	/*������翪ʼʱ�������ʼʱ����ȵĻ*/
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
