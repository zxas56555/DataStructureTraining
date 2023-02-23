#include <iostream>
#define MaxSize 20 /*˳������󳤶�Ϊ20*/
using namespace std;

void BiBubbleSort(int r[], int n) {
	int start, end;
	int i, j, tmp;
	start = 1; end = n;
	while(start < end) {
		/*��������*/
		for(i = start; i < end; i++) {
			if(r[i] > r[i + 1]) {
				tmp = r[i];
				r[i] = r[i + 1];
				r[i + 1] = tmp;
			}
		}
		end--;
		/*��������*/
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
	cout<<"������˳���ĳ��ȣ�"<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "�������Ϸ���������[0,20]֮���ֵ��";
	}
	cout<<"������������˳���Ԫ�أ�"<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	BiBubbleSort(r, n);
	cout<<"˫����������֮���˳���Ϊ��"<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
