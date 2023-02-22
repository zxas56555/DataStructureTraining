#include <iostream>
#include <ctime> 
#include <cstdlib>
#define MaxSize 20
using namespace std;
/*非递归的折半查找，采用随机函数创建递增的整数数列，在r[begin...end]中寻找关键字k*/
int NoRecurBinSearch(int r[], int begin, int end, int k) {
	int low, high, mid;
	low = begin;
	high = end;
	while(low <= high) {
		mid = (low + high)/2;
		if(k < r[mid])
			high = mid-1;
		else if(k > r[mid])
			low = mid+1;
		else
			return mid;
	}
	return 0;
}

int main() {
	int i, n, k;
	int r[MaxSize+1];
	cout<<"请输入顺序表的长度："<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "参数n不合法，请输入[0,20]之间的整数！";
	}
	/*初始化顺序查找表*/
	/*以当前时间开始的随机种子*/
	srand((unsigned)time(NULL));
	r[1] = rand() % 11;
	for(i = 2; i <= n; i++)
		r[i] = r[i-1] + rand() % 11;
	cout<<"生成的随机数列为："<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
  	cout<<"请输入要查找的关键字的值："<<endl;
	cin>>k;
	int pos = NoRecurBinSearch(r, 1, n, k);
	if(pos == 0)
		cout<<"查找失败！顺序表中不存在"<<k<<"！"<<endl;
	else
		cout<<"查找成功！"<<k<<"在顺序表中的位置是"<<pos<<"！"<<endl;
	return 0;
}
