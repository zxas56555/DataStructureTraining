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
		/*�ж�bt�Ƿ���Ҷ��*/ 
		if(k == 1) {
			if(bt->lchild == NULL && bt->rchild == NULL)
				return 1;
			else 
				return 0;
		}
		/*�ݹ������������е�Ҷ�����ĺ�*/
		if(k > 1) {
			return GetLeafNodesNumberOfKthLevel(bt->lchild, k - 1) + GetLeafNodesNumberOfKthLevel(bt->rchild, k - 1);
		}
	}
}

