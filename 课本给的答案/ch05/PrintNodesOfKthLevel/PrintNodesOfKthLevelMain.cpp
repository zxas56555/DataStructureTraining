#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree<char> T;
	int k;
	cout<<"���������k��";
	cin>>k;
	cout<<"��������"<<k<<"��Ľ��Ϊ��";
	T.PrintNodesOfKthLevel(k); 
	cout<<endl;
	cout<<"��������"<<k<<"���Ҷ�ӽ��Ϊ��";
	T.PrintLeafNodesOfKthLevel(k);
	cout<<endl;
	return 0;
}
