#ifndef BITREE_H
#define BITREE_H
/*ȫ�ֱ�����ͳ��Ҷ�ӽ���������ֵΪ0*/
int countLeaf = 0;
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
	void CountLeaf() {
		 CountLeaf(root);
	}
	int Depth() {
		return Depth(root);
	}
private:
	BiNode<ElemType> *root; /*ָ�������ͷָ��*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*���캯������*/
	int Depth(BiNode<ElemType> *bt); /*��������ĸ߶�*/
	void CountLeaf(BiNode<ElemType> *bt); /*���������Ҷ�ӽ��ĸ���*/
};
#endif
