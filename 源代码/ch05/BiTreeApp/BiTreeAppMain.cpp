#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {
	BiTree<char> T;
	cout<<"�����������Ϊ��";
	cout<<T.Depth()<<endl;
	cout<<"�������Ľ�����Ϊ��";
	T.Count();
	cout<<countNode<<endl;
	cout<<"��������Ҷ�ӽ��Ϊ��";
	T.PrintLeaf();
	cout<<endl;
	cout<<"��������Ҷ�ӽ�����Ϊ��";
	T.CountLeaf();
	cout<<countLeaf<<endl;
	return 0;
}
