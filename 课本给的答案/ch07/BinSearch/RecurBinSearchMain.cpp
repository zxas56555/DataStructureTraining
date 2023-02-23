#include <iostream>
#include <ctime> 
#include <cstdlib>
#define MaxSize 20
using namespace std;
/*递归的折半查找，采用随机函数创建递增的整数数列，r[low...high]中寻找关键字k*/ 
int RecurBinSearch(int r[], int low, int high, int k) {
	int mid;
	if(low > high)
		return 0;
	else {
		mid = (low + high) / 2;
		if(k < r[mid])
			/*左半区继续查找*/
			return RecurBinSearch(r, low, mid - 1, k);
		else if(k > r[mid])
			/*右半区继续查找*/
			return RecurBinSearch(r, mid + 1, high, k);
		else 
			/*查找成功*/
			return mid;
	}
}

int main() {
	int i, n, k;
	int r[MaxSize + 1];
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
	int pos = RecurBinSearch(r, 1, n, k);
	if(pos == 0)
		cout<<"查找失败！顺序表中不存在"<<k<<"！"<<endl;
	else
		cout<<"查找成功！"<<k<<"在顺序表中的位置是"<<pos<<"！"<<endl;
	return 0;
}
