#include <iostream>  
#include <iomanip>
using namespace std;
#define MaxSize 100
/*�ж��±�Ϊi, j����Ԫ���Ƿ���Ҫȡ��*/
int judge(int i, int j) {
	int flag = 0;
	/*���Խ����ϵ�Ԫ��*/
	if(i == j) return 1;
	/*���Խ�������С���������Խ����ϵ�Ԫ��*/
	else if(i > j && (i - j) % 4 == 0)
		return 1;
	/*���Խ�������С���������Խ����ϵ�Ԫ��*/
	else if(j > i && (j - i) % 4 == 0)
		return 1;
	/*С�����ϴζԽ����ϵ�Ԫ��*/
	else if((i + j + 1) % 4==0)
		return 1;
	else 
		return 0;
}

/*˫ż�׻÷��Ĺ��췽��*/
void MagicSquresDoubleEven(int a[][MaxSize], int n) {
	int i, j;
	/*��ʼ���÷�*/ 
	/*��1-n*n����˳����д���÷���*/
	int k = 1;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			a[i][j] = k++;
	for(i = 0; i< n; i++) {
		for(j = 0; j < n; j++) {
			if(judge(i, j) == 1)
				a[i][j] = n*n + 1 - a[i][j];
		}
	}
}

/*����÷�*/
void PrintMagicSquares(int a[][MaxSize], int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			/*Ԥ��������Ϊ5���ַ�*/
			cout<<setw(5)<<a[i][j];
		}
		cout<<endl;
	}
}

int main() {
	int a[MaxSize][MaxSize];
	int i, j;
	int n;
	cout<<"������÷��Ľ���������ΪС��MaxSize��4�ı�����:"<<endl;
	cin>>n;
	if(n < 0 || n % 4 != 0 || n > MaxSize)
		throw "����n���Ϸ���";
	MagicSquresDoubleEven(a, n);
	cout<<n<<"�׻÷�Ϊ��"<<endl;
	PrintMagicSquares(a, n);
	return 0;
}
