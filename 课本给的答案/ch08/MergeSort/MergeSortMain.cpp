#include <iostream>
#define MaxSize 20 /*˳������󳤶�Ϊ20*/
using namespace std;

/*һ�ι鲢���鲢����˳���r[s..m]��r[m+1..t]��r1*/
void Merge(int r[], int r1[], int s, int m, int t) {
	int i, j, k;
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
}

/*һ�˹鲢����rΪ���鲢���У�r1Ϊ��ʱ�ռ䣬hΪ�����������еĳ���*/
void MergePass(int r[], int r1[], int n, int h) {
	int i, k;
	i = 1;
	/*���Էָ������������������*/
	while(i <= n - 2 * h + 1) {
		Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
		i = i + 2 * h;
	}
	/*���Էָ�����������У���һ�������еĳ���Ϊh���ڶ��������еĳ���<h*/
	if(i < n - h + 1) {
		Merge(r, r1, i, i + h - 1, n);
	}
	/*ֻ�ָܷ��һ�������У�����<=h����r�е����ݸ�����r1��*/
	else {
		for(k = i; k <= n; k++)
			r1[k] = r[k];
	}
}

/*�����Ķ�·�鲢�����㷨���ǵݹ�*/
void MergeSort(int r[], int r1[], int n) {
	int h = 1;
	while(h < n) {
		MergePass(r, r1, n, h);
		h = 2 * h;
		MergePass(r1, r, n, h);
		h= 2 * h;
	}
}
int main() {
	int i, n;
	int r[MaxSize + 1], r1[MaxSize + 1];
	cout<<"������˳���ĳ��ȣ�"<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "�������Ϸ���������[0,20]֮���ֵ��";
	}
	cout<<"������������˳���Ԫ�أ�"<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	MergeSort(r, r1, n);
	cout<<"�鲢����֮���˳���Ϊ��"<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
