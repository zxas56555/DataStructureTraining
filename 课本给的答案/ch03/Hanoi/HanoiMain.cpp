#include <iostream>
using namespace std;
void Hanoi(int n, char A, char B, char C) {
	if(n ==  1) {
		cout<<A<<" 塔移到 "<<C<<" 塔"<<endl;
	}
	else {
		Hanoi(n - 1, A, C, B);
		cout<<A<<" 塔移到 "<<C<<" 塔"<<endl;
		Hanoi(n - 1, B, A, C);
	}
}
int main() {
	int n;
	cout<<"请输入A塔上金碟的个数：";
	cin>>n;
	if(n<1)
		throw "参数不合法，n必须是大于0的整数！";
	Hanoi(n, 'A', 'B', 'C');
	return 0;
}
