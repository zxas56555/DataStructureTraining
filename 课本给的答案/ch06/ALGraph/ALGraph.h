#ifndef ALGRAPH_H /*�����ظ�����ͷ�ļ�*/
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
const int MaxSize = 10; /*ͼ����ඥ�����*/
int visited[MaxSize] = {0}; /*����ķ��ʱ�־����*/
/*����ͼ�����ڽӱ�洢*/
template <class ElemType>
class ALGraph{
public:
   ALGraph(ElemType a[], int n, int e); /*���캯������������n������e���ߵ�����ͼ*/
   ~ALGraph(); /*��������*/
   void DFSTraverse(int v); /*�Ӷ���v��ʼ������ȱ���ͼ*/
   void BFSTraverse(int v); /*�Ӷ���v��ʼ������ȱ���ͼ*/
   void DFS(); /*������ȱ���ͼ*/
   void BFS(); /*������ȱ���ͼ*/
private:
    VertexNode<ElemType> adjList[MaxSize]; /*��Ŷ���������*/
    int vertexNum, arcNum; /*ͼ�Ķ������ͱ���*/
};
#endif
