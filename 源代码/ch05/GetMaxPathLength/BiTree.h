#ifndef BITREE_H
#define BITREE_H

template <class ElemType>
/*�������Ľ��ṹ*/
struct BiNode{
	ElemType data;
	BiNode<ElemType> *lchild, *rchild;
	int maxLeft; /*����������������*/
	int maxRight; /*����������������*/
};

template <class ElemType>
class BiTree{
public:
	/*���캯��������һ�ö�����*/
	BiTree() {
		root = Creat(root);
	}
	
	void GetMaxPathLength() {
		GetMaxPathLength(root);
	}             
private:
	BiNode<ElemType> *root; /*ָ�������ͷָ��*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*���캯������*/
	void GetMaxPathLength(BiNode<ElemType> *bt); /*��������Ľ���������*/
};
#endif
