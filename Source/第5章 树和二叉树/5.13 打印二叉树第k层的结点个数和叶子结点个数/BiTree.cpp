#include <bits/stdc++.h>

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
		/*�ж�bt�Ƿ���Ҷ��*/ 
		if(k == 1) {
			if(bt->lchild == NULL && bt->rchild == NULL)
				cout<<bt->data<<" ";
		}		
		else if(k > 1) {
			/*�ݹ��ӡ��������k-1���Ҷ�ӽ��*/
			PrintLeafNodesOfKthLevel(bt->lchild, k - 1); 
			/*�ݹ��ӡ���ӽ��k-1���Ҷ�ӽ��*/
			PrintLeafNodesOfKthLevel(bt->rchild, k - 1); 
		}
	}
}
