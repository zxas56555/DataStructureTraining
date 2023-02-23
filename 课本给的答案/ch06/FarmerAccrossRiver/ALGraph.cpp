#include <iostream>
#include "ALGraph.h" /*����ͷ�ļ�*/
using namespace std;

template <class ElemType>
ALGraph<ElemType>::ALGraph(ElemType a[], int n, int e) {
	ArcNode *s;
	int i, j, k;
	vertexNum = n;
	arcNum = e;
	/*���붥����Ϣ����ʼ�������*/
	for(i = 0; i < vertexNum; i++) {
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = NULL;
	}
    /*��������ÿһ����*/
	for (k = 0; k < arcNum; k++) { 
		cout<<"�������"<<k + 1<<"���ߵ������������ţ�";
		cin>>i>>j;
		/*�����µı߱���s*/
		s = new ArcNode; 
		s->adjvex = j;
		/*ʹ��ͷ�巨��s���뵽�߱���*/
		s->next = adjlist[i].firstedge;
		adjlist[i].firstedge = s;
	}
}

/*�����������ͷ��ڽӱ��б߱�����н��*/
template <class ElemType>
ALGraph<ElemType>::~ALGraph() {
	ArcNode *p;
	for(int i = 0; i < vertexNum; i++) {
		p = adjlist[i].firstedge;
		while(p != NULL) {
			adjlist[i].firstedge = p->next;
			delete p;
			p = adjlist[i].firstedge;
		}
	}
}

/*����ڽӱ�*/
template <class ElemType>
void ALGraph<ElemType>::PrintALGraph() {
	cout<<"�ڽӱ�Ϊ��"<<endl;
	int i;
	ArcNode *p;
	for(i = 0; i < vertexNum; i++) {
		cout<<adjlist[i].vertex<<" ";
		p = adjlist[i].firstedge;
		while(p != NULL) {
			cout<<p->adjvex<<" ";
			p = p->next;
		}
		cout<<endl;
	}
}

/*��ʼ״̬*/ 
static int s1 = 0;
template <class ElemType>
void ALGraph<ElemType>::Find(int x, int l, int visited[], int path[], int d) {
	int i, node;
	ArcNode *r;
	visited[x] = 1;
	d++;
	path[d] = x;
	/*�ҵ��յ㣬���·��*/
	if(x == l) {
		s1++;
		if(s1 == 1)
			cout<<"����"<<path[0]<<"������"<<l<<"��·��Ϊ��"<<endl;
		for(i = 0; i <= d; i++) {
			//cout<<path[i]<<" ";
			cout<<adjlist[path[i]].vertex<<" ";
			s[path[i]].PrintStatus();
		}
		cout<<endl;
	}
	r = adjlist[x].firstedge;
	while(r != NULL) {
		node = r->adjvex;
		/*�ݹ�Ѱ��·��*/
		if(visited[node] == 0)
			Find(node, l, visited, path, d);
		r = r->next;
	} 
	visited[x] = 0;
	d--;
}

