#include <bits/stdc++.h>

using namespace std; 

typedef struct BiTNode
{
	char data;  /*结点的数据域*/
	struct BiTNode *lchild , *rchild; /*指向左孩子和右孩子*/
} BiTNode , *BiTree;
/*创建一棵二叉树*/

