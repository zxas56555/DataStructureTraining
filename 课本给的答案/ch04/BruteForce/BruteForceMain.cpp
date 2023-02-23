#include <iostream>
#include "string.h" /*引入字符串库函数*/
using namespace std;

int BF(char S[], char T[]) {
	int i = 0, j = 0;
	while(S[i] != '\0' && T[j] != '\0') {
		if(S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}	
	}
	if(T[j] == '\0') return i - j + 1;
	else return 0;
}
int main() {
	char S[100];
	char T[100];
	cout<<"请输入目标串S:"<<endl;
	cin>>S;
	cout<<"请输入模式串T:"<<endl;
	cin>>T;
	int pos;
	pos = BF(S, T);
	if(pos == 0) {
		cout<<"匹配失败！";
	}
	else {
		cout<<T<<"在"<<S<<"中第一次出现的位置是"<<pos<<endl;
	}
	return 0;
}
