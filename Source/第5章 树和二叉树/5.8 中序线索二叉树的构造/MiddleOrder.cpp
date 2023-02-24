#include "MiddleOrder.h " 
#include <bits/stdc++.h>

using namespace std;

void InitBiTree(BiTree *T){
	*T = NULL;
}

/*
��������������ʽ�������ڵ� 
*/
void createBiTree(BiTree *T){
	char ch;
	cin>>ch;
	if(ch =='#') *T=NULL;
	else{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!(*T)) exit(-1);
		//��������ķ�ʽ���������� 
		(*T)->data = ch;
		createBiTree(&((*T)->lchild));
		createBiTree(&((*T)->rchild));
	}
}

/*
����ջ���Զ��������зǵݹ�������� 
*/
void InOrder(BiTree T){
	BiTree p = T;//p�Ǳ���ָ�� 
	while(p||!s.empty()){//��ջ���ջ�p����ʱ��������ѭ�� 
		if(p){ 			//���p��Ϊ�վ�һ·���󲢽�����������ջ 
			s.push(p);
			p = p->lchild;
		}else{			//���������һ�����ӵ���ڵ�Ϊ��ʱ�������ѭ�������г�ջ 
			p=s.top();
			cout<<p->data<<" ";
			s.pop();
			p = p->rchild;//����ջ��ת���Һ��� 
		}
	}
	cout<<endl;
}

