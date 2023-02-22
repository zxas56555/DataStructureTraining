#ifndef BITREE_H
#define BITREE_H

template <class ElemType>
/*二叉树的结点结构*/
struct BiNode{
	ElemType data;
	BiNode<ElemType> *lchild, *rchild;
	int maxLeft; /*左子树结点的最大距离*/
	int maxRight; /*右子树结点的最大距离*/
};

template <class ElemType>
class BiTree{
public:
	/*构造函数，建立一棵二叉树*/
	BiTree() {
		root = Creat(root);
	}
	
	void GetMaxPathLength() {
		GetMaxPathLength(root);
	}             
private:
	BiNode<ElemType> *root; /*指向根结点的头指针*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*构造函数调用*/
	void GetMaxPathLength(BiNode<ElemType> *bt); /*求二叉树的结点的最大距离*/
};
#endif
