#include <memory>  
#include <iostream> 
#define MaxSize 20 /*쳲���������ĳ���*/
using namespace std;  
    
/*����һ��쳲���������*/   
void Fibonacci(int *F) {  
    F[0] = 0;  
    F[1] = 1;  
    for(int i = 2; i < MaxSize; ++i)  
        F[i] = F[i-1] + F[i-2];  
}  
   
/*쳲��������ң���r[0...n-1]�в���key*/
int FibonacciSearch(int r[], int n, int key, int &count) {  
	int low = 0;  
	int high = n-1;   
	int F[MaxSize];  
  	Fibonacci(F); /*����һ��쳲���������F*/    
  	int k = 0;  
  	while(n > F[k]-1) /*����nλ��쳲��������е�λ��*/  
      	++k;  
  	int  *temp; /*������a��չ��F[k]-1�ĳ���*/  
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
           		return mid; /*�������˵��mid��Ϊ���ҵ���λ��*/  
       		else  
           		return n - 1; /*��mid>=n��˵������չ����ֵ,����n-1*/  
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
    cout<<"���ұ�Ϊ��"<<endl;
    for(int i = 0; i < n; i++)
    	cout<<r[i]<<" ";
	cout<<endl; 
    if(index!=-1) {
    	cout<<"���ҳɹ���"<<key<<"���±���"<<index<<"��"<<endl; 	
	}
	else {
		cout<<"����ʧ�ܣ�"<<endl;
	}
	cout<<"�Ƚ���"<<count<<"�Σ�"<<endl;
    return 0;  
}  
