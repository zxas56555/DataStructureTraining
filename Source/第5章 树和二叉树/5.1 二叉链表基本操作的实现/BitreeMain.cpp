#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree<char> T;
	cout<<"------ǰ�����------ "<<endl;
	T.PreOrder();
	cout<<endl;
	cout<<"------�������------ "<<endl;
	T.InOrder( );
	cout<<endl;
	cout<<"------�������------ "<<endl;
	T.PostOrder( );
	cout<<endl;
	cout<<"------�������------ "<<endl;
	T.LevelOrder();
	cout<<endl;
	cout << "������������" << endl;
	return 0;
}
