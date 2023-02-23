#include <iostream>
#include <iomanip>
using namespace std;
#define MAXN 105

int judge(int i, int j)
{
	int flag = 0;
	if (i == j)
		return 1;
	else if (i > j && (i - j) % 4 == 0)
		return 1;
	else if (j > i && (j - i) % 4 == 0)
		return 1;
	else if ((i + j + 1) % 4 == 0)
		return 1;
	else
		return 0;
}

void MagicSquresDoubleEven(int a[][MAXN], int n)
{
	int i, j;
	int k = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = k++;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (judge(i, j) == 1)
				a[i][j] = n * n + 1 - a[i][j];
		}
	}
}

void PrintMagicSquares(int a[][MAXN], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int a[MAXN][MAXN];
	int i, j;
	int n;
	cout << "Enter the order of magic square" << endl;
	cin >> n;
	MagicSquresDoubleEven(a, n);
	cout << "The magic square of order " << n << " is" << endl;
	PrintMagicSquares(a, n);
	cout << "By 李冠润" << endl;
	return 0;
}
