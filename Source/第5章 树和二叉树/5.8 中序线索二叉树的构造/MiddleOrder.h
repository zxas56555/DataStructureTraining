#include <bits/stdc++.h>

using namespace std;

typedef struct BiTNode{
	char data;//������ 
	struct BiTNode *lchild,*rchild;//���Һ���ָ�� 
}BiTNode,*BiTree;
stack<BiTree> s;//����ջ����������� 

