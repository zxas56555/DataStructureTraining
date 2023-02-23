#include<iostream>
using namespace std;
#define MAX 1005

int main()
{
	int n, m;
	cin >> n >> m;
	int r[MAX];
	int i = 0, k = 0, j = 0;
	for (i = 0; i < n; i++)
		r[i] = i + 1;
	i = 0;
	cout << "出列的顺序为" << endl;
	while(i < n)
	{
		if(r[i] != 0)
			k++;
		if(k == m)
		{
			k = 0;
			cout << r[i] << " ";
			r[i] = 0;
			j++;
		}
		if(j == n)
			break;
		i = (i + 1) % n;
	}
	cout << endl;
	cout << "By 李冠润" << endl;
	return 0;
}