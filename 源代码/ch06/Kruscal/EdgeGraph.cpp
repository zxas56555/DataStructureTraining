#include <iostream>
#include <iomanip>
using namespace std;
#include "EdgeGraph.h"  
#include "FindRoot.cpp"

template <class ElemType>
EdgeGraph<ElemType>::EdgeGraph(ElemType a[], int n, int e) {
	int i, k;
	vertexNum = n;
	edgeNum = e;
	/*������a���������鸳ֵ*/
	for(i = 0; i < vertexNum; i++) {
		vertex[i] = a[i];
	}
	/*��������edgeNum����*/
	for(k = 0; k < edgeNum; k++) {
		cout<<"�������"<<k + 1<<"���ߵ������������ż�Ȩֵ���ÿո������";
		cin>>edge[k].from;
		cin>>edge[k].to;
		cin>>edge[k].weight;
	}
}

template <class ElemType>
void EdgeGraph<ElemType>::Sort() {
	/*����ð�������������ͨ���ı߼������������*/
	int exchange, bound;
	int j;
	EdgeType temp;
	exchange = edgeNum-1;
	while(exchange != -1) {
		bound = exchange;
		exchange = -1;
		for(j = 0; j < bound; j++)
			if(edge[j].weight > edge[j+1].weight) {
				temp = edge[j];
				edge[j] = edge[j+1];
				edge[j+1] = temp;
				exchange = j;
			}
	}
}

template <class ElemType>
void EdgeGraph<ElemType>::Print() {
	cout<<"������Ϊ��"<<vertexNum<<endl;
	cout<<"����Ϊ��"<<edgeNum<<endl;
	cout<<"�߼�����Ϊ��"<<endl;
	int i;
	for(i = 0; i < edgeNum; i++) {
		cout<<setw(3)<<edge[i].from<<setw(3)<<edge[i].to<<setw(3)<<edge[i].weight<<endl;
	}
}

template <class ElemType>
void EdgeGraph<ElemType>::Kruscal() {
	int parent[MaxSize];
	int i, num;
	/*��ʼ��parent[]����*/
	for(i = 0; i < vertexNum; i++)
		parent[i] = -1;
	/*��¼�ϲ���ͨ�����Ĵ���*/
	num = 0;
	int vex1, vex2;
	cout<<"Kruscal�㷨������С�������а����ı�Ϊ��"<<endl;
	/*��Ȩֵ��С���������ź���ı߼������ÿһ����*/
	for(i = 0; i < edgeNum; i++) {
		/*Ѱ����������������ͨ�����ĸ�*/
		vex1 = FindRoot(parent, edge[i].from);
		cout<<"vex1="<<vex1<<endl;
		vex2 = FindRoot(parent, edge[i].to);
		cout<<"vex2="<<vex2<<endl;
		/*�ߵ��������㲻��ͬһ����ͨ����*/ 
		if(vex1 != vex2) {
			/*�����*/ 
			cout<<"("<<vertex[edge[i].from]<<", "<<vertex[edge[i].to]<<"), "<<edge[i].weight<<endl;
			/*�ϲ���ͨ����*/
			parent[vex2] = vex1;
			num++;
			/*�Ѻϲ�n - 1�Σ�����*/
			if(num == vertexNum - 1)
				return;
		}
	}
}
