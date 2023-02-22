#include <iostream>  
#include <iomanip>
using namespace std;
#define MaxSize 100
/*判断下标为i, j处的元素是否需要取补*/
int judge(int i, int j) {
	int flag = 0;
	/*主对角线上的元素*/
	if(i == j) return 1;
	/*主对角线以下小方阵上主对角线上的元素*/
	else if(i > j && (i - j) % 4 == 0)
		return 1;
	/*主对角线以上小方阵上主对角线上的元素*/
	else if(j > i && (j - i) % 4 == 0)
		return 1;
	/*小方阵上次对角线上的元素*/
	else if((i + j + 1) % 4==0)
		return 1;
	else 
		return 0;
}

/*双偶阶幻方的构造方法*/
void MagicSquresDoubleEven(int a[][MaxSize], int n) {
	int i, j;
	/*初始化幻方*/ 
	/*将1-n*n的数顺次填写到幻方中*/
	int k = 1;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			a[i][j] = k++;
	for(i = 0; i< n; i++) {
		for(j = 0; j < n; j++) {
			if(judge(i, j) == 1)
				a[i][j] = n*n + 1 - a[i][j];
		}
	}
}

/*输出幻方*/
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
	cout<<"请输入幻方的阶数（必须为小于MaxSize的4的倍数）:"<<endl;
	cin>>n;
	if(n < 0 || n % 4 != 0 || n > MaxSize)
		throw "参数n不合法！";
	MagicSquresDoubleEven(a, n);
	cout<<n<<"阶幻方为："<<endl;
	PrintMagicSquares(a, n);
	return 0;
}
