#include <bits/stdc++.h>

using namespace std;

struct node
{
	char data;
	node * lchild;
	node * rchild;
};
node *createNode(int Xb, int Xe, int Zb, int Ze,string xianxu,string zhongxu);
void houxu(node *Node);

