#include <bits/stdc++.h>

using namespace std; 


void shellsort(int a[],int left,int right){
    int d = (left+right)>>1;//d���� 
    while(d>0){
        for(int i = 0; i<right-d+1;i++)
        if(a[i]>a[i+d]){
            int temp = a[i+d];
            a[i+d]   = a[i];
            a[i]     = temp;
        }
        d=d>>1; 
    }
}
     
int main(){
	int a[10];
    cout<<"������10�����ݣ�";
    for(int i = 0;i<10;i++) 
   
    cin>>a[i]; 
    
    shellsort( a,0,9);
    cout<<"���к�����ݣ�"; 
    for(int i = 0;i<10;i++)
    cout<<a[i]<<" "; 
    getchar(); 
    cout << "������������" << endl;
    return 0;
}
