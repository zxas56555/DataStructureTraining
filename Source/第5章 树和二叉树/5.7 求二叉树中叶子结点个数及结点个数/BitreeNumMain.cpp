#include "BitreeNum.cpp" 
int main(int argc, char* argv[])
{
	BiTree T = NULL;
	CreateBiTree(T);
	int leaf = LeafCount(T);
	cout<<"二叉树中叶子结点个数："<<leaf<<endl;
	int nodes = Nodes(T);
	cout<<"二叉树中结点个数："<<nodes<<endl;
	cout << "是李树臻做的" << endl;
	return 0;
}

