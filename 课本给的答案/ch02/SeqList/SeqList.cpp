#include "SeqList.h"
/*SeqList.h�ж����SeqList�����ϸʵ��*/
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
int SeqList<ElemType>::Locate(ElemType x) {
	for (int i = 0; i < length; i++)
    if(data[i] == x) 
		return i+1; /*��data[i]=x���������߼�λ��i+1*/
    return 0; /*����ʧ�ܣ�����0*/
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
ElemType SeqList<ElemType>::Delete(int i) {
	if(length == 0) 
		throw "˳���Ϊ�գ�����ɾ��Ԫ�أ�����";
	if(i < 1 || i > length) 
		throw "ɾ��Ԫ�ص��߼�λ�÷Ƿ����Ϸ�λ��ӦΪ1~length";
	ElemType x = data[i-1]; /*ȡ��λ��i��Ԫ��*/
    for(int j = i; j < length; j++)
		data[j-1] = data[j]; /*Ԫ��data[i]...data[length-1]ǰ�ƣ������ǰ���*/
    length--;
    return x;
}

template <class ElemType>  
void SeqList<ElemType>::PrintList() {
	for (int i = 0; i < length; i++)
		cout<<data[i]<<" "; /*����������Ա��Ԫ��ֵ*/
	cout<<endl;
}

