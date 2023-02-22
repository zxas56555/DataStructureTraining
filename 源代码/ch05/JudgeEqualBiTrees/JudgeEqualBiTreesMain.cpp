#include <iostream>
using namespace std;
#include "BiTree.cpp"
template <class ElemType> 
int IsEqualBiTrees(BiNode<ElemType> *T1, BiNode<ElemType> *T2) {
	/*���ö�������Ϊ�գ�����1 */
	if(T1 == NULL && T2 == NULL)
		return 1;
	/*���ö�����һ��Ϊ�գ�һ�ò�Ϊ�գ�����0 */
	if(T1 == NULL || T2 == NULL)
		return 0;
	/*���ö���������Ϊ�գ����Ҹ������������ȣ�����0 */
	if(T1->data != T2->data)
		return 0;
	/*�ݹ��ж����������������Ƿ�ȼ�*/ 
	return IsEqualBiTrees(T1->lchild, T2->lchild) && IsEqualBiTrees(T1->rchild, T2->rchild); 
}

int main() {
	cout<<"��һ�ö�����"<<endl;	
	BiTree<char> T1;
	cout<<"�ڶ��ö�����"<<endl;
	BiTree<char> T2;
	BiNode<char> *root1,*root2;
	root1 = T1.GetRoot();
	root2 = T2.GetRoot(); 
	int flag = IsEqualBiTrees(root1, root2);
	if(flag)
		cout<<"���ö������ȼۣ�"<<endl;
	else
		cout<<"���ö��������ȼۣ�"<<endl;
	return 0;
}
