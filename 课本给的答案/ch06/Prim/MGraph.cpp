#include <iostream>
#include <iomanip>
using namespace std;
#include "MGraph.h" /*����ͷ�ļ�

/*��ѡ��̱߼�Ԫ��*/
struct element{
	int lowcost;
	int adjvex;
};

template <class ElemType>
MGraph<ElemType>::MGraph(ElemType a[], int n, int e) {
	int i, j, k, w;
	vertexNum = n;
	arcNum = e;
	/*������a���������鸳ֵ*/
	for(i = 0; i < vertexNum; i++) {
		vertex[i] = a[i];
	}
	/*�ڽӾ����ʼ��*/
	for(i = 0; i < vertexNum; i++)
        for(j = 0; j < vertexNum; j++) {
			if(i == j)
				arc[i][j] = 0;
			else
				arc[i][j] = 32767;
		}
	/*��������arcNum����*/
	for(k = 0; k < arcNum; k++) {
		cout<<"�������"<<k + 1<<"���ߵ������������ż�Ȩֵ���ÿո������";
		cin>>i;
		cin>>j;
		cin>>w;
		arc[i][j] = w; 
		arc[j][i] = w;	
	}
}

template <class ElemType>
void MGraph<ElemType>::Print() {
	cout<<"������Ϊ��"<<vertexNum<<endl;
	cout<<"����Ϊ��"<<arcNum<<endl;
	cout<<"�ڽӾ���Ϊ��"<<endl;
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
	/*��ʼ����������shortEdge*/
	for(i = 1; i < vertexNum; i++) {
		shortEdge[i].lowcost = arc[0][i];
		shortEdge[i].adjvex = 0;
	}
	/*����0���뼯��U*/
	shortEdge[0].lowcost = 0;
	cout<<"Prim�㷨������С�����������ı�Ϊ��"<<endl;
	for(i = 1; i < vertexNum; i++) {
		/*Ѱ����̱ߵ��ڽӵ�k*/
		/*k���ֵ*/
		for(j = 1; j < vertexNum; j++) {
			if(shortEdge[j].lowcost != 0) {
				k = j;
				break;
			}
		}
		/*ѡȡk*/
		for(j = 1; j < vertexNum; j++) {
			if(shortEdge[j].lowcost != 0 && shortEdge[j].lowcost < shortEdge[k].lowcost)
				k = j;
		}
		cout<<"("<<vertex[k]<<", "<<vertex[shortEdge[k].adjvex]<<"), "<<shortEdge[k].lowcost<<endl;
		/*����k���뼯��U��*/
		shortEdge[k].lowcost = 0;
		/*��������shortEdge*/
		for(j = 1; j < vertexNum; j++) {
			if(arc[k][j] < shortEdge[j].lowcost) {
				shortEdge[j].lowcost = arc[k][j];
				shortEdge[j].adjvex = k;
			}
		}
	}
}
