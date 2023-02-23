#ifndef MGRAPH_H /*避免重复引用头文件*/
#define MGRAPH_H

const int MaxSize = 10; /*图中最多顶点个数*/
const int MaxWeight = 1000; /*图中边权值的最大值*/
int visited[MaxSize] = {0}; /*各顶点的访问标志*/
 
/*无向图采用邻接矩阵存储*/
template <class ElemType>
class MGraph{
public:
	MGraph(ElemType a[], int n, int e); /*构造函数，建立具有n个顶点e条边的无向图*/
   	int Min(int a[], int n); /*求依附于某个没有访问过的顶点的权值最小的边*/
    void TSP(int v); /*使用贪心算法求解从顶点v出发，各个顶点都遍历一遍，回到顶点v的最短路径*/
private:
    ElemType vertex[MaxSize]; /*图的顶点*/
    int arc[MaxSize][MaxSize]; /*图的邻接矩阵*/
    int vertexNum, arcNum; /*图的顶点数和边数*/
};
#endif
