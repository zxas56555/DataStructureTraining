#include<iostream>
using namespace std;
#include "LinkList.cpp"
template <class ElemType>
void Intersection(LinkList<ElemType> &L1, LinkList<ElemType> &L2) {
	/*��������L1��L2�洢�ļ����󽻼������*/
	Node<ElemType> *first1,*p;
	first1 = L1.GetFirst();
	p = first1->next;
	while(p != NULL) {
		/*��L2�в���p���������Ƿ��Ѵ���*/
		int i = L2.Locate(p->data);
		/*�ҵ������p->data*/
		if(i != 0) {
		    cout<<p->data<<" ";
	    }
	    p = p->next;
	}
	cout<<endl;
}
int main() {
	int r1[7] = {1, 2, 3, 4, 5, 6, 7};
	int r2[8] = {5,6,7,8,9,10,11,12};
	/*��һ��������ı�Ϊ7*/
	LinkList<int> L1(r1, 7);
	/*�ڶ���������ı�Ϊ8*/
	LinkList<int> L2(r2, 8);
	cout<<"��һ������Ϊ��"<<endl;
	L1.PrintList();
	cout<<"�ڶ�������Ϊ��"<<endl;
	L2.PrintList();
	cout<<"�������ϵĽ���Ϊ��"<<endl;
	Intersection(L1, L2);
	char r3[5] = {'A','B','C','D','E'};
	char r4[6] = {'C','D','E','F','G','H'};
	LinkList<char> L3(r3, 5);
	LinkList<char> L4(r4, 6);
	cout<<"����������Ϊ��"<<endl;
	L3.PrintList();
	cout<<"���ĸ�����Ϊ��"<<endl;
	L4.PrintList();
	cout<<"�������ϵĽ���Ϊ��"<<endl;
	Intersection(L3, L4);
	cout<<"\n�˲��������������"<<endl;
	return 0;
}
