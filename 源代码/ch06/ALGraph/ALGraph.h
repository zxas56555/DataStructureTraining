#ifndef ALGRAPH_H /*避免重复引用头文件*/
#define ALGRAPH_H
struct ArcNode{
	int adjvex;
	ArcNode *next;
};
template <class ElemType>
struct VertexNode{
	ElemType vertex;
	ArcNode *firstEdge;
};
const int MaxSize = 10; /*图中最多顶点个数*/
int visited[MaxSize] = {0}; /*顶点的访问标志数组*/
/*有向图采用邻接表存储*/
template <class ElemType>
class ALGraph{
public:
   ALGraph(ElemType a[], int n, int e); /*构造函数，建立具有n个顶点e条边的有向图*/
   ~ALGraph(); /*析构函数*/
   void DFSTraverse(int v); /*从顶点v开始深度优先遍历图*/
   void BFSTraverse(int v); /*从顶点v开始广度优先遍历图*/
   void DFS(); /*深度优先遍历图*/
   void BFS(); /*广度优先遍历图*/
private:
    VertexNode<ElemType> adjList[MaxSize]; /*存放顶点表的数组*/
    int vertexNum, arcNum; /*图的顶点数和边数*/
};
#endif
