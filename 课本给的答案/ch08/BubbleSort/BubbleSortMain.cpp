#include <iostream>
#define MaxSize 20 /*˳������󳤶�Ϊ20*/
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
	cout<<"������˳���ĳ��ȣ�"<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "�������Ϸ���������[0,20]֮���ֵ��";
	}
	cout<<"������������˳���Ԫ�أ�"<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	BubbleSort2(r, n);
	cout<<"��������֮���˳���Ϊ��"<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
