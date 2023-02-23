#ifndef BITREE_H
#define BITREE_H
/*二叉树的结点结构*/
struct BiNode{
	char data;       
	BiNode *lchild, *rchild;
};

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
	/*前序非递归遍历二叉树*/
	void PreOrder() {
		PreOrder(root);
	}
	/*中序非递归遍历二叉树*/
	void InOrder() {
		InOrder(root);
	} 
	/*后序非递归遍历二叉树*/
	void PostOrder() {
		PostOrder(root);
	}
private:
	BiNode *root; /*指向根结点的头指针*/
	BiNode *Creat(BiNode *bt); /*构造函数调用*/
	void Release(BiNode *bt); /*析构函数调用*/
	void PreOrder(BiNode *bt); /*前序遍历函数调用*/
	void InOrder(BiNode *bt); /*中序遍历函数调用*/
	void PostOrder(BiNode *bt); /*后序遍历函数调用*/
};
#endif
