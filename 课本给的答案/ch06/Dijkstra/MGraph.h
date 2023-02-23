#ifndef MGRAPH_H /*�����ظ�����ͷ�ļ�*/
#define MGRAPH_H
#define INF 32767
const int MaxSize = 10; /*ͼ����ඥ�����*/
/*ģ����MGraph*/
template <class ElemType>
class MGraph{
public:
   MGraph(ElemType a[], int n, int e); /*���캯��*/  
   void Dijkstra(int v); /*����Dijkstra�㷨�����·��*/
private:
    ElemType vertex[MaxSize];          
    int arc[MaxSize][MaxSize];         
    int vertexNum, arcNum;              
};
#endif
