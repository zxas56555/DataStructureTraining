#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree<char> T;
	int nodes,leafNodes;
	int k;
	cout<<"���������k��";
	cin>>k;
	nodes = T.GetNodesNumberOfKthLevel(k);
	leafNodes = T.GetLeafNodesNumberOfKthLevel(k);
	cout<<"�������ĵ�"<<k<<"��Ľ�����Ϊ"<<nodes<<"����"<<endl;
	cout<<"�������ĵ�"<<k<<"���Ҷ�ӽ�����Ϊ"<<leafNodes<<"����"<<endl;
	return 0;
}
