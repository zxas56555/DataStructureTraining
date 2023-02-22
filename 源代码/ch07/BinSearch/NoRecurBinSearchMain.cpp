#include <iostream>
#include <ctime> 
#include <cstdlib>
#define MaxSize 20
using namespace std;
/*�ǵݹ���۰���ң�����������������������������У���r[begin...end]��Ѱ�ҹؼ���k*/
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
	cout<<"������˳���ĳ��ȣ�"<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "����n���Ϸ���������[0,20]֮���������";
	}
	/*��ʼ��˳����ұ�*/
	/*�Ե�ǰʱ�俪ʼ���������*/
	srand((unsigned)time(NULL));
	r[1] = rand() % 11;
	for(i = 2; i <= n; i++)
		r[i] = r[i-1] + rand() % 11;
	cout<<"���ɵ��������Ϊ��"<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
  	cout<<"������Ҫ���ҵĹؼ��ֵ�ֵ��"<<endl;
	cin>>k;
	int pos = NoRecurBinSearch(r, 1, n, k);
	if(pos == 0)
		cout<<"����ʧ�ܣ�˳����в�����"<<k<<"��"<<endl;
	else
		cout<<"���ҳɹ���"<<k<<"��˳����е�λ����"<<pos<<"��"<<endl;
	return 0;
}
