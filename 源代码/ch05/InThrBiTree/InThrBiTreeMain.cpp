#include <iostream>
using namespace std;
#include "InThrBiTree.cpp"
int main() {	
	InThrBiTree<char> T;
	cout<<"遍历中序线索二叉树的结果为："<<endl;
	T.InOrder();
	return 0;
}
