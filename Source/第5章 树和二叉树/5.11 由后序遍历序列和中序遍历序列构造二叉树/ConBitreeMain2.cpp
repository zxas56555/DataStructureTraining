 #include "ConBitree2.cpp " 
int main()
{
	BiTree T;
	int len;
	char in[MAXSIZE], post[MAXSIZE];
	cout<<"���������кͺ������й���������� "<<endl;
	cout<<"������������ַ������У�";//DBGEACF
	gets(in);
	printf("�����������ַ������У�");//DGEBFCA
	gets(post);
	len = strlen(post);
	CreateBiTree(&T, in, post, len);
	TreePrint(T, 1);
	printf("\n�����Ķ����������������ǣ� \n");
	PreTraverse(T);
	printf("\n�����Ķ����������������ǣ� \n");
	PrintLevel(T);
	printf("\n");
	cout << "������������" << endl;
	system("pause");
}

