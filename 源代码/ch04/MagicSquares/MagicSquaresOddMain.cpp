#include <iostream>  
#include <iomanip>  
#define MaxSize 100   
using namespace std; 
void MagicSquresOdd(int a[][MaxSize], int n) {
	int i, j, k;
	i = 0;
	j = n/2;
	a[i][j] = 1;
	for(k = 2; k <= n * n; k++) {
		int ti, tj;
		ti = i;
		tj = j;
		i = (i - 1 + n) % n;
		j = (j - 1 + n) % n;
		if(a[i][j] > 0) {
			i = (ti + 1) % n;
			j = tj;
		}
		a[i][j] = k;
	}
}

void PrintMagicSquares(int a[][MaxSize], int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			/*Ԥ��������Ϊ5���ַ�*/
			cout<<setw(5)<<a[i][j];
		}
		cout<<endl;
	} 
}

int main() {
	int a[MaxSize][MaxSize];
	int i, j;
	int n;
	cout<<"������÷��Ľ�������������"<<endl;
	cin>>n;
	if(n < 0 || n % 2 == 0 || n > MaxSize)
		throw "����n���Ϸ���";
	for(i = 0; i < n; i++)
		for(j = 0; j < n;j++)
			a[i][j] = 0;
	MagicSquresOdd(a, n);
	cout<<n<<"�׻÷�Ϊ��"<<endl;
	PrintMagicSquares(a, n);
	return 0;
}
