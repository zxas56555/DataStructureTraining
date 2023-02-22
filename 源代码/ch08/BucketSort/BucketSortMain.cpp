#include <iostream>
#include <stdlib.h>
#define MaxSize 20
using namespace std;
/*对长度为n的数组a[]进行桶式排序*/
/*数组a[]的值范围为0~m - 1*/ 
void BucketSort(int a[], int n, int m) {
    int i, j = 0;
    /*t用来记录每个桶内的元素个数*/
    int *t = new int[m];
    /*初始化为0*/
    for(i = 0; i < m; i++)
        t[i] = 0;
    /*统计每个桶的元素个数*/
    for(i = 0; i < n; i++)
        t[a[i]]++;
    /*收集桶内元素，重置数组a[]*/
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
	cout<<"排序之前：";
	PrintArray(a, n);
	BucketSort(a, 12, 10);
	cout<<"排序之后：";
	PrintArray(a, n);
	return 0;
}
