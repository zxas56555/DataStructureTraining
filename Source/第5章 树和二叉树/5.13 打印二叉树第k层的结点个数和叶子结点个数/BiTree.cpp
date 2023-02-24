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
void BiTree<ElemType>::PrintNodesOfKthLevel(BiNode<ElemType> *bt, int k) {
	if(bt == NULL || k < 1)
		return;
	if(k == 1)
		cout<<bt->data<<" ";
    PrintNodesOfKthLevel(bt->lchild, k-1);
	PrintNodesOfKthLevel(bt->rchild, k-1);
}

template <class ElemType>
void BiTree<ElemType>::PrintLeafNodesOfKthLevel(BiNode<ElemType> *bt, int k) {
	if(bt == NULL || k < 1)
		return;
	if(bt != NULL) {
		/*判断bt是否是叶子*/ 
		if(k == 1) {
			if(bt->lchild == NULL && bt->rchild == NULL)
				cout<<bt->data<<" ";
		}		
		else if(k > 1) {
			/*递归打印左子树第k-1层的叶子结点*/
			PrintLeafNodesOfKthLevel(bt->lchild, k - 1); 
			/*递归打印右子结第k-1层的叶子结点*/
			PrintLeafNodesOfKthLevel(bt->rchild, k - 1); 
		}
	}
}
