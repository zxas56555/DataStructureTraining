#include "BitreeNum.cpp" 
int main(int argc, char* argv[])
{
	BiTree T = NULL;
	CreateBiTree(T);
	int leaf = LeafCount(T);
	cout<<"��������Ҷ�ӽ�������"<<leaf<<endl;
	int nodes = Nodes(T);
	cout<<"�������н�������"<<nodes<<endl;
	cout << "������������" << endl;
	return 0;
}

