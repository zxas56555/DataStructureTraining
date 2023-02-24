#ifndef BITREE_H
#define BITREE_H

using namespace std;

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
	int GetNodesNumberOfKthLevel(int k) {
		return GetNodesNumberOfKthLevel(root, k);
	} 	 
	int GetLeafNodesNumberOfKthLevel(int k) {
		return GetLeafNodesNumberOfKthLevel(root, k);
	};                 
private:
	BiNode<ElemType> *root;/*指向根结点的头指针*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt);/*构造函数调用*/
	int GetNodesNumberOfKthLevel(BiNode<ElemType> *bt, int k); /*获取第k层的结点数*/
	int GetLeafNodesNumberOfKthLevel(BiNode<ElemType> *bt, int k); /*获取第k层的叶子结点数*/
};
#endif
