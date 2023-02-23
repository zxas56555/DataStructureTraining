#include <iostream>
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

void BiTree::InOrder(BiNode *bt) {
	if(bt == NULL)  
		return; /*递归调用的边界条件*/	          
    else {	
        InOrder(bt->lchild); /*递归遍历左子树*/
        a[k++] = bt->data; /*将当前结点数据保存到数组a中*/ 
        cout<<bt->data<<" "; /*访问根结点*/
        InOrder(bt->rchild); /*递归遍历右子树*/
	}
}

int BiTree::IsBiSortTree(BiNode *bt) {
	/*判断二叉树的中序遍历序列是否递增*/
	for(int i = 1; i < k; i++) {
		if(a[i] <= a[i-1]) {
			return 0;
		}
	} 
	return 1;
}

