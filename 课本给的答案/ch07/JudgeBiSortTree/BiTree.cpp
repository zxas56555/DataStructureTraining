#include <iostream>
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

void BiTree::InOrder(BiNode *bt) {
	if(bt == NULL)  
		return; /*�ݹ���õı߽�����*/	          
    else {	
        InOrder(bt->lchild); /*�ݹ����������*/
        a[k++] = bt->data; /*����ǰ������ݱ��浽����a��*/ 
        cout<<bt->data<<" "; /*���ʸ����*/
        InOrder(bt->rchild); /*�ݹ����������*/
	}
}

int BiTree::IsBiSortTree(BiNode *bt) {
	/*�ж϶�������������������Ƿ����*/
	for(int i = 1; i < k; i++) {
		if(a[i] <= a[i-1]) {
			return 0;
		}
	} 
	return 1;
}

