#include<iostream>
using namespace std;
#include "LinkList.cpp"
template <class ElemType>
void Intersection(LinkList<ElemType> &L1, LinkList<ElemType> &L2) {
	/*将单链表L1和L2存储的集合求交集并输出*/
	Node<ElemType> *first1,*p;
	first1 = L1.GetFirst();
	p = first1->next;
	while(p != NULL) {
		/*在L2中查找p的数据域是否已存在*/
		int i = L2.Locate(p->data);
		/*找到，输出p->data*/
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
	/*第一个单链表的表长为7*/
	LinkList<int> L1(r1, 7);
	/*第二个单链表的表长为8*/
	LinkList<int> L2(r2, 8);
	cout<<"第一个集合为："<<endl;
	L1.PrintList();
	cout<<"第二个集合为："<<endl;
	L2.PrintList();
	cout<<"两个集合的交集为："<<endl;
	Intersection(L1, L2);
	char r3[5] = {'A','B','C','D','E'};
	char r4[6] = {'C','D','E','F','G','H'};
	LinkList<char> L3(r3, 5);
	LinkList<char> L4(r4, 6);
	cout<<"第三个集合为："<<endl;
	L3.PrintList();
	cout<<"第四个集合为："<<endl;
	L4.PrintList();
	cout<<"两个集合的交集为："<<endl;
	Intersection(L3, L4);
	cout<<"\n此部分由刘宪铎完成"<<endl;
	return 0;
}
