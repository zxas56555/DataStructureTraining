#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;
#define MaxSize 10
/*ʹ�������Ϊ���ԽǾ��󸳳�ֵ*/ 
void InitMatrix(int A[][MaxSize], int n) {
	int a = 10;
	int b = 50;
	srand((unsigned)time(NULL)); 
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(abs(i - j) <= 1)
				A[i][j] = (rand() % (b - a)) + a;
			else
			 	A[i][j] = 0;
		}
	}
}

/*������ԽǾ���*/ 
void PrintMatrix(int A[][MaxSize],int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout.width(3);		
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}		
}

/*�����ԽǾ���Aѹ���洢��һά����SA��*/ 
void CompressMatrix(int A[][MaxSize], int SA[], int n) {
	int k = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			if(A[i][j] != 0) {
				SA[k++] = A[i][j];
			}
		}
}

/*���������±���һά����SA�ж�ȡ����Ԫ��*/ 
int GetElement(int SA[], int i, int j, int n) {
	if(i < 0 || i >= n || j < 0 || j >= n)
		throw "�����Ƿ�";
	if(abs(i-j) <= 1)
		return SA[2 * i + j];
	else
		return 0;
}

int main() {
	int A[MaxSize][MaxSize], n;
	int SA[MaxSize*(MaxSize + 1) / 2];
	int i, j;
	cout<<"����������������(<=10)��"<<endl; 
	cin>>n;
	InitMatrix(A, n);
	cout<<"���ԽǾ���Ϊ��"<<endl;
	PrintMatrix(A, n);
	CompressMatrix(A, SA, n);
	cout<<"���������Ԫ�ص������±�i��j��"<<endl;
	cin>>i>>j;
	cout<<"A["<<i<<"]["<<j<<"]��ֵΪ"<<GetElement(SA, i, j, n)<<endl;
	return 0;
}
