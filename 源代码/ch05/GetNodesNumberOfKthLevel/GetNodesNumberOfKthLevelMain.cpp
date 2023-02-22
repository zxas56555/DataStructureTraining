#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree<char> T;
	int nodes,leafNodes;
	int k;
	cout<<"请输入层数k：";
	cin>>k;
	nodes = T.GetNodesNumberOfKthLevel(k);
	leafNodes = T.GetLeafNodesNumberOfKthLevel(k);
	cout<<"二叉树的第"<<k<<"层的结点个数为"<<nodes<<"个。"<<endl;
	cout<<"二叉树的第"<<k<<"层的叶子结点个数为"<<leafNodes<<"个。"<<endl;
	return 0;
}
