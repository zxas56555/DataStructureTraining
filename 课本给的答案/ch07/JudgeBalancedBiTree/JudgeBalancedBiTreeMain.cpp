#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree T;
	int flag = 1;
	flag = T.IsBalancedBiTree();
	if(flag)
		cout<<"��������ƽ���������";
	else
		cout<<"����������ƽ���������"; 
	return 0;
}
