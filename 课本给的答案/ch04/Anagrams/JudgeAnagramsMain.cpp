#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool myfunction(char i, char j) {
    return i > j;
}

int IsAnagrams(string s1, string s2) {
    /*对s1, s2进行排序*/
	/*begin()为String类的方法，指向字符串的第一个位置*/
	/*end()为String类的方法，指向字符串的最后一个位置*/ 
	/*compare()为String类的方法，比较两个字符串，相等返回0*/
    sort(s1.begin(), s1.end(), myfunction);
    sort(s2.begin(), s2.end(), myfunction);
    if(!s1.compare(s2)) 
        return 1;
    else
        return 0;
}

int main() {
    string s1 = "abandon";
    string s2 = "banadon";
    string s3 = "abaddon"; 
    cout<<s1<<"和"<<s2;
    if(IsAnagrams(s1, s2))
        cout<<"是变位词！"<<endl;
    else
        cout<<"不是变位词！"<<endl;
    cout<<s1<<"和"<<s3;
	if(IsAnagrams(s1, s3))
		cout<<"是变位词！"<<endl;
	else
		cout<<"不是变位词！"<<endl; 
	return 0;
}
