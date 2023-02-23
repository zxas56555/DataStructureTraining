#include <iostream>
#define MaxSize 20 /*顺序表的最大长度为20*/
using namespace std;

void SelectSort(int r[], int n) {
	int index, i, j;
	int temp;
	for(i = 1; i < n; i++) {
		index = i;
		for(j = i + 1; j <= n; j++)
			if(r[j] < r[index])
				index = j;
			if(index != i) {
				temp = r[i];
				r[i] = r[index];
				r[index] = temp;
			}
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
	SelectSort(r, n);
	cout<<"简单选择排序之后的顺序表为："<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
