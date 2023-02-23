#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree<char> T;
	int k;
	cout<<"请输入层数k：";
	cin>>k;
	cout<<"二叉树第"<<k<<"层的结点为：";
	T.PrintNodesOfKthLevel(k); 
	cout<<endl;
	cout<<"二叉树第"<<k<<"层的叶子结点为：";
	T.PrintLeafNodesOfKthLevel(k);
	cout<<endl;
	return 0;
}
