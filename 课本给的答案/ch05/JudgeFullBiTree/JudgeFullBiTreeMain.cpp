#include <iostream>
#include <cmath>
using namespace std;
#include "BiTree.cpp"
int main() {
	BiTree<char> T;
	int h;
	h = T.Depth();
	cout<<"二叉树的高度为：";
	cout<<h<<endl;
	cout<<"二叉树的叶子结点个数为：";
	T.CountLeaf();
	cout<<countLeaf<<endl;
	if(countLeaf == pow(2,h-1))
		cout<<"二叉树是满二叉树！";
	else
		cout<<"二叉树不是满二叉树！";
	return 0;
}
