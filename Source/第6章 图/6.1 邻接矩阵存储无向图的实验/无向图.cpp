#include<bits/stdc++.h>
using namespace std;
#define  MAX 105 
template <class MGraph_entry>
class MGraph 
{
	private:
		int edg[MAX][MAX];//��� 
		int n,e;//�ֱ�Ϊ�������ͱ��� 
		int visit[MAX]; 
	public:
		MGraph(); //���캯�� 
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
	cout<<"����������ͼ�Ķ������ͱ�����"<<endl;
	cin>>n>>e;
	cout<<"�����ͼ��"<<e<<"���ߵ������˵�(1 ~ m)��"<<endl;
	int x,y; 
	for(int i=0;i<e;i++){
		cin>>x>>y;
		edg[x][y]=edg[y][x]=1; 
	} 
} 
template <class MGraph_entry>
void MGraph<MGraph_entry>::DFS(MGraph *G,int v){//������ȱ���
	if(!G->visit[v]){
		G->visit[v]=1; 
		cout<<v<<" "; 
	} 
	for(int j=1;j<=n;j++){
		if(G->edg[v][j]&&!G->visit[j]){//edg[v][j]����v���ڵĽڵ㣬visit[j]�жϸýڵ��Ƿ񱻷���
			DFS(G,j); 
		} 
	} 
}
template <class MGraph_entry>
void MGraph<MGraph_entry>::BFS(MGraph *G,int v){//������ȱ���
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
	cout<<"ͨ��������ȱ����Դ˷��ʵĽڵ����£�"<<endl; 
	mgraph.DFS(&mgraph,1); 
	cout<<endl<<"ͨ��������ȱ����Դ˷��ʵĽڵ����£�"<<endl; 
	mgraph.BFS(&mgraph,1);
	cout<<endl<<"������������"<<endl; 
	return 0; 
} 