#include<bits/stdc++.h>
using namespace std;
int   Bisearch(int data[],int x,int low ,int high)
{
	if(low>high)
	{
		return -1;
		exit(0);
	}
	int mid=(low+high)/2;
	if (x == data[mid])
	{
		return mid;
		exit(0);
	}
	if ( x < data[mid] )
	{
		Bisearch(data,x,low,mid-1);
	}
	else
		{
		Bisearch(data,x,mid+1,high);
		}

}
int main()
{	int i=0;
	int length=10;
	int data[10];
	cout<<"������10��Ԫ�أ�";
	for ( i=0;i<length;i++)
	cin>>data[i];
	int x;
    cout<<"��������Ҫ���ҵ�Ԫ�أ�";
	cin>>x;
	int loaction=Bisearch(data,x,0,9);
	if( loaction==-1)
	{
		cout<<"����ʧ�ܣ�û����Ҫ���ҵ�ֵ"<<endl;
	}
	else
	{
		cout<<"��Ҫ���ҵ�ֵ"<<x<<"��λ���ڵ�"<<loaction+1<<"��λ��"<<endl;
	}
	cout<<"������������"<<endl;
	return 0;
}
