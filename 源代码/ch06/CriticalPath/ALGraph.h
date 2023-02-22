#ifndef ALGRAPH_H /*�����ظ�����ͷ�ļ�*/ 
#define ALGRAPH_H
const int MaxSize = 10; /*����ͼ����󶥵���*/
const int EdgeMaxSize = 50; /*����ͼ��������*/
const int INF = 32767; /*������Ȩֵ*/ 
/*����߱���*/
struct ArcNode{
	int adjvex; /*�ߵ���һ�������ڶ�����е��±�*/
	int weight; /*�ߵ�Ȩֵ*/
    ArcNode *next;
};
/*���嶥�����*/
template <class ElemType>
struct VertexNode {
	int in; /*�������*/
	ElemType vertex;
    ArcNode *firstEdge;
};
/*����ͼʹ���ڽӱ�洢����*/
template <class ElemType>
class ALGraph{
public:
	ALGraph(ElemType a[], int n, int e); /*���캯��*/
	int TopoSort(); /*��������*/
	int getFirstNeighbor(int i); /*�󶥵�i�ĵ�һ���ڽӵ�*/
	int getNextNeighbor(int i, int j); /*�󶥵�i����ڶ���j����һ���ڽӵ�*/
	int getWeight(int i,int j); /*���<vi,vj>��Ȩֵ*/
	void GetCriticalPath(); /*���ؼ�·��*/
private:
   VertexNode<ElemType> adjlist[MaxSize]; /*��Ŷ���������*/
   int vertexNum, arcNum; /*ͼ�Ķ������ͱ���*/
};
#endif
