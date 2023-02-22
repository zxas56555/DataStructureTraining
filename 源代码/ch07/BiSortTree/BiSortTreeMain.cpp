#include <iostream>
using namespace std;
#include "BiSortTree.cpp"
int main() {
	int a[] = {61, 87, 59, 47, 35, 73, 51, 98, 37, 93};
	int n, i, k;
	cout<<"请输入二叉排序树结点个数(<=10)：";
	cin>>n;
	if(n < 0 || n > 10)
		throw "参数错误！"; 
	BiSortTree T(a, n);
	cout<<"构造的二叉排序树中序遍历序列为："<<endl;
	T.InOrder();
	cout<<endl;
	cout<<"请输入要查找的关键码值：";
	cin>>k;
	if(T.Search(k) == NULL)
		cout<<"二叉排序树中不存在关键码"<<k<<"!";
	else
		cout<<"二叉排序树中存在关键码"<<k<<"!"; 
	cout<<endl;
	cout<<"删除关键字47"<<endl;
	T.DeleteBST(T.Search(47),T.Search(59));
	cout<<"删除47以后的二叉树的中序遍历序列为："<<endl;
	T.InOrder();
	return 0;
}
