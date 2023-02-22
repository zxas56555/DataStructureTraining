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
			/*预设输出宽度为5个字符*/
			cout<<setw(5)<<a[i][j];
		}
		cout<<endl;
	} 
}

int main() {
	int a[MaxSize][MaxSize];
	int i, j;
	int n;
	cout<<"请输入幻方的阶数（奇数）："<<endl;
	cin>>n;
	if(n < 0 || n % 2 == 0 || n > MaxSize)
		throw "参数n不合法！";
	for(i = 0; i < n; i++)
		for(j = 0; j < n;j++)
			a[i][j] = 0;
	MagicSquresOdd(a, n);
	cout<<n<<"阶幻方为："<<endl;
	PrintMagicSquares(a, n);
	return 0;
}
