#ifndef BITREE_H
#define BITREE_H
#define NodesLength 6
template <class ElemType>
/*二叉树的结点结构*/
struct BiNode{
	ElemType data;       
	BiNode<ElemType> *lchild, *rchild;
};

template <class ElemType>
class BiTree{
public:
	BiTree(ElemType *preOrder, ElemType *inOrder, int len) {
		root = Rebuild(preOrder, inOrder, len);
	}
	void PostOrder() {
		PostOrder(root);
	}
	void PreOrder() {
		PreOrder(root);
	} 
	void InOrder() {
		InOrder(root);
	}
	/*根据前序遍历和中序遍历重建二叉树*/
	BiNode<ElemType> *Rebuild(ElemType *preOrder, ElemType *inOrder, int len);
private:
	BiNode<ElemType> *root; /*指向根结点的头指针*/
	void PostOrder(BiNode<ElemType> *bt); /*后序遍历二叉树*/ 
	void PreOrder(BiNode<ElemType> *bt); /*前序遍历二叉树*/
	void InOrder(BiNode<ElemType> *bt); /*中序遍历二叉树*/
};
#endif
