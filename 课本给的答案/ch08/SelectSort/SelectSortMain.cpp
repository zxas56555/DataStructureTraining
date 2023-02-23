#include <iostream>
#define MaxSize 20 /*˳������󳤶�Ϊ20*/
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
	cout<<"������˳���ĳ��ȣ�"<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "�������Ϸ���������[0,20]֮���ֵ��";
	}
	cout<<"������������˳���Ԫ�أ�"<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	SelectSort(r, n);
	cout<<"��ѡ������֮���˳���Ϊ��"<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
