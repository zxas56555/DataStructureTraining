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
	cout<<"������S��Сд��ĸ��ɵ��ַ�������"<<endl;
	cin>>S;
	cout<<"������λ����k��"<<endl;
	cin>>k;
	Caesar(S,T,k);
	cout<<"ԭ�ַ���Ϊ��"<<S<<endl;
	cout<<"�����Ժ���ַ���Ϊ��"<<T<<endl; 
	return 0;
}
