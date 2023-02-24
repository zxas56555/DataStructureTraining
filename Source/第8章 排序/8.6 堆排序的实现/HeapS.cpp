#include <bits/stdc++.h>

using namespace std;
 
void adjust_heap(int* a, int node, int size){
        int left = 2*node + 1;
        int right = 2*node + 2;
        int max = node;
        if( left < size && a[left] > a[max])
                max = left;
        if( right < size && a[right] > a[max])
                max = right;
        if(max != node){
                swap( a[max], a[node]);
                adjust_heap(a, max, size);
        }
}
 
void heap_sort(int* a, int len){
        for(int i = len/2 -1; i >= 0; --i)
                adjust_heap(a, i, len);
 
        for(int i = len - 1; i >= 0; i--){
                swap(a[0], a[i]);           // 将当前最大的放置到数组末尾
                adjust_heap(a, 0 , i);              // 将未完成排序的部分继续进行堆排序
        }
}
 
int main(){
 	int i,N; 
	cout<<"请输入数据个数："; 
	cin>>N; 
	int a[N]; 
    cout<<"输入数据：";
	for(i=0;i<N;i++)
		cin>>a[i]; 
        int len= sizeof(a) / sizeof(int);
        heap_sort(a, len);
 		cout<<"输出数据：";
        for(int i = 0; i < len; ++i)
            cout << a[i] << ' ';
        	cout << endl;
        cout << "是李树臻做的" << endl;
        return 0;
}
