#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;
#define MaxSize 10
/*ʹ�������Ϊ�Գƾ��󸳳�ֵ*/ 
void InitMatrix(int A[][MaxSize], int n) {
	int a = 10;
	int b = 50;
	srand((unsigned)time(NULL)); 
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++) {
			A[i][j] = (rand() % (b - a)) + a;
			A[j][i] = A[i][j];
		} 
		
}
 
/*����Գƾ���*/ 
void PrintMatrix(int A[][MaxSize], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout.width(3);		
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}		
}

/*���Գƾ���A��������ѹ���������ǵ�һά����SA��*/ 
void CompressMatrix(int A[][MaxSize], int SA[], int n) {
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
			SA[i * (i + 1) / 2 + j] = A[i][j];
}

/*���������±���һά����SA�ж�ȡ����Ԫ��*/ 
int GetElement(int SA[], int i, int j, int n) {
	if(i < 0 || i >= n || j < 0 || j >= n)
		throw "�����Ƿ�";
	/*������Ԫ��*/ 
	if(i >= j)	
		return SA[i * (i + 1) / 2 + j];
	/*������Ԫ��*/ 
	else
		return SA[j * (j + 1) / 2 + i];
}

int main() {
	int A[MaxSize][MaxSize], n;
	int SA[MaxSize * (MaxSize + 1) / 2];
	int i, j;
	cout<<"����������������(<=10)��"<<endl; 
	cin>>n;
	InitMatrix(A, n);
	cout<<"�Գƾ���Ϊ��"<<endl;
	PrintMatrix(A, n);
	CompressMatrix(A, SA, n);
	cout<<"���������Ԫ�ص������±�i��j��"<<endl;
	cin>>i>>j;
	cout<<"A["<<i<<"]["<<j<<"]��ֵΪ"<<GetElement(SA, i, j, n)<<endl;
	return 0;
}
