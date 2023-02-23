#ifndef BITREE_H
#define BITREE_H
/*�������Ľ��ṹ*/
struct BiNode{
	char data;       
	BiNode *lchild, *rchild;
};

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
	/*ǰ��ǵݹ����������*/
	void PreOrder() {
		PreOrder(root);
	}
	/*����ǵݹ����������*/
	void InOrder() {
		InOrder(root);
	} 
	/*����ǵݹ����������*/
	void PostOrder() {
		PostOrder(root);
	}
private:
	BiNode *root; /*ָ�������ͷָ��*/
	BiNode *Creat(BiNode *bt); /*���캯������*/
	void Release(BiNode *bt); /*������������*/
	void PreOrder(BiNode *bt); /*ǰ�������������*/
	void InOrder(BiNode *bt); /*���������������*/
	void PostOrder(BiNode *bt); /*���������������*/
};
#endif
