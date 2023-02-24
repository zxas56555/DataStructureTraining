#include <bits/stdc++.h>

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
int BiTree<ElemType>::GetNodesNumberOfKthLevel(BiNode<ElemType> *bt, int k) {
	if(bt == NULL || k < 1)
		return 0;
	if(k == 1)
		return 1;
	return GetNodesNumberOfKthLevel(bt->lchild, k - 1) + GetNodesNumberOfKthLevel(bt->rchild, k - 1);
}

template <class ElemType>
int BiTree<ElemType>::GetLeafNodesNumberOfKthLevel(BiNode<ElemType> *bt, int k) {
	if(bt == NULL || k < 1)
		return 0;
	if(bt != NULL) {
		/*判断bt是否是叶子*/ 
		if(k == 1) {
			if(bt->lchild == NULL && bt->rchild == NULL)
				return 1;
			else 
				return 0;
		}
		/*递归求左右子树中的叶子数的和*/
		if(k > 1) {
			return GetLeafNodesNumberOfKthLevel(bt->lchild, k - 1) + GetLeafNodesNumberOfKthLevel(bt->rchild, k - 1);
		}
	}
}

