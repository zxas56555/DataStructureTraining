#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
#define MaxSize 10
/*使用随机数为下三角矩阵赋初值*/
void InitMatrix(int A[][MaxSize], int n)
{
	int a = 10;
	int b = 50;
	srand((unsigned)time(NULL));
	int c = (rand() % (b - a)) + a;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			A[i][j] = (rand() % (b - a)) + a;
		}
		for (int j = i + 1; j < n; j++)
		{
			A[i][j] = c;
		}
	}
}

/*输出下三角矩阵*/
void PrintMatrix(int A[][MaxSize], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(3);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

/*将下三角矩阵A压缩存储到一维数组SA中*/
void CompressMatrix(int A[][MaxSize], int SA[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			SA[i * (i + 1) / 2 + j] = A[i][j];
	/*将常数c存储到数组SA中*/
	SA[n * (n + 1) / 2] = A[0][n - 1];
}

/*根据行列下标在一维数组SA中读取矩阵元素*/
int GetElement(int SA[], int i, int j, int n)
{
	if (i < 0 || i >= n || j < 0 || j >= n)
		throw "参数非法";
	/*下三角元素*/
	if (i >= j)
		return SA[i * (i + 1) / 2 + j];
	/*上三角元素*/
	else
		return SA[n * (n + 1) / 2];
}

int main()
{
	int A[MaxSize][MaxSize], n;
	int SA[MaxSize * (MaxSize + 1) / 2];
	int i, j;
	cout << "请输入矩阵的行列数(<=10)：" << endl;
	cin >> n;
	InitMatrix(A, n);
	cout << "下三角矩阵为：" << endl;
	PrintMatrix(A, n);
	CompressMatrix(A, SA, n);
	cout << "请输入矩阵元素的行列下标i和j：" << endl;
	cin >> i >> j;
	cout << "A[" << i << "][" << j << "]的值为" << GetElement(SA, i, j, n) << endl;
	return 0;
}
