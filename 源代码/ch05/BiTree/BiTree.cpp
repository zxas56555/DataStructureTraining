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
void BiTree<ElemType>::Release(BiNode<ElemType> *bt) {
	/*按照后序遍历的顺序释放二叉树*/
	if(bt != NULL) {                  
		Release(bt->lchild); /*释放左子树*/
		Release(bt->rchild); /*释放右子树*/
        delete bt; /*删除根结点*/
	}  
}

template <class ElemType>
void BiTree<ElemType>::PreOrder(BiNode<ElemType> *bt) {
	if(bt == NULL) /*递归调用的边界条件*/
		return;
	else {		
		cout<<bt->data<<" "; /*访问根结点*/
        PreOrder(bt->lchild); /*前序递归遍历左子树*/
		PreOrder(bt->rchild); /*前序递归遍历右子树*/
	}
}

template <class ElemType>
void BiTree<ElemType>::InOrder(BiNode<ElemType> *bt) {
	if(bt == NULL)  
		return; /*递归调用的边界条件*/	          
    else {	
        InOrder(bt->lchild); /*中序递归遍历左子树*/
        cout<<bt->data<<" "; /*访问根结点*/
        InOrder(bt->rchild); /*中序递归遍历的右子树*/
	}
}

template <class ElemType>
void BiTree<ElemType>::PostOrder(BiNode<ElemType> *bt) {
	if(bt == NULL)  
		return; /*递归调用的边界条件*/
    else {	
        PostOrder(bt->lchild); /*后序递归遍历左子树*/
        PostOrder(bt->rchild); /*后序递归遍历右子树*/
        cout<<bt->data<<" "; /*访问根结点*/
	}
}

template <class ElemType>
void BiTree<ElemType>::LevelOrder(BiNode<ElemType> *bt) {
	const int MaxSize = 100;
	/*采用顺序队列，假设不会发生溢出*/
	int front = -1, rear = -1;  
	BiNode<ElemType> *Q[MaxSize], *q;
	if(bt == NULL) 
		return;
	else {
		Q[rear++] = bt; /*bt入队*/
		/*队列非空时循环*/
		while(front != rear) {
			q = Q[front++]; /*队头出队*/
			cout<<q->data<<" "; /*访问队头*/	
			if(q->lchild != NULL) /*如果队头有左孩子，左孩子入队*/
				Q[rear++] = q->lchild;		
			if(q->rchild != NULL) /*如果队头有右孩子，右孩子入队*/
				Q[rear++] = q->rchild;
		}
	}
}

