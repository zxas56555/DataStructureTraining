#include <iostream>
#include <string.h>
#define MaxSize 100
using namespace std;
void Caesar(char S[], char T[], int k) {
	for(int i = 0; S[i] != '\0'; i++) {
		T[i] = 'a' + (S[i] - 'a' + k) % 26;
	}
}

int main() {
	char S[100],T[100],k;
	strcpy(T,"\0");
	strcpy(S,"\0");
	cout<<"请输入S（小写字母组成的字符串）："<<endl;
	cin>>S;
	cout<<"请输入位移量k："<<endl;
	cin>>k;
	Caesar(S,T,k);
	cout<<"原字符串为："<<S<<endl;
	cout<<"加密以后的字符串为："<<T<<endl; 
	return 0;
}
