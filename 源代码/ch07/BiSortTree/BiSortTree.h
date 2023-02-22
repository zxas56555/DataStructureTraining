#ifndef BISORTTREE_H
#define BISORTTREE_H

/*二叉排序树的结点结构*/
struct BiNode{
	int data;       
	BiNode *lchild, *rchild;
};

class BiSortTree{
public:
	BiSortTree(int a[], int n); /*建立一棵二排序叉树*/
	~BiSortTree() { /*析构函数*/
		Release(root);
	}
	void InsertBST(BiNode *&root, BiNode *s); /*在二叉排序树中插入结点s*/
	BiNode *Search(int k) { /*在二叉排序树中查找关键码k*/
		return SearchBST(root, k);
	}
	void InOrder() { /*中序遍历*/
		InOrder(root); 
	}
	void DeleteBST(BiNode *p, BiNode *f); /*在二叉排序树中删除f的左孩子结点p*/
	BiNode *SearchBST(BiNode *root, int k); /*在二叉排序树中查找关键码k*/
private:
	BiNode *root; /*指向根结点的头指针*/
	void InOrder(BiNode *root); /*中序遍历*/
	void Release(BiNode *root); /*释放二叉排序树*/
};
#endif
