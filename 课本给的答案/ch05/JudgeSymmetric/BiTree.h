#ifndef BITREE_H
#define BITREE_H

template <class ElemType>
/*二叉树的结点结构*/
struct BiNode{
	ElemType data;       
	BiNode<ElemType> *lchild, *rchild;
};

template <class ElemType>
class BiTree{
public:
	/*构造函数，建立一棵二叉树*/
	BiTree() {
		root = Creat(root);
	}
	/*判断二叉树是否结构性对称*/
	bool IsSymmetric() {
		return IsSymmetric(root);
	}               
private:
	BiNode<ElemType> *root; /*指向根结点的头指针*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*构造函数调用*/
	int IsSymmetric(BiNode<ElemType> *bt); /*判断二叉树是否对称*/
	int IsCheck(BiNode<ElemType> *lchild, BiNode<ElemType> *rchild); /*判断非空二叉树的左右子树是否对称*/ 
};
#endif
