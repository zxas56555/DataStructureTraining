#ifndef BITREE_H
#define BITREE_H

/*�������Ľ��ṹ*/
template <class ElemType>
struct BiNode{
	ElemType data;       
	BiNode<ElemType> *lchild, *rchild;
};

template <class ElemType>
class BiTree{
public:
	/*���캯��������һ�ö�����*/
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
	BiNode<ElemType> *root; /*ָ�������ͷָ��*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*���캯������*/
	void PrintNodesOfKthLevel(BiNode<ElemType> *bt, int k); /*��ӡ��k��Ľ��*/
	void PrintLeafNodesOfKthLevel(BiNode<ElemType> *bt, int k); /*��ӡ��k���Ҷ�ӽ��*/
};
#endif
