#include <bits/stdc++.h>

using namespace std;

typedef struct BiTNode{
	char data;//数据域 
	struct BiTNode *lchild,*rchild;//左右孩子指针 
}BiTNode,*BiTree;
stack<BiTree> s;//创建栈用于中序遍历 

