#include <iostream>
#include <stdlib.h>
#include <ctime>
#define MaxSize 20 /*ɢ�б�������ֵ*/
using namespace std;

/*ɢ�б�ı�Ϊm��ɢ�к���ΪH(key) = key % p������̽�⴦���ͻ*/ 
/*���ҹؼ���key��������ҳɹ����򷵻�key���±�*/
/*�������ʧ�ܣ��򷵻�0������key����ɢ�б���±�j��*/
int HashSearch(int ht[], int m, int key, int &j, int &count, int p) {
	int i;
	j = key % p;
	count = 1;
	if(ht[j] == key) /*�Ƚ�1�Σ����ҳɹ�*/ 
		return j;
	else if(ht[j] == 0) { /*����ʧ�ܣ���k����ɢ�б�*/
		ht[j] = key;
		return 0;
	} 
	/*�Ƚ�1�κ�û���ҵ�������̽���������*/
	i = (j + 1) % m;
	/*��ɢ�е�ַ����ʱѭ������ɢ�б�һ��*/
	while(ht[i] != 0 && i != j) {
		count++;
		/*���ҳɹ�*/
		if(ht[i] == key) {
			j = i;
			return 1;
		}
		/*�����Ƚ���һ��λ��*/
		else {
			i = (i + 1) % m;
		}
	}
	/*����ʧ�ܣ�����ɢ�б���û�п���λ��*/
	if(i == j) {
		cout<<"�ռ䲻�㣬�����";
		return 0;
	}
	/*���ҵ�����λ���˳�ѭ��������k*/
	else {
		ht[i] = key;
		j = i;
		return 0;
	}
} 

void PrintArray(int ht[], int m) {
	for(int i = 0; i < m; i++)
		cout<<ht[i]<<" ";
	cout<<endl;
}

int main() {	
	int s[MaxSize] = {26, 36, 41, 38, 44, 15, 68, 12, 06, 51, 25};
	int n = sizeof(s)/sizeof(int);
	int p = 13, m = 15;
	int ht[MaxSize] = {0};
	int key, i = 0, index = 0, count = 0;
	/*�����ɢ�б�*/
	for(i = 0; i < n; i++)
		HashSearch(ht, m, s[i], index, count, p); 
	/*���ɢ�б�*/
	cout<<"��ɢ�б�Ϊ��"<<endl;
	PrintArray(ht, m);
	cout<<"��������ҹؼ���(!=0)��";
	cin>>key;
	int result = HashSearch(ht, m, key, index, count, p);
	if(result != 0) {
		cout<<"���ҳɹ����ؼ���"<<key<<"���±�Ϊ"<<index<<"��"<<endl;
		cout<<"���Ƚ�"<<count<<"�Σ�" <<endl;
	}
	else {
		cout<<"����ʧ�ܣ�ԭɢ�б���û�йؼ���"<<key<<"��"<<endl;
		cout<<"����ؼ���"<<key<<"�����ɢ�б�Ϊ��"<<endl;
		PrintArray(ht, m); 
		cout<<"�¹ؼ���"<<key<<"��ɢ�б���±�"<<index<<"����"<<endl; 
	}
	return 0;
}
