#include <iostream>
using namespace std;
#define MaxSize 50
/*������ʵ��Լɪ������*/
void Josephus(int n, int m) {
	if(n < 0 || m < 0)
		throw "����m���Ϸ���";
	/*��¼���*/
	int r[MaxSize];
	/*����*/
	int k = 0;
	/*�ѳ��ӵ���*/
	int j = 0;
	/*�����鸳��ֵ*/
	int i;
	for(i = 0; i < n; i++)
		r[i] = i+1;
	i = 0;
	cout<<"���Ӵ���Ϊ��";
	while(i < n) {
		if(r[i] != 0) {
			k++;
		}
		/*����*/
		if(k == m) {
			k = 0;
			cout<<r[i]<<" ";
			r[i] = 0;
			j++;
		}
		/*ȫ������ʱ�˳�ѭ��*/
		if(j == n)
			break;		
		i = (i + 1) % n;
	}
}
int main() {
	
	int n;
	cout<<"����������n��"<<endl;
	cin>>n;
	if(n < 0 || n > MaxSize)
		throw "����n���Ϸ���";
	int m;
	cout<<"����������m��"<<endl;
	cin>>m;
    Josephus(n, m);
	cout<<endl;
	return 0;
}
