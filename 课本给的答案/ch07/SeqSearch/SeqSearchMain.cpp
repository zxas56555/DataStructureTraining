#include <iostream>
#define MaxSize 20
using namespace std;
/*˳����ң�0���±괦����ڱ�*/
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
	cout<<"������˳���ĳ��ȣ�"<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		cout<<"����n���Ϸ���������[0,20]֮���������";
	}
	cout<<"������˳����Ԫ��ֵ���ÿո������"<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	cout<<"������Ҫ���ҵĹؼ��ֵ�ֵ��"<<endl;
	cin>>k;
	int pos=SeqSearch(r, n, k);
	if(pos == 0)
		cout<<"����ʧ�ܣ�˳����в�����"<<k<<"��"<<endl;
	else
		cout<<"���ҳɹ���"<<k<<"��˳����е�λ����"<<pos<<"��"<<endl;
	return 0;
}
