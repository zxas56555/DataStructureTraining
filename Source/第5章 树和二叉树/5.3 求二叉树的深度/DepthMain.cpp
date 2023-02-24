#include "Depth.cpp"
#include <bits/stdc++.h>

using namespace std;


int main()
{
	BiTree T = NULL; /*最开始T指向空*/
		cout<<"请您输入一个二叉树（以#为空子树）：";
	CreatBiTree(&T); /*创建二叉树*/
	cout<<endl; 
	cout<<"二叉树的深度为"<<getBitreeDepth(T)<<endl;
	getchar() ;
	getchar() ;
}

