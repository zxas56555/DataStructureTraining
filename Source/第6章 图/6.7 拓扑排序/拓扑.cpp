#include <iostream>
#include <stack>
using namespace std;
#define maxnum 20

struct node { //边表节点的定义
    int vex;
    node* next; //指向下一个边表节点
};
struct vernode {
    char vex; //存放顶点信息
    node* first;//指向第一个边表节点
    int indegree;
};
struct Graph {
    vernode v[maxnum];
    int vnums,enums;
};
void CreateGraph(Graph &g,int n,int e) { //创建有向图的邻接表
    int i,j,k;
    g.vnums=n;
    g.enums=e;
    cout<<"依次输入顶点的编号："<<endl;
    for(i=1; i<=n; i++) {
        cin>>g.v[i].vex;
        g.v[i].first=NULL; //初始化为空
    }
    cout<<"依次输入边的起始点和终止点:"<<endl;
    for(k=1; k<=e; k++) {
        node *p;
        cin>>i>>j;
        p=new node();
        p->vex=j;
        p->next=g.v[i].first;
        g.v[i].first=p; //头插法
    }
}
void TopoSort(Graph &g) {
    std::stack<int> s;
    node *p;
    int counts=0;
    int i,j;
    for(i=1; i<=g.vnums; i++)
        g.v[i].indegree=0; //初始化入度为0
    for(i=1; i<=g.vnums; i++) { //计算各个顶点的入度
        p=g.v[i].first;
        while(p) {
            g.v[p->vex].indegree++; //计算入度
            p = p->next;
        }
    }
    for(i=1; i<=g.vnums; i++)
        if(g.v[i].indegree==0)
            s.push(i); //将度为 0 的顶点入栈,这里进栈的是入度为 0 的顶点在数组的位置
    cout<<"拓扑排序的结果："<<endl;
    while(!s.empty()) {
        j=s.top();
        s.pop(); //出栈
        cout<<g.v[j].vex<<" "; //将栈顶的元素出栈且输出
        counts++;
        p=g.v[j].first; //让p指向入度为0 的第一个节点
        while(p) {
            g.v[p->vex].indegree--;
            if(g.v[p->vex].indegree==0)
                s.push(p->vex);
            p=p->next;
        }
    }
    if(counts<g.vnums)
        cout<<"图中有环"<<endl;
}
int main() {
    Graph g;
    int n,e;
    cout<<"输入顶点个数和边数: "<<endl;
    cin>>n>>e;
    CreateGraph(g,n,e);
    TopoSort(g);
    cout<<endl;
    cout<<"是李鹏辉做的"<<endl;
    return 0;
}
