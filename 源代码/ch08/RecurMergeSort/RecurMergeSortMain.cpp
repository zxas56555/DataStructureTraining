#include <iostream>
#define MaxSize 20 /*顺序表的最大长度为20*/
using namespace std;

/*一次归并，归并有序顺序表r[s..m]和r[m+1..t]*/
void Merge(int r[], int s, int m, int t) {
	int i, j, k;
	/*临时辅助空间*/
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
	/*将r1中的数据复制到r中*/
	for(i = s; i <= t; i++)
		r[i] = r1[i]; 
}

/*递归的二路归并排序算法*/
void RecurMergeSort(int r[], int s, int t) {
	/*边界条件*/
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
	cout<<"请输入顺序表的长度："<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "参数不合法，请输入[0,20]之间的值！";
	}
	cout<<"请输入待排序的顺序表元素："<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	MergeSort(r, 1, n);
	cout<<"归并排序之后的顺序表为："<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
