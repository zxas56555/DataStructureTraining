#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;
#define MaxSize 10
/*ʹ�������Ϊ�����Ǿ��󸳳�ֵ*/ 
void InitMatrix(int A[][MaxSize], int n) {
	int a = 10;
	int b = 50;
	srand((unsigned)time(NULL)); 
	int c = (rand() % (b - a)) + a; 
	for(int i = 0; i < n; i++) { 
		for(int j = 0; j < i; j++) {
			A[i][j] = c;
		} 
		for(int j = i; j < n; j++) {
			A[i][j] = (rand() % (b - a)) + a;
		}	
    }		
} 

/*��������Ǿ���*/ 
void PrintMatrix(int A[][MaxSize], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout.width(3);		
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}		
}

/*�������Ǿ���Aѹ���洢��һά����SA��*/ 
void CompressMatrix(int A[][MaxSize], int SA[], int n) {
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			SA[i * (2 * n - i + 1) / 2 + j - i] = A[i][j];
	/*������c�洢������SA��*/
	SA[n * (n + 1) / 2] = A[n - 1][0]; 
}

/*���������±���һά����SA�ж�ȡ����Ԫ��*/ 
int GetElement(int SA[], int i, int j, int n) {
	if(i < 0 || i >= n || j < 0 || j >= n)
		throw "�����Ƿ�";
	/*������Ԫ��*/ 
	if(i <= j)	
		return SA[i * (2 * n - i + 1) / 2 + j - i];
	/*������Ԫ��*/ 
	else 
		return SA[n * (n + 1) / 2];
}

int main() {
	int A[MaxSize][MaxSize], n;
	int SA[MaxSize * (MaxSize + 1) / 2];
	int i, j;
	cout<<"����������������(<=10)��"<<endl; 
	cin>>n;
	InitMatrix(A, n);
	cout<<"�����Ǿ���Ϊ��"<<endl;
	PrintMatrix(A, n);
	CompressMatrix(A, SA, n);
	cout<<"���������Ԫ�ص������±�i��j��"<<endl;
	cin>>i>>j;
	cout<<"A["<<i<<"]["<<j<<"]��ֵΪ"<<GetElement(SA, i, j, n)<<endl;
	return 0;
}
