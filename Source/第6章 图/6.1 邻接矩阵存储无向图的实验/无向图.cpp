#include<bits/stdc++.h>
using namespace std;
#define  MAX 105 
template <class MGraph_entry>
class MGraph 
{
	private:
		int edg[MAX][MAX];//存边 
		int n,e;//分别为顶点数和边数 
		int visit[MAX]; 
	public:
		MGraph(); //构造函数 
		void DFS(MGraph *G,int v); 
		void BFS(MGraph *G,int v); 
};
template <class MGraph_entry>
MGraph<MGraph_entry>::MGraph(){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			edg[i][j]=0; 
		} 
	}  
	memset(visit,0,sizeof(visit)); 
	cout<<"请输入无向图的顶点数和边数："<<endl;
	cin>>n>>e;
	cout<<"输入该图的"<<e<<"条边的两个端点(1 ~ m)："<<endl;
	int x,y; 
	for(int i=0;i<e;i++){
		cin>>x>>y;
		edg[x][y]=edg[y][x]=1; 
	} 
} 
template <class MGraph_entry>
void MGraph<MGraph_entry>::DFS(MGraph *G,int v){//深度优先遍历
	if(!G->visit[v]){
		G->visit[v]=1; 
		cout<<v<<" "; 
	} 
	for(int j=1;j<=n;j++){
		if(G->edg[v][j]&&!G->visit[j]){//edg[v][j]是与v相邻的节点，visit[j]判断该节点是否被访问
			DFS(G,j); 
		} 
	} 
}
template <class MGraph_entry>
void MGraph<MGraph_entry>::BFS(MGraph *G,int v){//广度优先遍历
	memset(G->visit,0,sizeof(G->visit)); 	
	queue<MGraph_entry> q;
	cout<<v<<" ";
	G->visit[v]=1;
	q.push(v);
	int x; 
	while(!q.empty()){
		x=q.front();
		q.pop();
		for(int i=1;i<=G->n;i++){
			if(G->edg[x][i]&&!visit[i]){
				cout<<i<<" ";
				visit[i]=1;
				q.push(i); 
			} 
		} 
	}		
	memset(G->visit,0,sizeof(G->visit)); 
}
int main(){
	MGraph<int> mgraph; 
	cout<<"通过深度优先遍历以此访问的节点如下："<<endl; 
	mgraph.DFS(&mgraph,1); 
	cout<<endl<<"通过广度优先遍历以此访问的节点如下："<<endl; 
	mgraph.BFS(&mgraph,1);
	cout<<endl<<"是李鹏辉做的"<<endl; 
	return 0; 
} 