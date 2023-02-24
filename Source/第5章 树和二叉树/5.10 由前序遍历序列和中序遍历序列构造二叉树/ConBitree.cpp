#include "ConBitree.h" 
#include <bits/stdc++.h>

using namespace std;

node *createNode(int Xb, int Xe, int Zb, int Ze,string xianxu,string zhongxu)
{
	if(Xb >Xe)
		return NULL;
	node *Node = new node;
	Node->data = xianxu[Xb];
	int k=0;
	for (int i = Zb; i <Ze+1; i++)
	{
		if (xianxu[Xb] == zhongxu[i])
		{
			k = i;
			break;
		}
	}
	Node->lchild = createNode(Xb + 1, Xb+k-Zb, Zb, k - 1, xianxu, zhongxu);
	Node->rchild = createNode(Xb+k-Zb + 1, Xe, k + 1, Ze, xianxu, zhongxu);
	
	return Node;

}
void houxu(node *Node)
{
	if (Node == NULL)
		return;
	houxu(Node->lchild);
	houxu(Node->rchild);
	cout << Node->data;
}

