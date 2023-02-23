#include <iostream>
#include "ALGraph.h" /*引入头文件*/
using namespace std;

template <class ElemType>
ALGraph<ElemType>::ALGraph(ElemType a[], int n, int e) {
	ArcNode *s;
	int i, j, k;
	vertexNum = n;
	arcNum = e;
	/*输入顶点信息，初始化顶点表*/
	for(i = 0; i < vertexNum; i++) {
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = NULL;
	}
    /*依次输入每一条边*/
	for (k = 0; k < arcNum; k++) { 
		cout<<"请输入第"<<k + 1<<"条边的两个顶点的序号：";
		cin>>i>>j;
		/*生成新的边表结点s*/
		s = new ArcNode; 
		s->adjvex = j;
		/*使用头插法将s插入到边表中*/
		s->next = adjlist[i].firstedge;
		adjlist[i].firstedge = s;
	}
}

/*析构函数，释放邻接表中边表的所有结点*/
template <class ElemType>
ALGraph<ElemType>::~ALGraph() {
	ArcNode *p;
	for(int i = 0; i < vertexNum; i++) {
		p = adjlist[i].firstedge;
		while(p != NULL) {
			adjlist[i].firstedge = p->next;
			delete p;
			p = adjlist[i].firstedge;
		}
	}
}

/*输出邻接表*/
template <class ElemType>
void ALGraph<ElemType>::PrintALGraph() {
	cout<<"邻接表为："<<endl;
	int i;
	ArcNode *p;
	for(i = 0; i < vertexNum; i++) {
		cout<<adjlist[i].vertex<<" ";
		p = adjlist[i].firstedge;
		while(p != NULL) {
			cout<<p->adjvex<<" ";
			p = p->next;
		}
		cout<<endl;
	}
}

/*起始状态*/ 
static int s1 = 0;
template <class ElemType>
void ALGraph<ElemType>::Find(int x, int l, int visited[], int path[], int d) {
	int i, node;
	ArcNode *r;
	visited[x] = 1;
	d++;
	path[d] = x;
	/*找到终点，输出路径*/
	if(x == l) {
		s1++;
		if(s1 == 1)
			cout<<"顶点"<<path[0]<<"到顶点"<<l<<"的路径为："<<endl;
		for(i = 0; i <= d; i++) {
			//cout<<path[i]<<" ";
			cout<<adjlist[path[i]].vertex<<" ";
			s[path[i]].PrintStatus();
		}
		cout<<endl;
	}
	r = adjlist[x].firstedge;
	while(r != NULL) {
		node = r->adjvex;
		/*递归寻找路径*/
		if(visited[node] == 0)
			Find(node, l, visited, path, d);
		r = r->next;
	} 
	visited[x] = 0;
	d--;
}

