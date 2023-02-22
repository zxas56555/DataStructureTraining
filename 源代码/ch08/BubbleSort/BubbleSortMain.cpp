#include <iostream>
#define MaxSize 20 /*顺序表的最大长度为20*/
using namespace std;

void BubbleSort1(int r[], int n) {
	int i, j, temp;
	for(i = 1; i < n; i++) {
		for(j = 1; j < n - i + 1; j++) {
			if(r[j] > r[j + 1]) {
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
			}
		}
	}
}
void BubbleSort2(int r[], int n) {
	int exchange, bound;
	int j;
	int temp;
	exchange = n;
	while(exchange != 0) {
		bound = exchange;
		exchange = 0;
		for(j = 1; j < bound; j++)
			if(r[j] > r[j+1]) {
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
				exchange = j;
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
	BubbleSort2(r, n);
	cout<<"起泡排序之后的顺序表为："<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
