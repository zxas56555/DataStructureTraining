#include <iostream>
using namespace std; /*ʹ��std�����ռ䣬����������ͻ*/
#include "SeqList.cpp"

template <class ElemType>
void DelDup(SeqList<ElemType> &L) {
	int i,j;
	for(i = 1; i <= L.Length(); i++) {
		j = i+1;
		while((j <= L.Length()) &&(L.Get(i) == L.Get(j))) {
			L.Delete(j);
			/*ע��˴�û��j++,L.Delete(j)ִ��ʱ��data[j+1]�Ѿ�ǰ�Ƶ�data[j]*/
		}
	}
}
int main() {
	int r[10] = {2, 4, 4, 4, 10, 10, 14, 14, 18, 19};
	SeqList<int> L(r, 10);
	cout<<"ɾ���ظ�Ԫ��֮ǰ�������Ϊ��";
	L.PrintList();
	int i, j;
	DelDup(L);
	cout<<"ɾ���ظ�Ԫ��֮��������Ϊ��";
	L.PrintList();
	return 0;
}
