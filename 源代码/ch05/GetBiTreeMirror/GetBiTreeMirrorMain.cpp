#include <stdio.h>
#include "BiTree.cpp"
#define NODESLENGTH 6
using namespace std;
int main() {
	BiTree<char> T; /*����һ�ö�����*/
	cout<<"ԭ��������ǰ�����У�"<<endl;
	T.PreOrder();
	cout<<endl;
	cout<<"ԭ���������������У�"<<endl;	
	T.InOrder();
	cout<<endl;
	cout<<"ԭ�������ĺ������У�"<<endl;
	T.PostOrder();
	cout<<endl;
	T.GetMirror();
	cout<<"�����������ǰ�����У�"<<endl;
	T.PreOrder();
	cout<<endl;
	cout<<"������������������У�"<<endl;	
	T.InOrder();
	cout<<endl;
	cout<<"����������ĺ������У�"<<endl;
	T.PostOrder();
    return 0;
}
