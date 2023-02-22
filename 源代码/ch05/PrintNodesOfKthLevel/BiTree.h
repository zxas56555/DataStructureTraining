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
	void PrintNodesOfKthLevel(int k) {
		PrintNodesOfKthLevel(root, k);
	}
	void PrintLeafNodesOfKthLevel(int k) {
		PrintLeafNodesOfKthLevel(root, k);
	}            
private:
	BiNode<ElemType> *root; /*指向根结点的头指针*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*构造函数调用*/
	void PrintNodesOfKthLevel(BiNode<ElemType> *bt, int k); /*打印第k层的结点*/
	void PrintLeafNodesOfKthLevel(BiNode<ElemType> *bt, int k); /*打印第k层的叶子结点*/
};
#endif
