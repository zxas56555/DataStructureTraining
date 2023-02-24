#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree T;
	cout<<"------前序非递归遍历------ "<<endl;
	T.PreOrder();
	cout<<endl;
	cout<<"------中序非递归遍历------ "<<endl;
	T.InOrder( );
	cout<<endl;
	cout<<"------后序非递归遍历------ "<<endl;
	T.PostOrder( );
	cout<<endl;
	cout << "是李树臻做的" << endl; 
	return 0;
}
