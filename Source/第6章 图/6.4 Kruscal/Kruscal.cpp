#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
const int INF = 1 << 30;
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int T, n, m, x;
struct edge
{
    int u, v, w;
    bool operator <(const edge& a)const
    {
        return w < a.w;
    }
};
edge a[maxn];
int par[600], high[600];
//初始化n个元素
void init(int n)
{
    for(int i = 0; i < n; i++)
    {
        par[i] = i;
        high[i] = 0;
    }
}
//查询树的根
int Find(int x)
{
    return par[x] == x ? x : par[x] = Find(par[x]);//路径压缩
}
void unite(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y)return;
    if(high[x] < high[y])par[x] = y;//y的高度高，将x的父节点设置成y
    else
    {
        par[y] = x;
        if(high[x] == high[y])high[x]++;
    }
}
bool same(int x, int y)
{
    return Find(x) == Find(y);
}
void kruskal(int n, int m)//点数n，边数m
{
    int sum_mst = 0;//mst权值
    int num= 0;//已经选择的边的边数
    sort(a, a + m);//边进行排序
    init(n);//初始化并查集
    cout<<"选取的边分别为："<<endl; 
    for(int i = 0; i < m; i++)
    {
        int u = a[i].u;
        int v = a[i].v;
        if(Find(u - 1) != Find(v - 1))//图最开始的下标是1，并查集是0
        {
            printf("%d %d %d\n", u, v, a[i].w);
            sum_mst += a[i].w;
            num++;
            unite(u - 1, v - 1);
        }
        if(num >= n - 1)break;
    }
    cout<<"kruskal算法生成的结果为"<<sum_mst<<endl; 
}
int main()
{
	cout<<"请分别输入顶点数和边数："<<endl; 
    cin >> n >> m;
    cout<<"请输入对应的边和权值："<<endl; 
    for(int i = 0; i < m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    kruskal(n, m);
    cout<<"是李鹏辉做的"<<endl;
    return 0;
}