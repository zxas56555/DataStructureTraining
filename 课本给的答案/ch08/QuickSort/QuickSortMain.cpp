#include <iostream>
#define MaxSize 20 /*顺序表的最大长度为20*/
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
	cout<<"请输入顺序表的长度："<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "参数不合法，请输入[0,20]之间的值！";
	}
	cout<<"请输入待排序的顺序表元素："<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	QuickSort(r, 1, n);
	cout<<"快速排序之后的顺序表为："<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
