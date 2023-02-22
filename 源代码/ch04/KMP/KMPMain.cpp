#include <iostream>
#include "string.h" /*引入字符串库函数*/
using namespace std;
void GetNext(char T[], int next[])
{
	int j, k;
	j = 0;
	k = -1;
	next[0] = -1;
	while (T[j] != '\0')
	{
		if (k == -1 || T[j] == T[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMPIndex(char S[], char T[])
{
	int next[100];
	int i, j;
	i = 0;
	j = 0;
	GetNext(T, next);
	while (S[i] != '\0' && T[j] != '\0')
	{
		if (j == -1 || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (T[j] == '\0')
		return i - j + 1;
	else
		return 0;
}

int main()
{
	char S[100];
	char T[100];
	cout << "请输入目标串S:" << endl;
	cin >> S;
	cout << "请输入模式串T:" << endl;
	cin >> T;
	int pos;
	pos = KMPIndex(S, T);
	if (pos == 0)
	{
		cout << "匹配失败！";
	}
	else
	{
		cout << T << "在" << S << "中第一次出现的位置是" << pos << endl;
	}
	return 0;
}
