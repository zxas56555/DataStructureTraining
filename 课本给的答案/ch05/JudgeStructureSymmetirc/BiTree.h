#ifndef BITREE_H
#define BITREE_H

template <class ElemType>
/*�������Ľ��ṹ*/
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
	/*�ж϶������Ƿ�ṹ�ԶԳ�*/
	int IsStructureSymmetric() {
		return IsStructureSymmetric(root);
	}               
private:
	BiNode<ElemType> *root; /*ָ�������ͷָ��*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*���캯������*/
	int IsStructureSymmetric(BiNode<ElemType> *bt);
	int IsCheck(BiNode<ElemType> *lchild, BiNode<ElemType> *rchild);
};
#endif
