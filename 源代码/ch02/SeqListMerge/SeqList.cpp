#include "SeqList.h"
/*SeqList.h中定义的SeqList类的详细实现*/
using namespace std;
template <class ElemType>
SeqList<ElemType>::SeqList() {
	length = 0;
}

template <class ElemType>  
SeqList<ElemType>::SeqList(ElemType a[], int n) {
	if(n > MaxSize)
		throw "参数非法，数组参数的长度超过了顺序表的最大容量";
    for(int i = 0; i < n; i++)
		data[i] = a[i];
	/*顺序表的长度为数组参数的长度*/
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
		throw "查找位置非法，合法位置应在1~length之间";
    else 
		return data[i-1];
}

template <class ElemType>  
void SeqList<ElemType>::Insert(int i, ElemType x) {
	if (length >= MaxSize) 
		throw "顺序表已满，不能再插入元素，上溢";
    if (i < 1|| i > length+1) 
		throw "插入位置不合法，合法的插入位置应为1~length+1";
    for(int j = length; j >= i; j--)
		data[j] = data[j-1]; /*元素data[i-1]...data[length-1]后移，方向从后向前*/
    data[i-1] = x; /*新元素位置*/
    length++;
}

template <class ElemType>  
void SeqList<ElemType>::PrintList() {
	for (int i = 0; i < length; i++)
		cout<<data[i]<<" "; /*依次输出线性表的元素值*/
	cout<<endl;
}

