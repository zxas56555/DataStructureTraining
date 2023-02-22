#include <iostream>
using namespace std;
#include "LinkList.cpp"

template <class ElemType>
/*判断两个集合是否相等，相等返回1，不相等返回0*/ 
int SetIsEqual(LinkList<ElemType> &L1, LinkList<ElemType> &L2) {
	Node<ElemType> *p,*q;
	int flag = 1;
	p = L1.GetFirst()->next;
	q = L2.GetFirst()->next;
	/*两个链表都未结束时判断*/ 
	while(p != NULL && q != NULL) {
		/*如果数据域相等则继续比较*/
		if(p->data == q->data) {
			p = p->next;
			q = q->next;
		}
		/*相同位置的数据域不相等*/ 
		else {
			flag = 0;
			break;
		}
	}
	/*一个链表结束，另一个链表没结束*/
	/*并且已比较的部分相等*/ 
	if((flag == 1) && (p || q)) {
		flag = 0;
	}
	return flag;
}
void outResult(int flag) {
	if(flag) {
		cout<<"相等"; 
	}
	else {
		cout<<"不相等"; 
	}
	cout<<endl;
}
int main() {
	int s1[] = {1, 3, 5, 7, 9};
	int s2[] = {1, 3, 5, 7, 9};
	int s3[] = {2, 4, 6, 8, 10, 12};
	int s4[] = {2, 4, 6, 8, 10, 12, 14, 16}; 
	int s5[] = {1, 3, 6, 8, 10};
	LinkList<int> L1(s1, 5);
    LinkList<int> L2(s2, 5);
    LinkList<int> L3(s3, 6);
    LinkList<int> L4(s4, 8);
    LinkList<int> L5(s5, 5);
    cout<<"第一个集合：";
    L1.PrintList();
    cout<<"第二个集合：";
    L2.PrintList();
    cout<<"第三个集合：";
    L3.PrintList();
    cout<<"第四个集合：";
    L4.PrintList();
    cout<<"第五个集合：";
    L5.PrintList();
    cout<<"第一、二个集合是否相等？";
	outResult(SetIsEqual(L1,L2));
    cout<<"第三、四个集合是否相等？";
	outResult(SetIsEqual(L3,L4));
    cout<<"第二、五个集合是否相等？";
	outResult(SetIsEqual(L2,L5));
	return 0;
}
