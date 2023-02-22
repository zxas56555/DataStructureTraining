#ifndef ALGRAPH_H /*�����ظ�����ͷ�ļ�*/ 
#define ALGRAPH_H
const int MaxSize = 10; /*����ͼ����󶥵���*/
/*����߱���*/
struct ArcNode{
	int adjvex; /*�ߵ���һ�������ڶ�����е��±�*/
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
	void TopoSort(); /*��������*/
private:
   VertexNode<ElemType> adjlist[MaxSize]; /*��Ŷ���������*/
   int vertexNum, arcNum; /*ͼ�Ķ������ͱ���*/
};
#endif
