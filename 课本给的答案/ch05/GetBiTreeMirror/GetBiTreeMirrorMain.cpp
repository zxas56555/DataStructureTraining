#include <stdio.h>
#include "BiTree.cpp"
#define NODESLENGTH 6
using namespace std;
int main() {
	BiTree<char> T; /*创建一棵二叉树*/
	cout<<"原二叉树的前序序列："<<endl;
	T.PreOrder();
	cout<<endl;
	cout<<"原二叉树的中序序列："<<endl;	
	T.InOrder();
	cout<<endl;
	cout<<"原二叉树的后序序列："<<endl;
	T.PostOrder();
	cout<<endl;
	T.GetMirror();
	cout<<"二叉树镜像的前序序列："<<endl;
	T.PreOrder();
	cout<<endl;
	cout<<"二叉树镜像的中序序列："<<endl;	
	T.InOrder();
	cout<<endl;
	cout<<"二叉树镜像的后序序列："<<endl;
	T.PostOrder();
    return 0;
}
