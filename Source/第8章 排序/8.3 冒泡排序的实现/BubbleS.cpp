#include <bits/stdc++.h>

using namespace std; 


int main() {
	double a[100]; //�������飬��С100
	int N; 
	int i = 0, j = 0; 
	cout<<"����Ԫ�ظ�����";	
	cin >>N; 
	cout<<endl;
	cout<<"�������ݣ�"; 
	for (i = 0; i<N; i++) //����N��Ԫ��
		cin >> a[i]; 
	//-------����---------------
	for (i = 0; i<N - 1; i++) { 
		for (j = 0; j<N - 1 - i; j++){
			if (a[j]>a[j + 1]) { 
				int tmp; 
				tmp = a[j]; 
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	//--------���----------
	cout<<endl;
	cout<<"������ݣ�";
	for (i = 0; i<N; i++) { 
		cout << a[i] << " ";
	}
	cout << endl; 
	cout << "������������" << endl;
	return 0;
}
