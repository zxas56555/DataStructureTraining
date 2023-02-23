/*使用单链表求两个集合的并集*/ 
#include<iostream>
using namespace std;
#include "LinkList.cpp"
template <class ElemType>
void Union(LinkList<ElemType> &L1, LinkList<ElemType> &L2) {
	/*将单链表L1和L2存储的集合求并集至L1*/
	/*即将L2中存在但L1中不存在的元素插入到L1中*/
	Node<ElemType> *first1, *first2;
	first1 = L1.GetFirst(); /*获取单链表L1的头指针*/
	first2 = L2.GetFirst(); /*获取单链表L2的头指针*/
	Node<ElemType> *p,*q;
	p = first2->next;
	while(p != NULL) {
		/*在L1中查找p的数据域是否已存在*/
		int i = L1.Locate(p->data);
		/*未找到，将p插入到L1的表头位置*/
		if(i == 0) {
		    q = p->next;
			first2->next = q;
			p->next = first1->next;
			first1->next = p;		 
			p = q;
	    }
	    /*已找到，p的数据域已在L1中存在，后移p*/ 
	    else {
	    	p = p->next;
		}
	} 
}
int main() {
	int r1[7] = {1, 2, 3, 4, 5, 6, 7};
	int r2[8]={14, 2, 3, 13, 8, 6, 9, 7};
	/*第一个单链表的表长为7*/
	LinkList<int> L1(r1, 7);
	/*第二个单链表的表长为8*/
	LinkList<int> L2(r2, 8);
	cout<<"第一个集合为："<<endl;
	L1.PrintList();
	cout<<"第二个集合为："<<endl;
	L2.PrintList();
	cout<<"两个集合的并集为："<<endl;
	Union(L1,L2);
	L1.PrintList();
	return 0;
}

