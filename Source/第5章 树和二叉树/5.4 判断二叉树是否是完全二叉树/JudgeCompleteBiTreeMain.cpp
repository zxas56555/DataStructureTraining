#include <iostream>
#include <cmath>
using namespace std;
#include "BiTree.cpp"

int main() {	
	BiTree<char> T;
	int flag=T.IsCompleteBiTree();
	if(flag==true)
		cout<<"����������ȫ��������";
	else
		cout<<"������������ȫ��������";
	cout << endl << "������������" << endl;
	return 0; 
}
