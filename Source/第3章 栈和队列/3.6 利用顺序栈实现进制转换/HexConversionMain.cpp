#include <iostream>
using namespace std;
#include "SeqStack.cpp"
void convert(int N, int n) {
	SeqStack<int> S;
	while(N != 0) {
		S.Push(N % n);
		N = N / n;
	}
	int e;
	while(!S.Empty()) {
		e = S.Pop();
		if(e > 9) {
			/*当余数大于9时，用大写字母表示*/
			e = e + 55;
			cout<<(char)e;
		}
		else
			cout<<e;
	}
}

int main() {
	int n,N;
	cout<<"请输入需要转化进制的十进制数N(N>0)：";
	cin>>N;
	if(N <= 0) {
		cout<<"N必须大于0!"<<endl;
		return 0;
	}
	cout<<"请输入想要转化的进制(2...16)：";
	cin>>n;
	if(n < 2 || n > 16) {
		cout<<"请输入2...16的整数！"<<endl;
		return 0;
	}
	cout<<"转化后的结果为：";
	convert(N, n);
	cout<<endl;
	cout<<"           -杜中驭"<<endl;
	return 0;
}
