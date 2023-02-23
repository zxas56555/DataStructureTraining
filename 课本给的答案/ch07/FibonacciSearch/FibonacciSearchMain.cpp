#include <memory>  
#include <iostream> 
#define MaxSize 20 /*斐波那契数组的长度*/
using namespace std;  
    
/*构造一个斐波那契数组*/   
void Fibonacci(int *F) {  
    F[0] = 0;  
    F[1] = 1;  
    for(int i = 2; i < MaxSize; ++i)  
        F[i] = F[i-1] + F[i-2];  
}  
   
/*斐波那契查找，在r[0...n-1]中查找key*/
int FibonacciSearch(int r[], int n, int key, int &count) {  
	int low = 0;  
	int high = n-1;   
	int F[MaxSize];  
  	Fibonacci(F); /*构造一个斐波那契数组F*/    
  	int k = 0;  
  	while(n > F[k]-1) /*计算n位于斐波那契数列的位置*/  
      	++k;  
  	int  *temp; /*将数组a扩展到F[k]-1的长度*/  
	temp = new int [F[k]-1];  
	memcpy(temp, r, n * sizeof(int));  
  	for(int i = n; i < F[k] - 1; ++i)  
     	temp[i] = r[n-1];  
  	while(low <= high) {  
    	int mid = low + F[k - 1] - 1; 
		count++; 
    	if(key < temp[mid]) {  
      		high = mid-1;  
      		k -= 1;  
    	}	  
    	else if(key > temp[mid]) {  
     		low = mid+1;  
     		k -= 2;  
    	}	  
    	else {  
       		if(mid < n)  
           		return mid; /*若相等则说明mid即为查找到的位置*/  
       		else  
           		return n - 1; /*若mid>=n则说明是扩展的数值,返回n-1*/  
    	}		  
  	}    
  	delete [] temp;  
  	return -1;  
}  
   
int main() {  
    int r[] = {0, 16, 24, 35, 47, 59, 62, 73, 88, 99};  
    int key = 62;  
    int count = 0;
    int n = sizeof(r) / sizeof(int);
    int index = FibonacciSearch(r, n, key, count); 
    cout<<"查找表为："<<endl;
    for(int i = 0; i < n; i++)
    	cout<<r[i]<<" ";
	cout<<endl; 
    if(index!=-1) {
    	cout<<"查找成功，"<<key<<"的下标是"<<index<<"！"<<endl; 	
	}
	else {
		cout<<"查找失败！"<<endl;
	}
	cout<<"比较了"<<count<<"次！"<<endl;
    return 0;  
}  
