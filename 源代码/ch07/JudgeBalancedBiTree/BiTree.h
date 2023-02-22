#ifndef BITREE_H
#define BITREE_H
/*�����������������ֵ*/
#define MaxSize 20 
/*�������Ľ��ṹ*/
struct BiNode{
	int data;       
	BiNode *lchild, *rchild;
};

class BiTree{
public:
	/*���캯��������һ�ö�����*/
	BiTree() {
		root = Creat(root);
	}
	/*ƽ����������ж�*/
	int IsBalancedBiTree() {
		return IsBalancedBiTree(root);
	} 
	int Depth() {
		return Depth(root);
	}
private:
	BiNode *root; /*ָ�������ͷָ��*/
	BiNode *Creat(BiNode *bt); /*���캯������*/
	int IsBalancedBiTree(BiNode *bt); /*�ж϶������Ƿ���ƽ�������*/ 
	int Depth(BiNode *bt); /*������������*/
};
#endif
