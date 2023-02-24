#include <bits/stdc++.h>

using namespace std;

#include "BiTree.h"
#include "CirQueue.cpp"

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
int BiTree<ElemType>::IsCompleteBiTree(BiNode<ElemType> *bt) {
	CirQueue<BiNode<ElemType> *> Q;
	BiNode<ElemType> *p;
	if(bt == NULL) return 1; /*空二叉树*/
	Q.EnQueue(bt);
	/*当出队的队头指针不为空时，将其左右指针入队*/ 
	while((p = Q.DeQueue()) != NULL) {
		Q.EnQueue(p->lchild);
		Q.EnQueue(p->rchild);	
	}
	/*当遇到空指针时，判断队列中是否有非空指针*/
	/*如果有，则不是完全二叉树*/
	/*没有，则为完全二叉树*/
	while(!Q.Empty()) {
		p = Q.DeQueue();
		if(p != NULL)
			return 0;
	}
	return 1;
}
