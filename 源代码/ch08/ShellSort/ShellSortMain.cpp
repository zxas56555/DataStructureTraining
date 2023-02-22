#include <iostream>
#define MaxSize 20 /*顺序表的最大长度为20*/
using namespace std;
void ShellSort(int r[], int n) {
	int d, i, j;
	/*增量序列从n/2开始，至1结束*/
	for(d = n / 2; d >= 1; d = d / 2) {
		for(i = d + 1; i <= n; i++) {
			r[0] = r[i];
			for(j = i - d; j > 0 && r[0] < r[j]; j = j - d)
				r[j + d] = r[j];
			r[j + d] = r[0];
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
	ShellSort(r, n);
	cout<<"希尔排序之后的顺序表为："<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
