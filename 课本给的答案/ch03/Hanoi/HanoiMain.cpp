#include <iostream>
using namespace std;
void Hanoi(int n, char A, char B, char C) {
	if(n ==  1) {
		cout<<A<<" ���Ƶ� "<<C<<" ��"<<endl;
	}
	else {
		Hanoi(n - 1, A, C, B);
		cout<<A<<" ���Ƶ� "<<C<<" ��"<<endl;
		Hanoi(n - 1, B, A, C);
	}
}
int main() {
	int n;
	cout<<"������A���Ͻ���ĸ�����";
	cin>>n;
	if(n<1)
		throw "�������Ϸ���n�����Ǵ���0��������";
	Hanoi(n, 'A', 'B', 'C');
	return 0;
}
