#ifndef MGRAPH_H /*避免重复引用头文件*/
#define MGRAPH_H
const int MaxSize = 10; /*图中最多顶点个数*/

/*无向图采用邻接矩阵存储*/
template <class ElemType>
class MGraph{
public:
   MGraph(ElemType a[], int n, int e); /*构造函数，建立具有n个顶点e条边的无向图*/
   void Print(); /*输出无向图的邻接矩阵*/
   void Prim(); /*Prim算法*/
private:
    ElemType vertex[MaxSize]; /*存放图中顶点的数组*/
    int arc[MaxSize][MaxSize]; /*存放图中边的数组*/
    int vertexNum, arcNum; /*图的顶点数和边数*/
};
#endif
