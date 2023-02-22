#include <iostream>
#include <ctime> 
#include <cstdlib>
#define MaxSize 20
using namespace std;
/*�ݹ���۰���ң�����������������������������У�r[low...high]��Ѱ�ҹؼ���k*/ 
int RecurBinSearch(int r[], int low, int high, int k) {
	int mid;
	if(low > high)
		return 0;
	else {
		mid = (low + high) / 2;
		if(k < r[mid])
			/*�������������*/
			return RecurBinSearch(r, low, mid - 1, k);
		else if(k > r[mid])
			/*�Ұ�����������*/
			return RecurBinSearch(r, mid + 1, high, k);
		else 
			/*���ҳɹ�*/
			return mid;
	}
}

int main() {
	int i, n, k;
	int r[MaxSize + 1];
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
	int pos = RecurBinSearch(r, 1, n, k);
	if(pos == 0)
		cout<<"����ʧ�ܣ�˳����в�����"<<k<<"��"<<endl;
	else
		cout<<"���ҳɹ���"<<k<<"��˳����е�λ����"<<pos<<"��"<<endl;
	return 0;
}
