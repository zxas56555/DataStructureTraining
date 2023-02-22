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
	/*�����������ͷŸ����*/
	~BiTree() {
		Release(root);
	}
	/*ǰ�����������*/
	void PreOrder() {
		PreOrder(root);
	}
	/*�������������*/
	void InOrder() {
		InOrder(root);
	} 
	/*�������������*/
	void PostOrder() {
		PostOrder(root);
	}
	/*�������������*/
	void LevelOrder() {
		LevelOrder(root);
	};                 
private:
	BiNode<ElemType> *root; /*ָ�������ͷָ��*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*���캯������*/
	void Release(BiNode<ElemType> *bt); /*������������*/
	void PreOrder(BiNode<ElemType> *bt); /*ǰ�������������*/
	void InOrder(BiNode<ElemType> *bt); /*���������������*/
	void PostOrder(BiNode<ElemType> *bt); /*���������������*/
	void LevelOrder(BiNode<ElemType> *bt); /*���������������*/
};
#endif
