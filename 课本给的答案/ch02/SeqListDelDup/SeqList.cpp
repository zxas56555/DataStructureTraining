#include "SeqList.h"
/*SeqList.h中定义的SeqList类的详细实现*/
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
ElemType SeqList<ElemType>::Delete(int i) {
	if(length == 0) 
		throw "顺序表为空，不能删除元素，下溢";
	if(i < 1||i > length) 
		throw "删除元素的逻辑位置非法，合法位置应为1~length";
	ElemType x = data[i-1]; /*取出位置i的元素*/
    for(int j = i; j < length; j++)
		data[j-1] = data[j]; /*元素data[i]...data[length-1]前移，方向从前向后*/
    length--;
    return x;
}

template <class ElemType>  
void SeqList<ElemType>::PrintList() {
	for (int i = 0; i < length; i++)
		cout<<data[i]<<" "; /*依次输出线性表的元素值*/
	cout<<endl;
}

