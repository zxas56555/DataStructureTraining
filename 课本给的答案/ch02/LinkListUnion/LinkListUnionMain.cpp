/*ʹ�õ��������������ϵĲ���*/ 
#include<iostream>
using namespace std;
#include "LinkList.cpp"
template <class ElemType>
void Union(LinkList<ElemType> &L1, LinkList<ElemType> &L2) {
	/*��������L1��L2�洢�ļ����󲢼���L1*/
	/*����L2�д��ڵ�L1�в����ڵ�Ԫ�ز��뵽L1��*/
	Node<ElemType> *first1, *first2;
	first1 = L1.GetFirst(); /*��ȡ������L1��ͷָ��*/
	first2 = L2.GetFirst(); /*��ȡ������L2��ͷָ��*/
	Node<ElemType> *p,*q;
	p = first2->next;
	while(p != NULL) {
		/*��L1�в���p���������Ƿ��Ѵ���*/
		int i = L1.Locate(p->data);
		/*δ�ҵ�����p���뵽L1�ı�ͷλ��*/
		if(i == 0) {
		    q = p->next;
			first2->next = q;
			p->next = first1->next;
			first1->next = p;		 
			p = q;
	    }
	    /*���ҵ���p������������L1�д��ڣ�����p*/ 
	    else {
	    	p = p->next;
		}
	} 
}
int main() {
	int r1[7] = {1, 2, 3, 4, 5, 6, 7};
	int r2[8]={14, 2, 3, 13, 8, 6, 9, 7};
	/*��һ��������ı�Ϊ7*/
	LinkList<int> L1(r1, 7);
	/*�ڶ���������ı�Ϊ8*/
	LinkList<int> L2(r2, 8);
	cout<<"��һ������Ϊ��"<<endl;
	L1.PrintList();
	cout<<"�ڶ�������Ϊ��"<<endl;
	L2.PrintList();
	cout<<"�������ϵĲ���Ϊ��"<<endl;
	Union(L1,L2);
	L1.PrintList();
	return 0;
}

