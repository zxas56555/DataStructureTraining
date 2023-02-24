#include "MiddleOrder.h " 
#include <bits/stdc++.h>

using namespace std;

void InitBiTree(BiTree *T){
	*T = NULL;
}

/*
创建树，以先序方式插入树节点 
*/
void createBiTree(BiTree *T){
	char ch;
	cin>>ch;
	if(ch =='#') *T=NULL;
	else{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!(*T)) exit(-1);
		//按照先序的方式插入生成树 
		(*T)->data = ch;
		createBiTree(&((*T)->lchild));
		createBiTree(&((*T)->rchild));
	}
}

/*
利用栈，对二叉树进行非递归中序遍历 
*/
void InOrder(BiTree T){
	BiTree p = T;//p是遍历指针 
	while(p||!s.empty()){//当栈不空或p不空时进入下面循环 
		if(p){ 			//如果p不为空就一路向左并将所有左孩子入栈 
			s.push(p);
			p = p->lchild;
		}else{			//当碰到最后一个左孩子的左节点为空时，进入该循环，进行出栈 
			p=s.top();
			cout<<p->data<<" ";
			s.pop();
			p = p->rchild;//出完栈后，转到右孩子 
		}
	}
	cout<<endl;
}

