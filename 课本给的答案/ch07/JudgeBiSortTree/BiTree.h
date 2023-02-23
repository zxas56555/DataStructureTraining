#ifndef BITREE_H
#define BITREE_H
/*�����������������ֵ*/
#define MaxSize 20 
/*�������Ľ��ṹ*/
struct BiNode{
	int data;       
	BiNode *lchild, *rchild;
};
/*��¼�������еĽ�����*/
int k = 0;
/*��¼�������������������*/
int a[MaxSize];

class BiTree{
public:
	/*���캯��������һ�ö�����*/
	BiTree() {
		root = Creat(root);
	}
	/*�������������*/
	void InOrder() {
		InOrder(root);
	} 
	/*�����������ĵݹ��ж�*/
	int IsBiSortTree() {
		return IsBiSortTree(root);
	} 
private:
	BiNode *root; /*ָ�������ͷָ��*/
	BiNode *Creat(BiNode *bt); /*���캯������*/
	void InOrder(BiNode *bt); /*���������������*/
	int IsBiSortTree(BiNode *bt); /*�ж϶������Ƿ��Ƕ���������*/ 
};
#endif
