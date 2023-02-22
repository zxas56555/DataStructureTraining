#include <iostream>
#include <cmath>
using namespace std;
#include "BiTree.h"

BiNode *BiTree::Creat(BiNode *bt) {
	int data;
	cout<<"�����봴��һ�ö������Ľ�����ݣ�"<<endl;
	cin>>data;
	/*-1����ն�����*/
    if(data == -1) {
		return NULL;
    }
    else { 
		bt = new BiNode; /*�����½��*/
        bt->data = data;
        bt->lchild = Creat(bt->lchild); /*�ݹ鴴��������*/
        bt->rchild = Creat(bt->rchild); /*�ݹ鴴��������*/
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
