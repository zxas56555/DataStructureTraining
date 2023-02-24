#include<iostream>
using namespace std;

int BF(char s[], char t[]);

int main()
{
	char TargetString[1005], PatternString[1005];
	cout << "Input the target string." << endl;
	cin >> TargetString;
	cout << "Input the pattern string." << endl;
	cin >> PatternString;
	int ans = BF(TargetString, PatternString);
	cout << "The first occurrence of " << PatternString << " in " << TargetString << " is " << ans << endl;
	cout << "By 李冠润" << endl;
	return 0;
}

int BF(char s[], char t[])
{
	int i = 0,	j = 0;
	while (s[i] != '\0' && t[j] != '\0')
	{
		if(s[i] == t[j])
		{
			i++;
			j++;
		}
		else 
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if(t[j] == '\0')
		return i - j + 1;
	else
		return 0;
}