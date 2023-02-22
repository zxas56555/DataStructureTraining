#ifndef BITREE_H
#define BITREE_H
/*全局变量，统计叶子结点个数，初值为0*/
int countLeaf = 0;
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
	void CountLeaf() {
		 CountLeaf(root);
	}
	int Depth() {
		return Depth(root);
	}
private:
	BiNode<ElemType> *root; /*指向根结点的头指针*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*构造函数调用*/
	int Depth(BiNode<ElemType> *bt); /*求二叉树的高度*/
	void CountLeaf(BiNode<ElemType> *bt); /*求二叉树中叶子结点的个数*/
};
#endif
