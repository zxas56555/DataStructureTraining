#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree<char> T; /*����һ�ö�����*/
	T.GetMaxPathLength();
	cout<<"�������������Ϊ��";
	cout<<maxLen<<endl;
	cout << "������������" << endl;
	return 0;
}
