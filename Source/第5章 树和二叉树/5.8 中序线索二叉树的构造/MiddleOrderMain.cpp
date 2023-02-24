#include "MiddleOrder.cpp" 
int main(){
	BiTree T;
	InitBiTree(&T);
	cout<<"请按照先序地方式输入二叉树(输入#代表空)："<<endl;
	createBiTree(&T);
	cout<<"该二叉树的中序遍历是："; 
	InOrder(T);
	cout << "是李树臻做的" << endl; 
	return 0;
}

