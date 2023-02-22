#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree<char> T;
	bool flag = T.IsSymmetric();
	if(flag)
		cout<<"二叉树是对称的！"<<endl;
	else
		cout<<"二叉树不是对称的！"<<endl; 
	return 0;
}
