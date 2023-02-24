#include <bits/stdc++.h>
#include "stdio.h"
#include "stdlib.h"

using namespace std; 

typedef struct BiTNode
{
	char data;//树中节点的数据
	struct BiTNode *lchild,*rchild;//节点的左孩子指针和右孩子指针
}BiTNode,*BiTree;//二叉树节点

