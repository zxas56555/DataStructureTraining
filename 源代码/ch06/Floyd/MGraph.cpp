#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "MGraph.h" /*����ͷ�ļ�*/

template <class ElemType>
MGraph<ElemType>::MGraph(ElemType a[], int n, int e) {
	int i, j, w, k;
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
				arc[i][j] = INF;
		}
	/*��������arcNum����*/
	for(k = 0; k < arcNum; k++) {
		cout<<"�������"<<k + 1<<"���ߵ������������ż�Ȩֵ��ʹ�ÿո������";
		cin>>i;
		cin>>j;
		cin>>w;
		arc[i][j] = w; 
	}
}

template <class ElemType>
void MGraph<ElemType>::Floyd() {
	int dist[MaxSize][MaxSize];
	string path[MaxSize][MaxSize];
	int i, j, k;
	/*dist, path��ʼ��*/
	for(i = 0; i < vertexNum; i++)
		for(j = 0; j < vertexNum; j++) {
			dist[i][j] = arc[i][j];
			if(dist[i][j] != INF)
				path[i][j] = vertex[i]+vertex[j];
			else 
				path[i][j] = "";
		}
	/*����ʹ�ö���k��Ϊ�м䶥����̽*/
	for(k = 0; k < vertexNum; k++) {
		for(i = 0; i < vertexNum; i++)
			for(j = 0; j < vertexNum; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k] + vertex[j];
				}
	}
	/*������*/
	cout<<"���·���ֱ�Ϊ��"<<endl;
	for(i = 0; i < vertexNum; i++) {
		for(j = 0; j < vertexNum; j++) {
			if(i != j) {
				cout<<vertex[i]<<"-->"<<vertex[j]<<" : ";
				cout<<dist[i][j]<<"("<<path[i][j]<<")"<<" ";
				cout<<endl;
			}
		}
	}
}
