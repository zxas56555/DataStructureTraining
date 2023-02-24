#include <iostream>
#include <stack>
using namespace std;
#define maxnum 20

struct node { //�߱�ڵ�Ķ���
    int vex;
    node* next; //ָ����һ���߱�ڵ�
};
struct vernode {
    char vex; //��Ŷ�����Ϣ
    node* first;//ָ���һ���߱�ڵ�
    int indegree;
};
struct Graph {
    vernode v[maxnum];
    int vnums,enums;
};
void CreateGraph(Graph &g,int n,int e) { //��������ͼ���ڽӱ�
    int i,j,k;
    g.vnums=n;
    g.enums=e;
    cout<<"�������붥��ı�ţ�"<<endl;
    for(i=1; i<=n; i++) {
        cin>>g.v[i].vex;
        g.v[i].first=NULL; //��ʼ��Ϊ��
    }
    cout<<"��������ߵ���ʼ�����ֹ��:"<<endl;
    for(k=1; k<=e; k++) {
        node *p;
        cin>>i>>j;
        p=new node();
        p->vex=j;
        p->next=g.v[i].first;
        g.v[i].first=p; //ͷ�巨
    }
}
void TopoSort(Graph &g) {
    std::stack<int> s;
    node *p;
    int counts=0;
    int i,j;
    for(i=1; i<=g.vnums; i++)
        g.v[i].indegree=0; //��ʼ�����Ϊ0
    for(i=1; i<=g.vnums; i++) { //���������������
        p=g.v[i].first;
        while(p) {
            g.v[p->vex].indegree++; //�������
            p = p->next;
        }
    }
    for(i=1; i<=g.vnums; i++)
        if(g.v[i].indegree==0)
            s.push(i); //����Ϊ 0 �Ķ�����ջ,�����ջ�������Ϊ 0 �Ķ����������λ��
    cout<<"��������Ľ����"<<endl;
    while(!s.empty()) {
        j=s.top();
        s.pop(); //��ջ
        cout<<g.v[j].vex<<" "; //��ջ����Ԫ�س�ջ�����
        counts++;
        p=g.v[j].first; //��pָ�����Ϊ0 �ĵ�һ���ڵ�
        while(p) {
            g.v[p->vex].indegree--;
            if(g.v[p->vex].indegree==0)
                s.push(p->vex);
            p=p->next;
        }
    }
    if(counts<g.vnums)
        cout<<"ͼ���л�"<<endl;
}
int main() {
    Graph g;
    int n,e;
    cout<<"���붥������ͱ���: "<<endl;
    cin>>n>>e;
    CreateGraph(g,n,e);
    TopoSort(g);
    cout<<endl;
    cout<<"������������"<<endl;
    return 0;
}
