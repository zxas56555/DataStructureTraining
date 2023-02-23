#include <iostream>
using namespace std;

#define MAXN 105

int main()
{
	int Matrix[MAXN][MAXN];
	int m, n, minData, flag = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Matrix[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		minData = Matrix[i][0];
		for (int j = 0; j < n; j++)
		{
			if (Matrix[i][j] < minData)
				minData = Matrix[i][j];
		}
		for (int j = 0; j < n; j++)
		{
			if (Matrix[i][j] == minData)
			{
				int k;
				for (k = 0; k < m; k++)
					if (Matrix[k][j] > minData)
						break;
				if (k == m)
				{
					cout << "The saddle point is " << Matrix[i][j] << " of " << i + 1 << " row and " << j + 1 << " columns" << endl;
					flag = 1;
				}
			}
		}
	}
	if (!flag)
		cout << "This matrix has no saddle point" << endl;
	cout << "By 李冠润" << endl;
}