#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAX 105

class Matrix
{
private:
	int A[MAX][MAX];
	int SA[MAX * (MAX + 1) / 2];

public:
	int n;
	Matrix(int n);
	void compressMatrix();
	int getElement(int i, int j);
	void PrintMatrix();
};

Matrix::Matrix(int n)
{
	this->n = n;
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

void Matrix::compressMatrix()
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

int Matrix::getElement(int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= n)
		throw "参数非法";
	if (abs(i - j) <= 1)
		return SA[2 * i + j];
	else
		return 0;
}

void Matrix::PrintMatrix()
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

int main()
{
	int n;
	cout << "Input the number of rows and columns of the matrix" << endl;
	cin >> n;
	Matrix A(n);
	cout << "The constructed random matrix is as follows" << endl;
	A.PrintMatrix();
	A.compressMatrix();
	cout << "Input the coordinates to query" << endl;
	int x, y;
	cin >> x >> y;
	int ans;
	ans = A.getElement(x - 1, y - 1);
	cout << "The value of " << x << "rows and " << y << " columns is " << ans << endl;
}