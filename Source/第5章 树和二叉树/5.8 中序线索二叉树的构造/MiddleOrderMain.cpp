#include "MiddleOrder.cpp" 
int main(){
	BiTree T;
	InitBiTree(&T);
	cout<<"�밴������ط�ʽ���������(����#�����)��"<<endl;
	createBiTree(&T);
	cout<<"�ö���������������ǣ�"; 
	InOrder(T);
	cout << "������������" << endl; 
	return 0;
}

