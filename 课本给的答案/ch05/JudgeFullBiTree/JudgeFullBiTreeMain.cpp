#include <iostream>
#include <cmath>
using namespace std;
#include "BiTree.cpp"
int main() {
	BiTree<char> T;
	int h;
	h = T.Depth();
	cout<<"�������ĸ߶�Ϊ��";
	cout<<h<<endl;
	cout<<"��������Ҷ�ӽ�����Ϊ��";
	T.CountLeaf();
	cout<<countLeaf<<endl;
	if(countLeaf == pow(2,h-1))
		cout<<"������������������";
	else
		cout<<"��������������������";
	return 0;
}
