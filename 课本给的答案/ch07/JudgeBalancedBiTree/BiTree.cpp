#include <iostream>
#include <cmath>
using namespace std;
#include "BiTree.h"

BiNode *BiTree::Creat(BiNode *bt) {
	int data;
	cout<<"请输入创建一棵二叉树的结点数据："<<endl;
	cin>>data;
	/*-1代表空二叉树*/
    if(data == -1) {
		return NULL;
    }
    else { 
		bt = new BiNode; /*生成新结点*/
        bt->data = data;
        bt->lchild = Creat(bt->lchild); /*递归创建左子树*/
        bt->rchild = Creat(bt->rchild); /*递归创建右子树*/
    } 
    return bt;
}

int BiTree::Depth(BiNode *bt) {
	if(bt == NULL)
		return 0;
	else {
		int dep1 = Depth(bt->lchild);
		int dep2 = Depth(bt->rchild);
		return (dep1 > dep2) ? (dep1 + 1) : (dep2 + 1);
	}
}

int BiTree::IsBalancedBiTree(BiNode *bt) {
	if(bt == NULL)
		return 1;
	else if(abs(Depth(bt->lchild) - Depth(bt->rchild)) > 1)
		return 0;
	else return IsBalancedBiTree(bt->lchild) && IsBalancedBiTree(bt->rchild);
} 
