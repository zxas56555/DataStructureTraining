#include<iostream>
using namespace std;
#define  MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType  *R; //���ַ
    int length;   //��
}SSTable;
void Create_Seq(SSTable &ST,ElemType key)
{
    cout<<"�����뽨��Ԫ�ظ���:";
    int n;
    cin>>n;
    ST.length=n;
    ST.R= new ElemType[MAXSIZE];
    cout<<"������"<<n<<"������Ԫ��:";
    for(int i=1;i<=n;i++)
    {
        cin>>ST.R[i];
    }
}
int Search_Seq(SSTable ST,ElemType key)
{
    //���ɹ�������λ����Ϣ�����򷵻�0
    ST.R[0]=key;
    int i;
    for(i=ST.length;ST.R[i]!=key;--i);
    return i;
}
int main()
{
    SSTable ST;
    int key,pos;
    Create_Seq(ST,key);//����
    cout<<"������Ҫ��ѯ����:";
    cin>>key;
    //����
    pos=Search_Seq(ST,key);
    cout<<"����ֵ��λ��:"<<pos<<endl;
    cout<<"������������"<<endl;
    return 0;
}