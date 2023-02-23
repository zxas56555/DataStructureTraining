#ifndef ALGRAPH_H /*避免重复引用头文件*/ 
#define ALGRAPH_H
const int MaxSize = 10; /*有向图的最大顶点数*/
/*定义边表结点*/
struct ArcNode{
	int adjvex; /*边的另一个顶点在顶点表中的下标*/
    ArcNode *next;
};
/*定义顶点表结点*/
template <class ElemType>
struct VertexNode {
	int in; /*顶点入度*/
	ElemType vertex;
    ArcNode *firstEdge;
};
/*有向图使用邻接表存储的类*/
template <class ElemType>
class ALGraph{
public:
	ALGraph(ElemType a[], int n, int e); /*构造函数*/
	void TopoSort(); /*拓扑排序*/
private:
   VertexNode<ElemType> adjlist[MaxSize]; /*存放顶点表的数组*/
   int vertexNum, arcNum; /*图的顶点数和边数*/
};
#endif
