#include "Depth.cpp"
#include <bits/stdc++.h>

using namespace std;


int main()
{
	BiTree T = NULL; /*�ʼTָ���*/
		cout<<"��������һ������������#Ϊ����������";
	CreatBiTree(&T); /*����������*/
	cout<<endl; 
	cout<<"�����������Ϊ"<<getBitreeDepth(T)<<endl;
	getchar() ;
	getchar() ;
}

