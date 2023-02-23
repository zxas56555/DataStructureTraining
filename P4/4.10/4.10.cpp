#include<iostream>
using namespace std;

int calculate(int n, int i, int j);

int main()
{
	int n;
	cout << "Enter the number of rows and columns of the matrix" << endl;
	cin >> n;
	cout << "The spiral square matrix of order "<< n << " is" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout.width(5);
			cout << calculate(n - 1, i, j);
		}
		cout << endl;
	}
	cout << "By 李冠润" << endl;
}

int calculate(int n, int i, int j)
{
	int k = 0;
	int mini = i < n - i ? i : n - i;
	int minj = j < n - j ? j : n - j;
	int min = mini < minj ? mini : minj;
	int h;
	for (h = 0; h < min; ++h)
	{
		k += (n - 2 * h) * 4;
	}
	if (i == min)
	{
		k += j - min + 1;
	}
	else if (j == n - min)
	{
		k += (n - 2 * min) + (i - min) + 1;
	}
	else if (i == n - min)
	{
		k += (n - 2 * min) * 2 + (n - min - j) + 1;
	}
	else if (j == min)
	{
		k += (n - 2 * min) * 3 + (n - min - i) + 1;
	}
	return k;
}
