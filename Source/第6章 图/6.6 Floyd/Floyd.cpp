#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int e[10][10],k,i,j,n,m,t1,t2,t3;
    int inf=99999999; //��inf(infinity����д)�洢һ��������Ϊ��������ֵ
//����n��m��n��ʾ���������m��ʾ�ߵ�����
    cout<<"��ֱ����붥�����ͱ�����"<<endl;
    scanf("%d %d",&n,&m);
//��ʼ��
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(i==j)
                e[i][j]=0;
            else
                e[i][j]=inf;
//�����
    cout<<"�������Ӧ�ıߺ�Ȩֵ��"<<endl;
    for(i=1; i<=m; i++) {
        scanf("%d %d %d",&t1,&t2,&t3);
        e[t1][t2]=t3;
    }
//Floyd-Warshall�㷨�������
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(e[i][j]>e[i][k]+e[k][j] )
                    e[i][j]=e[i][k]+e[k][j];
//������յĽ��
    cout<<"���վ���Ϊ��"<<endl;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%10d",e[i][j]);
        }
        printf("\n");
    }
    cout<<"������������"<<endl;
    return 0;
}
