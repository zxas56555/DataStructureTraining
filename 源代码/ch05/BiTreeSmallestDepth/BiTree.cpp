#include <iostream>
using namespace std;
#include "BiTree.h"

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
int BiTree<ElemType>::SmallestDepth(BiNode<ElemType> *bt) {
	if(bt == NULL)   
        return 0;  
    if(bt->lchild == NULL)   
        return SmallestDepth(bt->rchild) + 1;  
    if(bt->rchild == NULL)  
        return SmallestDepth(bt->lchild) + 1; 
	int m = SmallestDepth(bt->lchild) + 1;
	int n = SmallestDepth(bt->rchild) + 1;
	return m < n ? m : n; 
} 

