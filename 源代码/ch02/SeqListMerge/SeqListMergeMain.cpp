/*�����ĺϲ���Ҫ��ϲ�����Ȼ����*/
#include <iostream>
#include "time.h"
#include "stdlib.h"
#include "SeqList.cpp"
#define MaxSize 100
using namespace std; /*ʹ��std�����ռ䣬����������ͻ*/

template <class ElemType>
void Merge(SeqList<ElemType>& L1, SeqList<ElemType>& L2, SeqList<ElemType>& L3) {
	int i = 1, j = 1, k = 1;
	int n1 = L1.Length();
	int n2 = L2.Length();
	while(i <= n1 && j <= n2) {
		if(L1.Get(i) <= L2.Get(j)) {
			L3.Insert(k, L1.Get(i));
			i++;
		}
		else {
			L3.Insert(k, L2.Get(j));
			j++;
		}
		k++;
	}
	/*����L1��ʣ���Ԫ��*/
	while(i <= n1) {
		L3.Insert(k, L1.Get(i));
		i++;
		k++;
	}
	/*����L2��ʣ���Ԫ��*/
	while(j <= n2) {
		L3.Insert(k, L2.Get(j));
		j++;
		k++;
	}
}

int main( ) {
	int r1[MaxSize],r2[MaxSize];
	int r3[MaxSize];
	int n1,n2;
	cout<<"�������һ�������ı���"<<endl;
	cin>>n1;
	if(n1>MaxSize) {
		throw "��һ���������˷�Χ��";
	}
	cout<<"������ڶ��������ı���"<<endl;
	cin>>n2;
	if(n2>MaxSize) {
		throw "�ڶ����������˷�Χ��";
	}
	if(n1+n2>MaxSize) {
		throw "�ϲ���ı������˷�Χ��";
	}
	/*ʹ�������Ϊr1,r2��ֵ*/
	srand(time(NULL)); /*��ʼ���������Ϊ��ǰϵͳʱ��*/
	r1[0]=rand()%n1;
    for(int i=1;i<n1;i++)
		r1[i]=r1[i-1]+rand()%n1+1; /*+1Ϊ�˱���Ԫ���ظ�*/
	srand(time(NULL));
	r2[0]=rand()%n2;
	for(int i=1;i<n2;i++)
		r2[i]=r2[i-1]+rand()%n2+1;
	SeqList<int> L1(r1,n1);
	SeqList<int> L2(r2,n2);
	SeqList<int> L3;
	Merge(L1,L2,L3);
	cout<<"��һ�������Ϊ��";
	L1.PrintList();
	cout<<"�ڶ��������Ϊ��";
	L2.PrintList();
	cout<<"�ϲ��Ժ�������Ϊ��";
	L3.PrintList();
	return 0;
}
