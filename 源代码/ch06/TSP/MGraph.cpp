#include <iostream>
using namespace std;
#include "MGraph.h"

template <class ElemType>
MGraph<ElemType>::MGraph(ElemType a[],int n,int e) {
	int i, j, k, weight;
	vertexNum = n;
	arcNum = e;
	/*������a���������鸳ֵ*/
	for(i = 0; i < vertexNum; i++) {
		vertex[i] = a[i];
	}
	/*�ڽӾ����ʼ��*/
	for(i = 0; i < vertexNum; i++)
        for(j = 0; j < vertexNum; j++)
			arc[i][j] = MaxWeight;
	/*��������arcNum����*/
	for(k = 0; k < arcNum; k++) {
		cout<<"�������"<<k + 1<<"���ߵ������������ţ�";
		cin>>i>>j>>weight;
		arc[i][j] = weight; 
		arc[j][i] = weight;	
	}
}

template <class ElemType>
int MGraph<ElemType>::Min(int a[],int n) {
	int start = 0, min = a[0], k=0;
	/*Ѱ�һ�û�з��ʹ��Ķ���start*/
 	while(visited[start] == 1) {
  		start++;
  		min = a[start];
 	}
 	/*Ѱ�������ڶ���start�ı���Ȩֵ��С�ı���������һ������*/ 
 	for(; start < n; start++) {
  		if(visited[start] == 0 && min >= a[start]) {
   			k = start;
   			min = a[k];
  		}
 	}
 	return k;
} 

template <class ElemType>
void MGraph<ElemType>::TSP(int v) {
	int path = 0;
 	cout<<"·��Ϊ��";
 	cout<<vertex[v];
 	visited[v] = 1;
 	int i = 0, j = 0;
 	int log = 0;
 	for(; log < vertexNum; log++) {
  		j = Min(arc[i],vertexNum);
  		visited[j] = 1;
  		cout<<"->"<<vertex[j];
  		path += arc[i][j];
  		i = j;
 	}
 	cout<<endl;
 	cout<<"·������Ϊ��"<<path<<endl;
}
