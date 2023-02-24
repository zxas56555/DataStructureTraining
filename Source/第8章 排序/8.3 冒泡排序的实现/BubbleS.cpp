#include <bits/stdc++.h>

using namespace std; 


int main() {
	double a[100]; //定义数组，大小100
	int N; 
	int i = 0, j = 0; 
	cout<<"输入元素个数：";	
	cin >>N; 
	cout<<endl;
	cout<<"输入数据："; 
	for (i = 0; i<N; i++) //输入N个元素
		cin >> a[i]; 
	//-------排序---------------
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
	//--------输出----------
	cout<<endl;
	cout<<"输出数据：";
	for (i = 0; i<N; i++) { 
		cout << a[i] << " ";
	}
	cout << endl; 
	cout << "是李树臻做的" << endl;
	return 0;
}
