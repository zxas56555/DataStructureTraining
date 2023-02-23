#ifndef BITREE_H
#define BITREE_H
/*二叉树结点个数的最大值*/
#define MaxSize 20 
/*二叉树的结点结构*/
struct BiNode{
	int data;       
	BiNode *lchild, *rchild;
};

class BiTree{
public:
	/*构造函数，建立一棵二叉树*/
	BiTree() {
		root = Creat(root);
	}
	/*平衡二叉树的判断*/
	int IsBalancedBiTree() {
		return IsBalancedBiTree(root);
	} 
	int Depth() {
		return Depth(root);
	}
private:
	BiNode *root; /*指向根结点的头指针*/
	BiNode *Creat(BiNode *bt); /*构造函数调用*/
	int IsBalancedBiTree(BiNode *bt); /*判断二叉树是否是平衡二叉树*/ 
	int Depth(BiNode *bt); /*求二叉树的深度*/
};
#endif
