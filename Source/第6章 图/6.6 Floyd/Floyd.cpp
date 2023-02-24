#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int e[10][10],k,i,j,n,m,t1,t2,t3;
    int inf=99999999; //用inf(infinity的缩写)存储一个我们认为的正无穷值
//读入n和m，n表示顶点个数，m表示边的条数
    cout<<"请分别输入顶点数和边数："<<endl;
    scanf("%d %d",&n,&m);
//初始化
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(i==j)
                e[i][j]=0;
            else
                e[i][j]=inf;
//读入边
    cout<<"请输入对应的边和权值："<<endl;
    for(i=1; i<=m; i++) {
        scanf("%d %d %d",&t1,&t2,&t3);
        e[t1][t2]=t3;
    }
//Floyd-Warshall算法核心语句
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(e[i][j]>e[i][k]+e[k][j] )
                    e[i][j]=e[i][k]+e[k][j];
//输出最终的结果
    cout<<"最终矩阵为："<<endl;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%10d",e[i][j]);
        }
        printf("\n");
    }
    cout<<"是李鹏辉做的"<<endl;
    return 0;
}
