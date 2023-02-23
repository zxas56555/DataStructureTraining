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
		Release(root->lchild); /*�ͷ�������*/
		Release(root->rchild); /*�ͷ�������*/
        delete root; /*ɾ�������*/
	}  
} 

void BiSortTree::DeleteBST(BiNode *p, BiNode *f) {
	/*pΪҶ��*/
	if(p->lchild == NULL && p->rchild == NULL) {
		f->lchild == NULL;
		delete p;
	} 
	/*pֻ��������*/
	else if(p->rchild == NULL) {
		f->lchild = p->lchild;
		delete p;
	} 
	/*pֻ��������*/
	else if(p->lchild == NULL) {
		f->lchild = p->rchild;
		delete p;
	}
	/*p��������������*/
	else {
		/*����p������������*/
		/*sΪp�����������½�㣬psΪs��˫��*/
		BiNode *ps, *s;
		ps = p;
		s = p->rchild;
		while(s->lchild != NULL) {
			ps = s;
			s = s->lchild;
		} 
		p->data = s->data;
		/*p���Һ���û����������p���Һ���������*/
		if(ps == p) {
			p->rchild = s->rchild;
		} 
		/*p���Һ�������������p�ĺ����s*/
		else {
			ps->lchild = s->rchild;
		}
		delete s;
	}
}
