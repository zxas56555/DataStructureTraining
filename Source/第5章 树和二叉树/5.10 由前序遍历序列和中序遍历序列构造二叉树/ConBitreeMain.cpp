#include "ConBitree.cpp" 
int main()
{
	string xianxu;
	string zhongxu;
	cout<<"请输入前序遍历序列："; 
	while (cin >> xianxu) {
			cout<<"请输入中序遍历序列："; 
		cin >> zhongxu;
		int Xb, Xe, Zb, Ze;//Xb表示先序开始字符位置Xe表示先序结束字符位置 Zb表示中序开始字符位置,Ze表示中序结束字符位置
		Xb = Zb = 0;
		Xe = xianxu.length() - 1;
		Ze = zhongxu.length() - 1;
		node *Node = new node;
		Node = createNode(Xb, Xe, Zb, Ze, xianxu, zhongxu);
		cout<<"后序遍历序列为："; 
		houxu(Node);
		cout << "是李树臻做的" << endl;
	}
		system("pause");
	return 0;
}

