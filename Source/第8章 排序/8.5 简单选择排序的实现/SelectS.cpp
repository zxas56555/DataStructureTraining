#include <bits/stdc++.h>

using namespace std;

int main(){
	int i,N; 
	cout<<"���������ݸ�����"<<endl; 
	cin>>N; 
	int a[N]; 
    cout<<"�������ݣ�";
	for(i=0;i<N;i++)
		cin>>a[i]; 
    int k,t;
   
    for(int i=0;i<N-1;i++){
    	k=i;
    	for(int j=i+1;j<N;j++)
        	if(a[j]<a[k])
            	k=j;
        	if(k != i){
            	t = a[k];
            	a[k] = a[i];
            	a[i] = t;
        	}
    }
    cout<<"������ݣ�" ; 
    for(int i=0;i<N;i++)
        cout<<a[i]<<" ";
    cout << endl;
    cout << "������������" << endl;
}
