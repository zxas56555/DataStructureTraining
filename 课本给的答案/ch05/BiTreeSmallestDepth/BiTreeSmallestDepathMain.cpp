#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree<char> T;
	cout<<"二叉树的最小深度为：";
	cout<<T.SmallestDepth()<<endl;
	return 0;
}
