#ifndef BITREE_H
#define BITREE_H
#define NODESLENGTH 6
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
	void GetMirror() {
		GetMirror(root);
	} 
	void PostOrder() {
		PostOrder(root);
	}
	void PreOrder() {
		PreOrder(root);
	} 
	void InOrder() {
		InOrder(root);
	}
private:
	BiNode<ElemType> *root; /*ָ�������ͷָ��*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*���캯������*/
	void GetMirror(BiNode<ElemType> *bt); /*��������ľ���*/ 
	void PostOrder(BiNode<ElemType> *bt); /*�������������*/ 
	void PreOrder(BiNode<ElemType> *bt); /*ǰ�����������*/
	void InOrder(BiNode<ElemType> *bt); /*�������������*/
};
#endif
