#ifndef ALGRAPH_H /*避免重复引用头文件*/
#define ALGRAPH_H
/*状态类*/
class Status{
public:
	/*构造函数*/
	Status(int f, int w, int s, int c) {
		farmer = f;
		wolf = w;
		sheep = s;
		cabbage = c;
	}
	/*输出状态*/
	void PrintStatus() {
		cout<<"("<<farmer<<","<<wolf<<","<<sheep<<","<<cabbage<<")"<<endl;
	}
private:
	int farmer;
	int wolf;
	int sheep;
	int cabbage;
};
/*农夫过河问题的十个有效状态*/
Status s[] = {Status(0,0,0,0), Status(0,0,0,1), Status(0,0,1,0), Status(0,1,0,0), Status(0,1,0,1), Status(1,0,1,0), Status(1,0,1,1), Status(1,1,0,1), Status(1,1,1,0), Status(1,1,1,1)};

/*邻接表的边结点*/ 
struct ArcNode{
	int adjvex;
	ArcNode *next;
};
/*顶点结点*/
template <class ElemType>
struct VertexNode{
	ElemType vertex;
	ArcNode *firstedge;
};
const int MaxSize = 10; /*图中最多顶点个数*/
int visited[MaxSize*2] = {0};
/*有向图采用邻接表存储*/
template <class ElemType>
class ALGraph{
public:
	ALGraph(ElemType a[], int n, int e); /*构造函数，建立具有n个顶点e条边的有向图*/
	~ALGraph(); /*析构函数*/
	void PrintALGraph(); /*输出邻接表*/
	void Find(int x, int l, int visited[], int path[], int d); /*寻找顶点x到顶点l的所有简单路径并输出*/
private:
    VertexNode<ElemType> adjlist[MaxSize]; /*存放顶点表的数组*/
    int vertexNum, arcNum; /*图的顶点数和边数*/
};
#endif
