#ifndef MGRAPH_H /*避免重复引用头文件*/
#define MGRAPH_H
#define INF 32767
const int MaxSize = 10; /*图中最多顶点个数*/
/*模板类MGraph*/
template <class ElemType>
class MGraph{
public:
   MGraph(ElemType a[], int n, int e); /*构造函数*/  
   void Dijkstra(int v); /*利用Dijkstra算法求最短路径*/
private:
    ElemType vertex[MaxSize];          
    int arc[MaxSize][MaxSize];         
    int vertexNum, arcNum;              
};
#endif
