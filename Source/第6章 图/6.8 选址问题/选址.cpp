#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define MAXV 50
#define INF 32767
typedef int InfoType;
//邻接矩阵存储方法
typedef struct {
    int no;
    InfoType info;
} VertexType;
typedef struct {
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
} MGraph;
void Ppath(int path[], int i, int v) {
    int k;
    k = path[i];
    if (k == v) return;
    Ppath(path, k, v);
}
int dis[5][5]= {
    {0,32767,32767,32767},
    {32767,0,32767,32767},
    {32767,32767,0,32767},
    {32767,32767,32767,0}
} ;
int biaoji1 = 0, biaoji2 = 0;
void Dispath(int dist[], int path[], int s[], int n, int v) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == v) continue;
        if (s[i] == 1) {
// cout << "从" << v << "到" << i << "的最短路径为：" << dist[i] << " "<<endl;
            dis[v][i]=dist[i];
            Ppath(path, i, v);
            if (biaoji1 != 5) {
                biaoji2 += dist[i];
                biaoji1++;
            } else {
// cout << "和为：" << " " << biaoji2;
                biaoji1 = 0;
                biaoji2 = 0;
            }
        }
// else
// cout << "从" << v << "到" << i << "不存在的路径" << endl;
    }
}
void Dijkstra(MGraph g, int v) {
    int dist[MAXV], path[MAXV];
    int s[MAXV];
    int mindis, i, j, u;
    for (i = 0; i < g.n; i++) {
        dist[i] = g.edges[v][i];
        s[i] = 0;
        if (g.edges[v][i] < INF) path[i] = v;
        else path[i] = -1;
    }
    s[v] = 1;
    path[v] = 0;
    for (i = 0; i < g.n; i++) {
        mindis = INF;
        for (j = 0; j < g.n; j++) {
            if (s[j] == 0 && dist[j] < mindis) {
                u = j;
                mindis = dist[j];
            }
        }
        s[u] = 1;
        for (j = 0; j < g.n; j++) {
            if (s[j] == 0) {
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]) {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
            }
        }
    }
    Dispath(dist, path, s, g.n, v);
}
//主函数
int main() {
    int i, j, n=4;
    MGraph g;
    cout << "带权有向图的顶点个数为4"<<endl;
    cout << "带权有向图的邻接矩阵：" << endl;
    printf("\tA\tB\tC\tD\n");
    printf("A\t0\t5\tINF\t7\n");
    printf("B\tINF\t0\t4\t2\n");
    printf("C\t3\t3\t0\t2\n");
    printf("D\tINF\tINF\t1\t0\n");
    g.edges[0][0]=0;
    g.edges[0][1]=5;
    g.edges[0][2]=32767;
    g.edges[0][3]=7;
    g.edges[1][0]=32767;
    g.edges[1][1]=0;
    g.edges[1][2]=4;
    g.edges[1][3]=2;
    g.edges[2][0]=3;
    g.edges[2][1]=3;
    g.edges[2][2]=0;
    g.edges[2][3]=2;
    g.edges[3][0]=32767;
    g.edges[3][1]=32767;
    g.edges[3][2]=1;
    g.edges[3][3]=0;
    g.n = n;
    cout << "采用狄克斯特拉算法得到的最短路径矩阵为：" << endl;
    for (i = 0; i < n; i++) Dijkstra(g, i);
    printf("\tA\tB\tC\tD\t\n") ;
    for(int i=0; i<4; i++) {
        printf("%c",'A'+i);
        for(int j=0; j<4; j++) {
            printf("\t%d",dis[i][j]);
        }
        cout<<endl;
    }
    int mmin=100000,index=-1;
    for(int i=0; i<n; i++) {
        int sum=dis[i][0]+dis[i][1]+dis[i][2]+dis[i][3]+dis[0][i]+dis[1][i]+dis[2][i]+dis[3][i];
        if(sum<mmin) {
            mmin=sum;
            index=i;
        }
    }
    printf("应该建在%c上\n",'A'+index);
    cout<<endl;
    cout<<"是李鹏辉做的"<<endl;
    return 0;
}
