#include <iostream>
#define MaxSize 20 /*顺序表的最大长度为20*/
using namespace std;

void BiBubbleSort(int r[], int n) {
	int start, end;
	int i, j, tmp;
	start = 1; end = n;
	while(start < end) {
		/*从左向右*/
		for(i = start; i < end; i++) {
			if(r[i] > r[i + 1]) {
				tmp = r[i];
				r[i] = r[i + 1];
				r[i + 1] = tmp;
			}
		}
		end--;
		/*从右向左*/
		for(j = end; j > start; j--) {
			if(r[j] < r[j - 1]) {
				tmp = r[j];
				r[j] = r[j - 1];
				r[j - 1] = tmp;
			}
		}
		start++;
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
	BiBubbleSort(r, n);
	cout<<"双向起泡排序之后的顺序表为："<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
