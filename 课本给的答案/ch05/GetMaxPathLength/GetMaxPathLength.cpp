#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree<char> T; /*创建一棵二叉树*/
	T.GetMaxPathLength();
	cout<<"二叉树的最长距离为：";
	cout<<maxLen<<endl;
	return 0;
}
