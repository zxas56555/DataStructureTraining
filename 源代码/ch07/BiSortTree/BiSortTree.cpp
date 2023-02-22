#include <iostream>
using namespace std;
#include "BiSortTree.h"

BiSortTree::BiSortTree(int a[], int n) {
	BiNode *s;
	for(int i = 0; i < n; i++) {
		s = new BiNode;
		s->data = a[i];
		s->lchild = NULL;
		s->rchild = NULL;
		InsertBST(root, s); 
	}
} 

void BiSortTree::InsertBST(BiNode *&root, BiNode *s) {
	if(root == NULL) 
		root = s;
	else if(s->data < root->data) 
		InsertBST(root->lchild, s);
	else 
		InsertBST(root->rchild, s);
}

BiNode *BiSortTree::SearchBST(BiNode *root, int k) {
	if(root == NULL)
		return NULL;
	else if(k == root->data)
		return root;
	else if(k < root->data)
		return SearchBST(root->lchild, k);
	else
		return SearchBST(root->rchild, k);
}

void BiSortTree::InOrder(BiNode *root) {
	if(root == NULL)
		return;
	InOrder(root->lchild);
	cout<<root->data<<" ";
	InOrder(root->rchild); 
}

void BiSortTree::Release(BiNode *root) {
	if(root != NULL) {                  
		Release(root->lchild); /*释放左子树*/
		Release(root->rchild); /*释放右子树*/
        delete root; /*删除根结点*/
	}  
} 

void BiSortTree::DeleteBST(BiNode *p, BiNode *f) {
	/*p为叶子*/
	if(p->lchild == NULL && p->rchild == NULL) {
		f->lchild == NULL;
		delete p;
	} 
	/*p只有左子树*/
	else if(p->rchild == NULL) {
		f->lchild = p->lchild;
		delete p;
	} 
	/*p只有右子树*/
	else if(p->lchild == NULL) {
		f->lchild = p->rchild;
		delete p;
	}
	/*p有左右两棵子树*/
	else {
		/*查找p的中序遍历后继*/
		/*s为p右子树最左下结点，ps为s的双亲*/
		BiNode *ps, *s;
		ps = p;
		s = p->rchild;
		while(s->lchild != NULL) {
			ps = s;
			s = s->lchild;
		} 
		p->data = s->data;
		/*p的右孩子没有左子树，p的右孩子是其后继*/
		if(ps == p) {
			p->rchild = s->rchild;
		} 
		/*p的右孩子有左子树，p的后继是s*/
		else {
			ps->lchild = s->rchild;
		}
		delete s;
	}
}
