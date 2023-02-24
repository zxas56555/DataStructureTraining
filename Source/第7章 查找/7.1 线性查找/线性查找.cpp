#include<iostream>
using namespace std;
#define  MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType  *R; //表基址
    int length;   //表长
}SSTable;
void Create_Seq(SSTable &ST,ElemType key)
{
    cout<<"请输入建表元素个数:";
    int n;
    cin>>n;
    ST.length=n;
    ST.R= new ElemType[MAXSIZE];
    cout<<"请输入"<<n<<"个建表元素:";
    for(int i=1;i<=n;i++)
    {
        cin>>ST.R[i];
    }
}
int Search_Seq(SSTable ST,ElemType key)
{
    //若成功返回其位置信息，否则返回0
    ST.R[0]=key;
    int i;
    for(i=ST.length;ST.R[i]!=key;--i);
    return i;
}
int main()
{
    SSTable ST;
    int key,pos;
    Create_Seq(ST,key);//建表
    cout<<"请输入要查询的数:";
    cin>>key;
    //查找
    pos=Search_Seq(ST,key);
    cout<<"查找值的位置:"<<pos<<endl;
    cout<<"是李鹏辉做的"<<endl;
    return 0;
}