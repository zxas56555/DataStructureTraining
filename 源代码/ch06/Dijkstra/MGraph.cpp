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
void MGraph<ElemType>::Dijkstra(int v) {
	int dist[MaxSize]; /*�洢·������*/ 
	string path[MaxSize]; /*�洢·��*/
	int s[MaxSize]; /*�Ѿ�������·���Ķ���*/ 
	int num; /*�Ѿ�������·���Ķ������*/ 
	int i, j, k;
	/*��ʼ��*/
	for(i = 0; i < vertexNum; i++) {
		dist[i] = arc[v][i];
		if(dist[i] != INF)
			path[i] = vertex[v] + " " + vertex[i];
		else
			path[i] = "";
	}
	/*����v���뼯��s*/
	s[0] = v;
	num = 1;
	while(num<vertexNum) {
		/*�ӷ����dist[]��ѡȡ��Сֵ*/
		/*�ҵ�һ�������dist*/
		for(j = 0; j < vertexNum; j++) {
			if(dist[j] != 0)
				break;
		}
		/*�����һ�������dsit[]��С*/
		k = j;
		for(i = k + 1; i < vertexNum; i++)
			if((dist[i] != 0) && (dist[i] < dist[k]))
				k = i;
		/*v��k�����·����������*/
		cout<<path[k]<<" : "<<dist[k]<<endl;
		/*k����s*/
		s[num++] = k;
		/*��k��Ϊ�м䶥�㣬����dist[]��path[]*/ 
		for(i = 0;i < vertexNum; i++)
			if(dist[i] > dist[k] + arc[k][i]) {
				dist[i] = dist[k] + arc[k][i];
				path[i] = path[k] + " " + vertex[i];
			}
		/*����dist[k]��������ıȽ�*/ 
		dist[k] = 0;
	}	
}

