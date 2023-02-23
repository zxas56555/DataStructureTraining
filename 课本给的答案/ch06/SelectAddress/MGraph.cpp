#include <iostream>
#include <iomanip>
#include <string>
#define INF 32767
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
void MGraph<ElemType>::SelectAddressByFloyd() {
	int dist[MaxSize][MaxSize];
	int maxShortest[MaxSize];
	int i, j, k;
	for(i = 0; i < vertexNum; i++)
		for(j = 0; j < vertexNum; j++) {
			dist[i][j] = arc[i][j];
		}
	/*����ʹ�ö���k��Ϊ�м䶥����̽*/
	for(k = 0; k < vertexNum; k++) {
		for(i = 0; i < vertexNum; i++)
			for(j = 0; j < vertexNum; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
	}
	/*ѡ��dist[][]ÿһ�е����ֵ����maxShortest[]*/
	for(i = 0; i < vertexNum; i++) {
		k = 0;
		for(j = k + 1; j < vertexNum; j++) {
			if(dist[i][j] > dist[i][k])
				k = j;
		}
		maxShortest[i] = dist[i][k];
	}
	/*��maxShortest[]������Сֵ�������Ӧ�Ķ���*/
	k = 0;
	for(j = k + 1; j < vertexNum; j++) {
		if(maxShortest[j] < maxShortest[k])
			k = j;
	}
	cout<<endl<<"��ַӦѡ���ڶ���"<<vertex[k]<<"��"<<endl;	
}

