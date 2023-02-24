 #include "ConBitree2.cpp " 
int main()
{
	BiTree T;
	int len;
	char in[MAXSIZE], post[MAXSIZE];
	cout<<"由中序序列和后序序列构造二叉树： "<<endl;
	cout<<"请输入中序的字符串序列：";//DBGEACF
	gets(in);
	printf("请输入后序的字符串序列：");//DGEBFCA
	gets(post);
	len = strlen(post);
	CreateBiTree(&T, in, post, len);
	TreePrint(T, 1);
	printf("\n建立的二叉树先序遍历结果是： \n");
	PreTraverse(T);
	printf("\n建立的二叉树层序遍历结果是： \n");
	PrintLevel(T);
	printf("\n");
	cout << "是李树臻做的" << endl;
	system("pause");
}

