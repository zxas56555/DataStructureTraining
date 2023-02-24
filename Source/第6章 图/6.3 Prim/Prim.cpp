#include <iostream>
#include <cstdio> 
#include <vector> 
#include <queue> 
#include <cstring> 
using namespace std;
const int maxn=1005;
struct Edge{
    int to,dist;
    Edge(int t,int d):to(t),dist(d){}
    bool operator<(const Edge& e)const{
        return dist>e.dist; }
};
int n,m;
bool vis[maxn];
vector<Edge> g[maxn];
priority_queue<Edge> que;
void prim(){
    memset(vis,0,sizeof(vis));
    while(que.size()) que.pop();
    for(int i=0;i<g[0].size();++i) que.push(g[0][i]);
    vis[0]=true;
    int ans=0;
    for(int cnt=1;cnt<n;++cnt){
        while(que.size() && vis[que.top().to]) que.pop();
        Edge e=que.top();
        ans+=e.dist;
        int v=e.to;
        vis[v]=true;
        for(int i=0;i<g[v].size();++i){
            if(!vis[g[v][i].to]) que.push(g[v][i]);
        }
    }
    cout<<"prim算法生成的结果为"<<ans<<endl; 
}
int main(){
	cout<<"请分别输入顶点数和边数："<<endl; 
    cin>>n>>m; 
    cout<<"请输入对应的边和权值："<<endl; 
    for(int i=0;i<n;++i) g[i].clear();
    for(int i=0;i<m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u-1].push_back(Edge(v-1,w));
        g[v-1].push_back(Edge(u-1,w));
    }
    prim();
    cout<<"是李鹏辉做的"<<endl;
    return 0;
}