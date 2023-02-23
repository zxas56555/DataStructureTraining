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
	bool IsSymmetric() {
		return IsSymmetric(root);
	}               
private:
	BiNode<ElemType> *root; /*ָ�������ͷָ��*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*���캯������*/
	int IsSymmetric(BiNode<ElemType> *bt); /*�ж϶������Ƿ�Գ�*/
	int IsCheck(BiNode<ElemType> *lchild, BiNode<ElemType> *rchild); /*�жϷǿն����������������Ƿ�Գ�*/ 
};
#endif
