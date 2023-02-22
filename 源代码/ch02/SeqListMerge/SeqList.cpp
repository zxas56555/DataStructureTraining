#include "SeqList.h"
/*SeqList.h�ж����SeqList�����ϸʵ��*/
using namespace std;
template <class ElemType>
SeqList<ElemType>::SeqList() {
	length = 0;
}

template <class ElemType>  
SeqList<ElemType>::SeqList(ElemType a[], int n) {
	if(n > MaxSize)
		throw "�����Ƿ�����������ĳ��ȳ�����˳�����������";
    for(int i = 0; i < n; i++)
		data[i] = a[i];
	/*˳���ĳ���Ϊ��������ĳ���*/
    length = n;
}

template <class ElemType>
SeqList<ElemType>::~SeqList() {
}

template <class ElemType>
int SeqList<ElemType>::Length() {
	return length;
}

template <class ElemType>  
ElemType SeqList<ElemType>::Get(int i) {
	if(i < 1 || i > length) 
		throw "����λ�÷Ƿ����Ϸ�λ��Ӧ��1~length֮��";
    else 
		return data[i-1];
}

template <class ElemType>  
void SeqList<ElemType>::Insert(int i, ElemType x) {
	if (length >= MaxSize) 
		throw "˳��������������ٲ���Ԫ�أ�����";
    if (i < 1|| i > length+1) 
		throw "����λ�ò��Ϸ����Ϸ��Ĳ���λ��ӦΪ1~length+1";
    for(int j = length; j >= i; j--)
		data[j] = data[j-1]; /*Ԫ��data[i-1]...data[length-1]���ƣ�����Ӻ���ǰ*/
    data[i-1] = x; /*��Ԫ��λ��*/
    length++;
}

template <class ElemType>  
void SeqList<ElemType>::PrintList() {
	for (int i = 0; i < length; i++)
		cout<<data[i]<<" "; /*����������Ա��Ԫ��ֵ*/
	cout<<endl;
}

