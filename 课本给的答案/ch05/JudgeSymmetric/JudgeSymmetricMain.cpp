#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree<char> T;
	bool flag = T.IsSymmetric();
	if(flag)
		cout<<"�������ǶԳƵģ�"<<endl;
	else
		cout<<"���������ǶԳƵģ�"<<endl; 
	return 0;
}
