#include <iostream>
using namespace std;
#include "LinkList.cpp"

template <class ElemType>
/*�ж����������Ƿ���ȣ���ȷ���1������ȷ���0*/ 
int SetIsEqual(LinkList<ElemType> &L1, LinkList<ElemType> &L2) {
	Node<ElemType> *p,*q;
	int flag = 1;
	p = L1.GetFirst()->next;
	q = L2.GetFirst()->next;
	/*��������δ����ʱ�ж�*/ 
	while(p != NULL && q != NULL) {
		/*������������������Ƚ�*/
		if(p->data == q->data) {
			p = p->next;
			q = q->next;
		}
		/*��ͬλ�õ����������*/ 
		else {
			flag = 0;
			break;
		}
	}
	/*һ�������������һ������û����*/
	/*�����ѱȽϵĲ������*/ 
	if((flag == 1) && (p || q)) {
		flag = 0;
	}
	return flag;
}
void outResult(int flag) {
	if(flag) {
		cout<<"���"; 
	}
	else {
		cout<<"�����"; 
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
    cout<<"��һ�����ϣ�";
    L1.PrintList();
    cout<<"�ڶ������ϣ�";
    L2.PrintList();
    cout<<"���������ϣ�";
    L3.PrintList();
    cout<<"���ĸ����ϣ�";
    L4.PrintList();
    cout<<"��������ϣ�";
    L5.PrintList();
    cout<<"��һ�����������Ƿ���ȣ�";
	outResult(SetIsEqual(L1,L2));
    cout<<"�������ĸ������Ƿ���ȣ�";
	outResult(SetIsEqual(L3,L4));
    cout<<"�ڶ�����������Ƿ���ȣ�";
	outResult(SetIsEqual(L2,L5));
	return 0;
}
