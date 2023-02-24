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
	cout<<"请输入10个元素：";
	for ( i=0;i<length;i++)
	cin>>data[i];
	int x;
    cout<<"请输入你要查找的元素：";
	cin>>x;
	int loaction=Bisearch(data,x,0,9);
	if( loaction==-1)
	{
		cout<<"查找失败，没有你要查找的值"<<endl;
	}
	else
	{
		cout<<"你要查找的值"<<x<<"的位置在第"<<loaction+1<<"个位置"<<endl;
	}
	cout<<"是李鹏辉做的"<<endl;
	return 0;
}
