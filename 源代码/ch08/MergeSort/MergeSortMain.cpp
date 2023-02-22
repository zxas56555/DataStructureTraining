#include <iostream>
#define MaxSize 20 /*顺序表的最大长度为20*/
using namespace std;

/*一次归并，归并有序顺序表r[s..m]和r[m+1..t]至r1*/
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

/*一趟归并排序，r为待归并序列，r1为临时空间，h为完整的子序列的长度*/
void MergePass(int r[], int r1[], int n, int h) {
	int i, k;
	i = 1;
	/*可以分割出两个完整的子序列*/
	while(i <= n - 2 * h + 1) {
		Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
		i = i + 2 * h;
	}
	/*可以分割出两个子序列，第一个子序列的长度为h，第二个子序列的长度<h*/
	if(i < n - h + 1) {
		Merge(r, r1, i, i + h - 1, n);
	}
	/*只能分割出一个子序列，长度<=h，将r中的数据复制至r1中*/
	else {
		for(k = i; k <= n; k++)
			r1[k] = r[k];
	}
}

/*完整的二路归并排序算法，非递归*/
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
	cout<<"请输入顺序表的长度："<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "参数不合法，请输入[0,20]之间的值！";
	}
	cout<<"请输入待排序的顺序表元素："<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	MergeSort(r, r1, n);
	cout<<"归并排序之后的顺序表为："<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
