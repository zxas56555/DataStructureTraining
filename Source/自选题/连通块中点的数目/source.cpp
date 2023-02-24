#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int p[N];
int cnt[N];

int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= n; i++)
		cnt[i] = 1;
	while (m--)
	{
		string op;
		int a, b;
		cin >> op;
		if (op == "C")
		{
			cin >> a >> b;
			a = find(a), b = find(b);
			if (a != b)
			{
				p[a] = b;
				cnt[b] += cnt[a];
			}
		}
		else if (op == "Q1")
		{
			cin >> a >> b;
			a = find(a), b = find(b);
			if (a != b)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
		}
		else
		{
			cin >> a;
			a = find(a);
			cout << cnt[a] << endl;
		}
	}
	return 0;
}