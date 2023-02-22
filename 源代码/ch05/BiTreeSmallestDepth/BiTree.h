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
	int SmallestDepth() {
		return SmallestDepth(root);
	}      
private:
	BiNode<ElemType> *root; /*ָ�������ͷָ��*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*���캯������*/
	int SmallestDepth(BiNode<ElemType> *bt); /*�����������С���*/
};
#endif
