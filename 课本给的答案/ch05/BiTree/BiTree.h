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
	/*析构函数，释放各结点*/
	~BiTree() {
		Release(root);
	}
	/*前序遍历二叉树*/
	void PreOrder() {
		PreOrder(root);
	}
	/*中序遍历二叉树*/
	void InOrder() {
		InOrder(root);
	} 
	/*后序遍历二叉树*/
	void PostOrder() {
		PostOrder(root);
	}
	/*层序遍历二叉树*/
	void LevelOrder() {
		LevelOrder(root);
	};                 
private:
	BiNode<ElemType> *root; /*指向根结点的头指针*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*构造函数调用*/
	void Release(BiNode<ElemType> *bt); /*析构函数调用*/
	void PreOrder(BiNode<ElemType> *bt); /*前序遍历函数调用*/
	void InOrder(BiNode<ElemType> *bt); /*中序遍历函数调用*/
	void PostOrder(BiNode<ElemType> *bt); /*后序遍历函数调用*/
	void LevelOrder(BiNode<ElemType> *bt); /*层序遍历函数调用*/
};
#endif
