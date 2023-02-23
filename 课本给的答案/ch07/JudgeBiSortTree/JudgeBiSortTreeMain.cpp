#include <iostream>
using namespace std;
#include "BiTree.cpp"
int main() {	
	BiTree T;
	cout<<"二叉树的中序遍历序列为：";
	T.InOrder();
	cout<<endl;
	int flag = 1;
	flag = T.IsBiSortTree();
	if(flag)
		cout<<"二叉树是二叉排序树！";
	else
		cout<<"二叉树不是二叉排序树！"; 
	return 0;
}
