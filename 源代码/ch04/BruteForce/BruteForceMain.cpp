#include <iostream>
#include "string.h" /*�����ַ����⺯��*/
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
	cout<<"������Ŀ�괮S:"<<endl;
	cin>>S;
	cout<<"������ģʽ��T:"<<endl;
	cin>>T;
	int pos;
	pos = BF(S, T);
	if(pos == 0) {
		cout<<"ƥ��ʧ�ܣ�";
	}
	else {
		cout<<T<<"��"<<S<<"�е�һ�γ��ֵ�λ����"<<pos<<endl;
	}
	return 0;
}
