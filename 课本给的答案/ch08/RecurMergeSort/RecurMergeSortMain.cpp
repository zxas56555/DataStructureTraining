#include <iostream>
#define MaxSize 20 /*˳������󳤶�Ϊ20*/
using namespace std;

/*һ�ι鲢���鲢����˳���r[s..m]��r[m+1..t]*/
void Merge(int r[], int s, int m, int t) {
	int i, j, k;
	/*��ʱ�����ռ�*/
	int r1[MaxSize + 1];
	i = s;
	j = m + 1;
	k = s;
	while(i <= m && j <= t) {
		if(r[i] <= r[j]) {
			r1[k] = r[i];
			k++;
			i++;
		}
		else {
			r1[k] = r[j];
			k++;
			j++;
		}
	}
	while(i <= m) {
		r1[k] = r[i];
		k++;
		i++;
	}
	while(j <= t) {
		r1[k] = r[j];
		k++;
		j++;
	}
	/*��r1�е����ݸ��Ƶ�r��*/
	for(i = s; i <= t; i++)
		r[i] = r1[i]; 
}

/*�ݹ�Ķ�·�鲢�����㷨*/
void RecurMergeSort(int r[], int s, int t) {
	/*�߽�����*/
	if(s < t) {
		int m = (s + t) / 2;
		RecurMergeSort(r, s, m);
		RecurMergeSort(r, m + 1, t);
		Merge(r, s, m, t); 
	}
}
int main() {
	int i, n;
	int r[MaxSize + 1];
	cout<<"������˳���ĳ��ȣ�"<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "�������Ϸ���������[0,20]֮���ֵ��";
	}
	cout<<"������������˳���Ԫ�أ�"<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	MergeSort(r, 1, n);
	cout<<"�鲢����֮���˳���Ϊ��"<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
