#ifndef BITREE_H
#define BITREE_H
int countLeaf = 0; /*ȫ�ֱ�����ͳ��Ҷ�ӽ���������ֵΪ0*/
int countNode = 0; /*ȫ�ֱ�����ͳ�ƽ���������ֵΪ0*/
/*�������Ľ��ṹ*/
template <class ElemType>
struct BiNode{
	ElemType data;
	BiNode<ElemType> *lchild,*rchild;
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
	int Depth() {
		return Depth(root);
	}
	void Count() {
		Count(root);
	}
	void CountLeaf() {
		 CountLeaf(root);
	}
	void PrintLeaf() {
		PrintLeaf(root);
	}
private:
	BiNode<ElemType> *root; /*ָ�������ͷָ��*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt); /*���캯������*/
	void Release(BiNode<ElemType> *bt); /*������������*/
	int Depth(BiNode<ElemType> *bt); /*������������*/
	void Count(BiNode<ElemType> *bt); /*����������ĸ���*/
	void CountLeaf(BiNode<ElemType> *bt); /*���������Ҷ�ӽ��ĸ���*/
	void PrintLeaf(BiNode<ElemType> *bt); /*��ӡ�������е�Ҷ�ӽ��*/
};
#endif
