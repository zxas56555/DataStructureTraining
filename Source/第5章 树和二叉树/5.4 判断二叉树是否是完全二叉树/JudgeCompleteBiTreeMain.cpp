#include <iostream>
#include <cmath>
using namespace std;
#include "BiTree.cpp"

int main() {	
	BiTree<char> T;
	int flag=T.IsCompleteBiTree();
	if(flag==true)
		cout<<"二叉树是完全二叉树！";
	else
		cout<<"二叉树不是完全二叉树！";
	cout << endl << "是李树臻做的" << endl;
	return 0; 
}
