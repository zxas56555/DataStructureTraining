#include <iostream>
using namespace std; /*使用std命名空间，避免命名冲突*/
#include "SeqList.cpp"

template <class ElemType>
void DelDup(SeqList<ElemType> &L) {
	int i,j;
	for(i = 1; i <= L.Length(); i++) {
		j = i+1;
		while((j <= L.Length()) &&(L.Get(i) == L.Get(j))) {
			L.Delete(j);
			/*注意此处没有j++,L.Delete(j)执行时，data[j+1]已经前移到data[j]*/
		}
	}
}
int main() {
	int r[10] = {2, 4, 4, 4, 10, 10, 14, 14, 18, 19};
	SeqList<int> L(r, 10);
	cout<<"删除重复元素之前的有序表为：";
	L.PrintList();
	int i, j;
	DelDup(L);
	cout<<"删除重复元素之后的有序表为：";
	L.PrintList();
	return 0;
}
