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
//��ʼ��n��Ԫ��
void init(int n)
{
    for(int i = 0; i < n; i++)
    {
        par[i] = i;
        high[i] = 0;
    }
}
//��ѯ���ĸ�
int Find(int x)
{
    return par[x] == x ? x : par[x] = Find(par[x]);//·��ѹ��
}
void unite(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y)return;
    if(high[x] < high[y])par[x] = y;//y�ĸ߶ȸߣ���x�ĸ��ڵ����ó�y
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
void kruskal(int n, int m)//����n������m
{
    int sum_mst = 0;//mstȨֵ
    int num= 0;//�Ѿ�ѡ��ıߵı���
    sort(a, a + m);//�߽�������
    init(n);//��ʼ�����鼯
    cout<<"ѡȡ�ı߷ֱ�Ϊ��"<<endl; 
    for(int i = 0; i < m; i++)
    {
        int u = a[i].u;
        int v = a[i].v;
        if(Find(u - 1) != Find(v - 1))//ͼ�ʼ���±���1�����鼯��0
        {
            printf("%d %d %d\n", u, v, a[i].w);
            sum_mst += a[i].w;
            num++;
            unite(u - 1, v - 1);
        }
        if(num >= n - 1)break;
    }
    cout<<"kruskal�㷨���ɵĽ��Ϊ"<<sum_mst<<endl; 
}
int main()
{
	cout<<"��ֱ����붥�����ͱ�����"<<endl; 
    cin >> n >> m;
    cout<<"�������Ӧ�ıߺ�Ȩֵ��"<<endl; 
    for(int i = 0; i < m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    kruskal(n, m);
    cout<<"������������"<<endl;
    return 0;
}