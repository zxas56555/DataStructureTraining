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
			/*����������9ʱ���ô�д��ĸ��ʾ*/
			e = e + 55;
			cout<<(char)e;
		}
		else
			cout<<e;
	}
}

int main() {
	int n,N;
	cout<<"��������Ҫת�����Ƶ�ʮ������N(N>0)��";
	cin>>N;
	if(N <= 0) {
		cout<<"N�������0!"<<endl;
		return 0;
	}
	cout<<"��������Ҫת���Ľ���(2...16)��";
	cin>>n;
	if(n < 2 || n > 16) {
		cout<<"������2...16��������"<<endl;
		return 0;
	}
	cout<<"ת����Ľ��Ϊ��";
	convert(N, n);
	cout<<endl;
	cout<<"           -����Ԧ"<<endl;
	return 0;
}
