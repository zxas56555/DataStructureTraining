#include <iostream>
#include "string.h" /*�����ַ����⺯��*/
using namespace std;
void GetNext(char T[], int next[]) {
	int j, k;
	j = 0;
	k = -1;
	next[0] = -1;
	while(T[j] != '\0') {
		if(k == -1 || T[j] == T[k]) {
			j++;
			k++;
			next[j] = k;
		}
		else {
			k = next[k];
		}
	}
}

int KMPIndex(char S[], char T[]) {
	int next[100];
	int i,j;
	i = 0;
	j = 0;
	GetNext(T, next);
	while(S[i] != '\0' && T[j] != '\0') {
		if(j == -1 || S[i] == T[j]) {
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if(T[j] == '\0')
		return i - j + 1;
	else
		return 0;
}

int main() {
	char S[100];
	char T[100];
	cout<<"������Ŀ�괮S:"<<endl;
	cin>>S;
	cout<<"������ģʽ��T:"<<endl;
	cin>>T;
	int pos;
	pos = KMPIndex(S, T);
	if(pos == 0) {
		cout<<"ƥ��ʧ�ܣ�";
	}
	else {
		cout<<T<<"��"<<S<<"�е�һ�γ��ֵ�λ����"<<pos<<endl;
	}
	return 0;
}
