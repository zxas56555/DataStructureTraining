#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool myfunction(char i, char j) {
    return i > j;
}

int IsAnagrams(string s1, string s2) {
    /*��s1, s2��������*/
	/*begin()ΪString��ķ�����ָ���ַ����ĵ�һ��λ��*/
	/*end()ΪString��ķ�����ָ���ַ��������һ��λ��*/ 
	/*compare()ΪString��ķ������Ƚ������ַ�������ȷ���0*/
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
    cout<<s1<<"��"<<s2;
    if(IsAnagrams(s1, s2))
        cout<<"�Ǳ�λ�ʣ�"<<endl;
    else
        cout<<"���Ǳ�λ�ʣ�"<<endl;
    cout<<s1<<"��"<<s3;
	if(IsAnagrams(s1, s3))
		cout<<"�Ǳ�λ�ʣ�"<<endl;
	else
		cout<<"���Ǳ�λ�ʣ�"<<endl; 
	return 0;
}
