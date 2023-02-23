#include <iostream>
using namespace std;
#include "ALGraph.h"

template <class ElemType>
ALGraph<ElemType>::ALGraph(ElemType a[], int n, int e) {
	ArcNode *s;
	int i, j, k;
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
		cout<<"�������"<<k + 1<<"���ߵ������������ţ�";
		cin>>i>>j;
		/*�����µı߱���s*/
		s = new ArcNode; 
		s->adjvex = j;
		/*����j�����ֵ��1*/
		adjlist[j].in++;
		/*ʹ��ͷ�巨��s���뵽�߱���*/
		s->next = adjlist[i].firstEdge;
		adjlist[i].firstEdge = s;
	}
}

template <class ElemType>
void ALGraph<ElemType>::TopoSort() {
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
		cout<<"����ͼ�д��ڻ�·���������в����ڣ�"<<endl;
	else
		cout<<"����ͼ�в����ڻ�·���������д��ڣ�"<<endl;;
}
