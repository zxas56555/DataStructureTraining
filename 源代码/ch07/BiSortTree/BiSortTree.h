#ifndef BISORTTREE_H
#define BISORTTREE_H

/*�����������Ľ��ṹ*/
struct BiNode{
	int data;       
	BiNode *lchild, *rchild;
};

class BiSortTree{
public:
	BiSortTree(int a[], int n); /*����һ�ö��������*/
	~BiSortTree() { /*��������*/
		Release(root);
	}
	void InsertBST(BiNode *&root, BiNode *s); /*�ڶ����������в�����s*/
	BiNode *Search(int k) { /*�ڶ����������в��ҹؼ���k*/
		return SearchBST(root, k);
	}
	void InOrder() { /*�������*/
		InOrder(root); 
	}
	void DeleteBST(BiNode *p, BiNode *f); /*�ڶ�����������ɾ��f�����ӽ��p*/
	BiNode *SearchBST(BiNode *root, int k); /*�ڶ����������в��ҹؼ���k*/
private:
	BiNode *root; /*ָ�������ͷָ��*/
	void InOrder(BiNode *root); /*�������*/
	void Release(BiNode *root); /*�ͷŶ���������*/
};
#endif
