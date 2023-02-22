#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
#define MaxSize 10
/*使用随机数为三对角矩阵赋初值*/
void InitMatrix(int A[][MaxSize], int n)
{
	int a = 10;
	int b = 50;
	srand((unsigned)time(NULL));
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (abs(i - j) <= 1)
				A[i][j] = (rand() % (b - a)) + a;
			else
				A[i][j] = 0;
		}
	}
}

/*输出三对角矩阵*/
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

/*将三对角矩阵A压缩存储到一维数组SA中*/
void CompressMatrix(int A[][MaxSize], int SA[], int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] != 0)
			{
				SA[k++] = A[i][j];
			}
		}
}

/*根据行列下标在一维数组SA中读取矩阵元素*/
int GetElement(int SA[], int i, int j, int n)
{
	if (i < 0 || i >= n || j < 0 || j >= n)
		throw "参数非法";
	if (abs(i - j) <= 1)
		return SA[2 * i + j];
	else
		return 0;
}

int main()
{
	int A[MaxSize][MaxSize], n;
	int SA[MaxSize * (MaxSize + 1) / 2];
	int i, j;
	cout << "请输入矩阵的行列数(<=10)：" << endl;
	cin >> n;
	InitMatrix(A, n);
	cout << "三对角矩阵为：" << endl;
	PrintMatrix(A, n);
	CompressMatrix(A, SA, n);
	cout << "请输入矩阵元素的行列下标i和j：" << endl;
	cin >> i >> j;
	cout << "A[" << i << "][" << j << "]的值为" << GetElement(SA, i, j, n) << endl;
	return 0;
}
