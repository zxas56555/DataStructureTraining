#include "ConBitree.cpp" 
int main()
{
	string xianxu;
	string zhongxu;
	cout<<"������ǰ��������У�"; 
	while (cin >> xianxu) {
			cout<<"����������������У�"; 
		cin >> zhongxu;
		int Xb, Xe, Zb, Ze;//Xb��ʾ����ʼ�ַ�λ��Xe��ʾ��������ַ�λ�� Zb��ʾ����ʼ�ַ�λ��,Ze��ʾ��������ַ�λ��
		Xb = Zb = 0;
		Xe = xianxu.length() - 1;
		Ze = zhongxu.length() - 1;
		node *Node = new node;
		Node = createNode(Xb, Xe, Zb, Ze, xianxu, zhongxu);
		cout<<"�����������Ϊ��"; 
		houxu(Node);
		cout << "������������" << endl;
	}
		system("pause");
	return 0;
}

