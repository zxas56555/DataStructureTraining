#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {
	BiTree<char> T;
	bool flag = T.IsStructureSymmetric();
	if(flag)
		cout<<"二叉树是结构性对称的！"<<endl;
	else
		cout<<"二叉树不是结构性对称的！"<<endl; 
	cout << "是李树臻做的" << endl; 
	return 0;
}
