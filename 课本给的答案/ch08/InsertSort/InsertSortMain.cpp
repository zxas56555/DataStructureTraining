#include <iostream>
#define MaxSize 20 /*顺序表的最大长度为20*/
using namespace std;

void InsertSort(int r[], int n) {
	int i, j;
	for(i = 2; i <= n; i++) {
		if(r[i] < r[i-1]) {
			r[0] = r[i];
			for(j = i - 1; r[0] < r[j]; j--)
				r[j + 1] = r[j];
		    r[j + 1] = r[0];
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
	InsertSort(r, n);
	cout<<"直接插入排序之后的顺序表为："<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
