#ifndef BITREE_H
#define BITREE_H
#define NODESLENGTH 6
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
	void GetMirror() {
		GetMirror(root);
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
private:
	BiNode<ElemType> *root; /*指向根结点的头指针*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*构造函数调用*/
	void GetMirror(BiNode<ElemType> *bt); /*求二叉树的镜像*/ 
	void PostOrder(BiNode<ElemType> *bt); /*后序遍历二叉树*/ 
	void PreOrder(BiNode<ElemType> *bt); /*前序遍历二叉树*/
	void InOrder(BiNode<ElemType> *bt); /*中序遍历二叉树*/
};
#endif
