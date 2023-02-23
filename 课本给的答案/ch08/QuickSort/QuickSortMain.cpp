#include <iostream>
#define MaxSize 20 /*˳������󳤶�Ϊ20*/
using namespace std;

int Partition(int r[], int first, int end) {
	int i, j;
	int temp;
	i = first;
	j = end;
	while(i < j) {
		while(i < j && r[i] <= r[j])
			j--;
		if(i < j) {
			temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			i++;
		}
		while(i < j && r[i] <= r[j])
			i++;
		if(i < j) {
			temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			j--;
		}
	}
	return i;
}

void QuickSort(int r[], int first, int end) {
	int pivot;
	if(first < end) {
		pivot = Partition(r, first, end);
		QuickSort(r, first, pivot-1);
		QuickSort(r, pivot + 1, end);
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
	QuickSort(r, 1, n);
	cout<<"��������֮���˳���Ϊ��"<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
