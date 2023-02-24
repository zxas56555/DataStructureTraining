#include <bits/stdc++.h>

using namespace std;

#include "BiTree.h"
/*全局变量，记录二叉树的最大的结点距离*/ 
int maxLen = 0;
template <class ElemType>
BiNode<ElemType> *BiTree<ElemType>::Creat(BiNode<ElemType> *bt) {
	char ch;
	cout<<"请输入创建一棵二叉树的结点数据："<<endl;
	cin>>ch;
	/*'#'代表空二叉树*/
    if(ch == '#') 
		return NULL;
    else { 
		bt = new BiNode<ElemType>; /*生成新结点*/
        bt->data = ch;
        bt->lchild = Creat(bt->lchild); /*递归创建左子树*/
        bt->rchild = Creat(bt->rchild); /*递归创建右子树*/
    } 
    return bt;
}

template <class ElemType>
void BiTree<ElemType>::GetMaxPathLength(BiNode<ElemType> *bt) {
	/*二叉树为空，空操作返回*/
	if(bt == NULL) {
		return;
	}
	/*二叉树左子树为空，则左子树的最大结点距离为0*/
	if(bt->lchild == NULL) {
		bt->maxLeft = 0;
	} 
	/*二叉树右子树为空，则右子树的最大结点距离为0*/ 
	if(bt->rchild == NULL) {
		bt->maxRight = 0;
	}
	/*如果左子树不为空，递归寻找左子树的最大结点距离*/
	if(bt->lchild != NULL) {
		GetMaxPathLength(bt->lchild);
	}
	/*如果右子树不为空，递归寻找右子树的最大结点距离*/
	if(bt->rchild != NULL) {
		GetMaxPathLength(bt->rchild);
	}
	/*计算左子树最大结点距离*/
	if(bt->lchild != NULL) {
		int temp = 0;
		int ll = bt->lchild->maxLeft;
		int lr = bt->lchild->maxRight;
		temp = ll > lr ? ll : lr;
		bt->maxLeft = temp + 1;
	} 
	/*计算右子树最大结点距离*/ 
	if(bt->rchild != NULL) {
		int temp = 0;
		int rl = bt->rchild->maxLeft;
		int rr = bt->rchild->maxRight;
		temp = rl > rr ? rl : rr;
		bt->maxRight = temp + 1;
	} 
	/*更新最大结点距离*/
	if(bt->maxLeft + bt->maxRight > maxLen) {
		maxLen = bt->maxLeft + bt->maxRight;
	}
}
