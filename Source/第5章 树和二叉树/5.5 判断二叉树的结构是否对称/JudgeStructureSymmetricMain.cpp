#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {
	BiTree<char> T;
	bool flag = T.IsStructureSymmetric();
	if(flag)
		cout<<"�������ǽṹ�ԶԳƵģ�"<<endl;
	else
		cout<<"���������ǽṹ�ԶԳƵģ�"<<endl; 
	cout << "������������" << endl; 
	return 0;
}
