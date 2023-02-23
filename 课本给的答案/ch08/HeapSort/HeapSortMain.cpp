#include <iostream>
#define MaxSize 20 /*˳������󳤶�Ϊ20*/
using namespace std;

/*�������k�����������������Ǵ���ѣ����µ����ɴ���ѣ��������Ϊm��*/
void Adjust(int r[], int k, int m) {
	int i, j;
	int temp;
	i = k;
	j = 2 * i;
	while(j <= m) {
		/*jָ��i�����Һ����нϴ��*/
		if(j < m && r[j + 1] > r[j])
			j++;
		/*������ϴ����Ҫ��������*/
		if(r[i] >= r[j])
			break;
		else {
			/*����r[i]��r[j]*/
			temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			/*��������һ���жϣ�ֱ��Ҷ�ӽ���*/
			i = j;
			j = 2 * i;
		}
	}
}

void HeapSort(int r[], int n) {		
	int i, temp;
	/*��ʼ���������*/
	for(i = n / 2; i >= 1; i--)
		Adjust(r, i, n);
	for(i = 1; i < n; i++) {
		/*r[1]�Ǵ�����Ԫ��������*/
		/*r[1]��r[n-i+1]����*/
		temp = r[1];
		r[1] = r[n - i + 1];
		r[n - i + 1] = temp;
		/*�������1��n-iʹ֮���³�Ϊ�����*/
		Adjust(r, 1, n - i);
	}
}

int main() {
	int i, n;
	int r[MaxSize + 1];
	cout<<"������˳���ĳ��ȣ�"<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "�������Ϸ���������[0,20]֮���ֵ��";
	}
	cout<<"������������˳���Ԫ�أ�"<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	HeapSort(r, n);
	cout<<"������֮���˳���Ϊ��"<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
