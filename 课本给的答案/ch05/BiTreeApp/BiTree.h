#ifndef BITREE_H
#define BITREE_H
int countLeaf = 0; /*全局变量，统计叶子结点个数，初值为0*/
int countNode = 0; /*全局变量，统计结点个数，初值为0*/
/*二叉树的结点结构*/
template <class ElemType>
struct BiNode{
	ElemType data;
	BiNode<ElemType> *lchild,*rchild;
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
	int Depth() {
		return Depth(root);
	}
	void Count() {
		Count(root);
	}
	void CountLeaf() {
		 CountLeaf(root);
	}
	void PrintLeaf() {
		PrintLeaf(root);
	}
private:
	BiNode<ElemType> *root; /*指向根结点的头指针*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*构造函数调用*/
	void Release(BiNode<ElemType> *bt); /*析构函数调用*/
	int Depth(BiNode<ElemType> *bt); /*求二叉树的深度*/
	void Count(BiNode<ElemType> *bt); /*求二叉树结点的个数*/
	void CountLeaf(BiNode<ElemType> *bt); /*求二叉树中叶子结点的个数*/
	void PrintLeaf(BiNode<ElemType> *bt); /*打印二叉树中的叶子结点*/
};
#endif
