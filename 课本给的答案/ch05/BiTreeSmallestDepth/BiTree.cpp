#include <iostream>
using namespace std;
#include "BiTree.h"

template <class ElemType>
BiNode<ElemType> *BiTree<ElemType>::Creat(BiNode<ElemType> *bt) {
	char ch;
	cout<<"�����봴��һ�ö������Ľ�����ݣ�"<<endl;
	cin>>ch;
	/*'#'����ն�����*/
    if(ch == '#') 
		return NULL;
    else { 
		bt = new BiNode<ElemType>; /*�����½��*/
        bt->data = ch;
        bt->lchild = Creat(bt->lchild); /*�ݹ鴴��������*/
        bt->rchild = Creat(bt->rchild); /*�ݹ鴴��������*/
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

