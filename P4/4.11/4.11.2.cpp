#include <iostream>
#include <iomanip>
#define MAXN 100
using namespace std;
void MagicSquresOdd(int a[][MAXN], int n)
{
	int i, j, k;
	i = 0;
	j = n / 2;
	a[i][j] = 1;
	for (k = 2; k <= n * n; k++)
	{
		int ti, tj;
		ti = i;
		tj = j;
		i = (i - 1 + n) % n;
		j = (j - 1 + n) % n;
		if (a[i][j] > 0)
		{
			i = (ti + 1) % n;
			j = tj;
		}
		a[i][j] = k;
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
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;
	MagicSquresOdd(a, n);
	cout << "The magic square of order " << n << " is" << endl;
	PrintMagicSquares(a, n);
	cout << "By 李冠润" << endl;
	return 0;
}
