#include <iostream>
#define MaxSize 20 /*˳������󳤶�Ϊ20*/
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
	cout<<"������˳���ĳ��ȣ�"<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "�������Ϸ���������[0,20]֮���ֵ��";
	}
	cout<<"������������˳���Ԫ�أ�"<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	InsertSort(r, n);
	cout<<"ֱ�Ӳ�������֮���˳���Ϊ��"<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
