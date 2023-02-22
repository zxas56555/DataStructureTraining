#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree T;
	int flag = 1;
	flag = T.IsBalancedBiTree();
	if(flag)
		cout<<"二叉树是平衡二叉树！";
	else
		cout<<"二叉树不是平衡二叉树！"; 
	return 0;
}
