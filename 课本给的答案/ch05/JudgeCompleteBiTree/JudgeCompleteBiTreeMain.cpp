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
	return 0; 
}
