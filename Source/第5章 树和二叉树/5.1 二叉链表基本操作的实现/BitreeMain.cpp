#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree<char> T;
	cout<<"------前序遍历------ "<<endl;
	T.PreOrder();
	cout<<endl;
	cout<<"------中序遍历------ "<<endl;
	T.InOrder( );
	cout<<endl;
	cout<<"------后序遍历------ "<<endl;
	T.PostOrder( );
	cout<<endl;
	cout<<"------层序遍历------ "<<endl;
	T.LevelOrder();
	cout<<endl;
	cout << "是李树臻做的" << endl;
	return 0;
}
