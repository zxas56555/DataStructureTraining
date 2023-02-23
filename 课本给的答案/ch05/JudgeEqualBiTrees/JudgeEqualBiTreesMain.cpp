#include <iostream>
using namespace std;
#include "BiTree.cpp"
template <class ElemType> 
int IsEqualBiTrees(BiNode<ElemType> *T1, BiNode<ElemType> *T2) {
	/*两棵二叉树都为空，返回1 */
	if(T1 == NULL && T2 == NULL)
		return 1;
	/*两棵二叉树一棵为空，一棵不为空，返回0 */
	if(T1 == NULL || T2 == NULL)
		return 0;
	/*两棵二叉树都不为空，并且根结点数据域不相等，返回0 */
	if(T1->data != T2->data)
		return 0;
	/*递归判断左子树和右子树是否等价*/ 
	return IsEqualBiTrees(T1->lchild, T2->lchild) && IsEqualBiTrees(T1->rchild, T2->rchild); 
}

int main() {
	cout<<"第一棵二叉树"<<endl;	
	BiTree<char> T1;
	cout<<"第二棵二叉树"<<endl;
	BiTree<char> T2;
	BiNode<char> *root1,*root2;
	root1 = T1.GetRoot();
	root2 = T2.GetRoot(); 
	int flag = IsEqualBiTrees(root1, root2);
	if(flag)
		cout<<"两棵二叉树等价！"<<endl;
	else
		cout<<"两棵二叉树不等价！"<<endl;
	return 0;
}
