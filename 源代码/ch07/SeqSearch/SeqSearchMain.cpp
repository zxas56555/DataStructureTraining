#include <iostream>
#define MaxSize 20
using namespace std;
/*顺序查找，0号下标处存放哨兵*/
int SeqSearch(int r[], int n, int k) {
	int i;
	r[0] = k;
	i = n;
	while(r[i] != k)
		i--;
	return i;
}

int main() {
	int i, n, k;
	int r[MaxSize + 1];
	cout<<"请输入顺序表的长度："<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		cout<<"参数n不合法，请输入[0,20]之间的整数！";
	}
	cout<<"请输入顺序表的元素值，用空格隔开："<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	cout<<"请输入要查找的关键字的值："<<endl;
	cin>>k;
	int pos=SeqSearch(r, n, k);
	if(pos == 0)
		cout<<"查找失败！顺序表中不存在"<<k<<"！"<<endl;
	else
		cout<<"查找成功！"<<k<<"在顺序表中的位置是"<<pos<<"！"<<endl;
	return 0;
}
