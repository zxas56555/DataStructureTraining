#ifndef BITREE_H
#define BITREE_H
/*二叉树的结点结构*/
template <class ElemType>
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
	int SmallestDepth() {
		return SmallestDepth(root);
	}      
private:
	BiNode<ElemType> *root; /*指向根结点的头指针*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*构造函数调用*/
	int SmallestDepth(BiNode<ElemType> *bt); /*求二叉树的最小深度*/
};
#endif
