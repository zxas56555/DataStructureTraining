#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {
	BiTree<char> T;
	cout<<"二叉树的深度为：";
	cout<<T.Depth()<<endl;
	cout<<"二叉树的结点个数为：";
	T.Count();
	cout<<countNode<<endl;
	cout<<"二叉树的叶子结点为：";
	T.PrintLeaf();
	cout<<endl;
	cout<<"二叉树的叶子结点个数为：";
	T.CountLeaf();
	cout<<countLeaf<<endl;
	return 0;
}
