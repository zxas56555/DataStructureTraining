#ifndef EDGEGRAPH_H /*避免重复引用头文件*/
#define EDGEGRAPH_H
const int MaxSize = 10; /*图中最多顶点个数*/
const int MaxEdge = 100; /*图中最多边数*/

struct EdgeType{
	int from, to; /*边对应的两个顶点*/
	int weight; /*边上的权值*/
};

/*无向连通网采用边集数组存储*/
template <class ElemType>
class EdgeGraph{
public:
   EdgeGraph(ElemType a[], int n, int e); /*构造函数*/
   void Sort(); /*给无向连通网的边集数组从小到大排序*/
   void Print(); /*输出无向连通网的边集数组*/
   void Kruscal(); /*Kruscal算法*/
private:
    ElemType vertex[MaxSize]; /*存放图中顶点的数组*/
    EdgeType edge[MaxEdge]; /*存放图中边的数组*/
    int vertexNum, edgeNum; /*图的顶点数和边数*/
};
#endif
