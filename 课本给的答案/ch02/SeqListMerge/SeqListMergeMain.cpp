/*有序表的合并，要求合并后仍然有序*/
#include <iostream>
#include "time.h"
#include "stdlib.h"
#include "SeqList.cpp"
#define MaxSize 100
using namespace std; /*使用std命名空间，避免命名冲突*/

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
	/*处理L1中剩余的元素*/
	while(i <= n1) {
		L3.Insert(k, L1.Get(i));
		i++;
		k++;
	}
	/*处理L2中剩余的元素*/
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
	cout<<"请输入第一个有序表的表长："<<endl;
	cin>>n1;
	if(n1>MaxSize) {
		throw "第一个表长超出了范围！";
	}
	cout<<"请输入第二个有序表的表长："<<endl;
	cin>>n2;
	if(n2>MaxSize) {
		throw "第二个表长超出了范围！";
	}
	if(n1+n2>MaxSize) {
		throw "合并后的表长超出了范围！";
	}
	/*使用随机数为r1,r2赋值*/
	srand(time(NULL)); /*初始化随机种子为当前系统时间*/
	r1[0]=rand()%n1;
    for(int i=1;i<n1;i++)
		r1[i]=r1[i-1]+rand()%n1+1; /*+1为了避免元素重复*/
	srand(time(NULL));
	r2[0]=rand()%n2;
	for(int i=1;i<n2;i++)
		r2[i]=r2[i-1]+rand()%n2+1;
	SeqList<int> L1(r1,n1);
	SeqList<int> L2(r2,n2);
	SeqList<int> L3;
	Merge(L1,L2,L3);
	cout<<"第一个有序表为：";
	L1.PrintList();
	cout<<"第二个有序表为：";
	L2.PrintList();
	cout<<"合并以后的有序表为：";
	L3.PrintList();
	return 0;
}
