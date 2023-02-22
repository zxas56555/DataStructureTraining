#ifndef INTHRBITREE_H
#define INTHRBITREE_H /*�����ظ�����ͷ�ļ�*/

/*�����������Ľ��ṹ*/
template <class ElemType>
struct ThrBiNode{
	ElemType data;       
	ThrBiNode<ElemType> *lchild, *rchild;
	int ltag,rtag; /*0��ʾ���ӣ�1��ʾ����*/
};

template <class ElemType>
class InThrBiTree{
public:	
	InThrBiTree(); /*���캯��������һ����������������*/
	ThrBiNode<ElemType> *Next(ThrBiNode<ElemType> *p); /*�����������������ϲ���p�ĺ��*/
	void InOrder(); /*�������������������������*/
private:
	ThrBiNode<ElemType> *root; /*ָ�������ͷָ��*/
	ThrBiNode<ElemType> *pre; /*��ǰ������ǰ�����*/
	ThrBiNode<ElemType> *Creat(ThrBiNode<ElemType> *bt); /*���캯������*/
	void ThrBiTree(ThrBiNode<ElemType> *bt); /*�ݹ������������*/ 
};
#endif
