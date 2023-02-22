#ifndef EDGEGRAPH_H /*�����ظ�����ͷ�ļ�*/
#define EDGEGRAPH_H
const int MaxSize = 10; /*ͼ����ඥ�����*/
const int MaxEdge = 100; /*ͼ��������*/

struct EdgeType{
	int from, to; /*�߶�Ӧ����������*/
	int weight; /*���ϵ�Ȩֵ*/
};

/*������ͨ�����ñ߼�����洢*/
template <class ElemType>
class EdgeGraph{
public:
   EdgeGraph(ElemType a[], int n, int e); /*���캯��*/
   void Sort(); /*��������ͨ���ı߼������С��������*/
   void Print(); /*���������ͨ���ı߼�����*/
   void Kruscal(); /*Kruscal�㷨*/
private:
    ElemType vertex[MaxSize]; /*���ͼ�ж��������*/
    EdgeType edge[MaxEdge]; /*���ͼ�бߵ�����*/
    int vertexNum, edgeNum; /*ͼ�Ķ������ͱ���*/
};
#endif
