#ifndef INTHRBITREE_H
#define INTHRBITREE_H /*避免重复引用头文件*/

/*线索二叉树的结点结构*/
template <class ElemType>
struct ThrBiNode{
	ElemType data;       
	ThrBiNode<ElemType> *lchild, *rchild;
	int ltag,rtag; /*0表示孩子，1表示线索*/
};

template <class ElemType>
class InThrBiTree{
public:	
	InThrBiTree(); /*构造函数，建立一棵中序线索二叉树*/
	ThrBiNode<ElemType> *Next(ThrBiNode<ElemType> *p); /*在中序线索二叉树上查找p的后继*/
	void InOrder(); /*在中序线索二叉树上中序遍历*/
private:
	ThrBiNode<ElemType> *root; /*指向根结点的头指针*/
	ThrBiNode<ElemType> *pre; /*当前根结点的前驱结点*/
	ThrBiNode<ElemType> *Creat(ThrBiNode<ElemType> *bt); /*构造函数调用*/
	void ThrBiTree(ThrBiNode<ElemType> *bt); /*递归的中序线索化*/ 
};
#endif
