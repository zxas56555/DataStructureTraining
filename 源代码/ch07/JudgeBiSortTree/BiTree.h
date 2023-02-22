#ifndef BITREE_H
#define BITREE_H
/*二叉树结点个数的最大值*/
#define MaxSize 20 
/*二叉树的结点结构*/
struct BiNode{
	int data;       
	BiNode *lchild, *rchild;
};
/*记录二叉树中的结点个数*/
int k = 0;
/*记录二叉树的中序遍历序列*/
int a[MaxSize];

class BiTree{
public:
	/*构造函数，建立一棵二叉树*/
	BiTree() {
		root = Creat(root);
	}
	/*中序遍历二叉树*/
	void InOrder() {
		InOrder(root);
	} 
	/*二叉排序树的递归判断*/
	int IsBiSortTree() {
		return IsBiSortTree(root);
	} 
private:
	BiNode *root; /*指向根结点的头指针*/
	BiNode *Creat(BiNode *bt); /*构造函数调用*/
	void InOrder(BiNode *bt); /*中序遍历函数调用*/
	int IsBiSortTree(BiNode *bt); /*判断二叉树是否是二叉排序树*/ 
};
#endif
