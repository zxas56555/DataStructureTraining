#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree T;
	cout<<"------ǰ��ǵݹ����------ "<<endl;
	T.PreOrder();
	cout<<endl;
	cout<<"------����ǵݹ����------ "<<endl;
	T.InOrder( );
	cout<<endl;
	cout<<"------����ǵݹ����------ "<<endl;
	T.PostOrder( );
	cout<<endl;
	cout << "������������" << endl; 
	return 0;
}
