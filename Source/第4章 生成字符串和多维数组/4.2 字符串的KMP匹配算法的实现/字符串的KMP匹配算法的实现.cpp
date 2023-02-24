#include <iostream>
#include <cstring>
using namespace std;

void GetNext(string T, int next[]);
int KMP(string s, string t);

int main()
{
	string TargetString, PatternString;
	cout << "Input the target string." << endl;
	cin >> TargetString;
	cout << "Input the pattern string." << endl;
	cin >> PatternString;
	int ans = 0;
	ans = KMP(TargetString, PatternString);
	if(ans)
		cout << "The first occurrence of " << PatternString << " in " << TargetString << " is " << ans << endl;
	else
		cout << "No " << PatternString << " in " << TargetString << endl;
	cout << "By 李冠润" << endl;
	return 0;
}

void GetNext(string T, int next[])
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j < (int)T.length())
	{
		if (k == -1 || T[j] == T[k])
		{
			j++, k++;
			if (T[j] == T[k])
				next[j] = next[k];
			else
				next[j] = k;
		}
		else
			k = next[k];
	}
}

int KMP(string s, string t)
{
	int Next[1005], i = 0, j = 0;
	GetNext(t, Next);
	while (i < (int)s.length() && j < (int)t.length())
	{
		if (j == -1 || s[i] == t[j])
			i++, j++;
		else
			j = Next[j];
	}
	if (j >= (int)t.length())
		return i - j + 1;
	else
		return 0;
}