#include <iostream>
#include <stdlib.h>
#define MaxSize 20
using namespace std;
/*�Գ���Ϊn������a[]����Ͱʽ����*/
/*����a[]��ֵ��ΧΪ0~m - 1*/ 
void BucketSort(int a[], int n, int m) {
    int i, j = 0;
    /*t������¼ÿ��Ͱ�ڵ�Ԫ�ظ���*/
    int *t = new int[m];
    /*��ʼ��Ϊ0*/
    for(i = 0; i < m; i++)
        t[i] = 0;
    /*ͳ��ÿ��Ͱ��Ԫ�ظ���*/
    for(i = 0; i < n; i++)
        t[a[i]]++;
    /*�ռ�Ͱ��Ԫ�أ���������a[]*/
    for(i = 0; i < m; i++) {
    	while(t[i]-- > 0)
            a[j++] = i;
	}   
    delete[] t;
}

void PrintArray(int a[],int n) {
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main() {
	int a[MaxSize] = {3, 4, 6, 9, 0, 5, 2, 3, 5, 1, 3, 4};
	int n = 12;
	int m = 10;
	cout<<"����֮ǰ��";
	PrintArray(a, n);
	BucketSort(a, 12, 10);
	cout<<"����֮��";
	PrintArray(a, n);
	return 0;
}
