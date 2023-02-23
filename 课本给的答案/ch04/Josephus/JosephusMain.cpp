#include <iostream>
using namespace std;
#define MaxSize 50
/*用数组实现约瑟夫环问题*/
void Josephus(int n, int m) {
	if(n < 0 || m < 0)
		throw "参数m不合法！";
	/*记录序号*/
	int r[MaxSize];
	/*报数*/
	int k = 0;
	/*已出队的数*/
	int j = 0;
	/*给数组赋初值*/
	int i;
	for(i = 0; i < n; i++)
		r[i] = i+1;
	i = 0;
	cout<<"出队次序为：";
	while(i < n) {
		if(r[i] != 0) {
			k++;
		}
		/*出队*/
		if(k == m) {
			k = 0;
			cout<<r[i]<<" ";
			r[i] = 0;
			j++;
		}
		/*全部出队时退出循环*/
		if(j == n)
			break;		
		i = (i + 1) % n;
	}
}
int main() {
	
	int n;
	cout<<"请输入人数n："<<endl;
	cin>>n;
	if(n < 0 || n > MaxSize)
		throw "参数n不合法！";
	int m;
	cout<<"请输入密码m："<<endl;
	cin>>m;
    Josephus(n, m);
	cout<<endl;
	return 0;
}
