#include <iostream>
#define MaxSize 20 /*˳������󳤶�Ϊ20*/
using namespace std;
void ShellSort(int r[], int n) {
	int d, i, j;
	/*�������д�n/2��ʼ����1����*/
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
	cout<<"������˳���ĳ��ȣ�"<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "�������Ϸ���������[0,20]֮���ֵ��";
	}
	cout<<"������������˳���Ԫ�أ�"<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	ShellSort(r, n);
	cout<<"ϣ������֮���˳���Ϊ��"<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
