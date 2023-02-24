#ifndef BITREE_H
#define BITREE_H

using namespace std;

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
	int GetNodesNumberOfKthLevel(int k) {
		return GetNodesNumberOfKthLevel(root, k);
	} 	 
	int GetLeafNodesNumberOfKthLevel(int k) {
		return GetLeafNodesNumberOfKthLevel(root, k);
	};                 
private:
	BiNode<ElemType> *root;/*ָ�������ͷָ��*/
	BiNode<ElemType> *Creat(BiNode<ElemType> *bt);/*���캯������*/
	int GetNodesNumberOfKthLevel(BiNode<ElemType> *bt, int k); /*��ȡ��k��Ľ����*/
	int GetLeafNodesNumberOfKthLevel(BiNode<ElemType> *bt, int k); /*��ȡ��k���Ҷ�ӽ����*/
};
#endif
