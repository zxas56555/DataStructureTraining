#ifndef MGRAPH_H /*�����ظ�����ͷ�ļ�*/
#define MGRAPH_H
const int MaxSize = 10; /*ͼ����ඥ�����*/
int visited[MaxSize] = {0};
/*����ͼ�����ڽӾ���洢*/
template <class ElemType>
class MGraph{
public:
   MGraph(ElemType a[], int n, int e); /*���캯������������n������e���ߵ�����ͼ*/
   ~MGraph(); /*��������Ϊ��*/
   void DFSTraverse(int v); /*�Ӷ���v��ʼ������ȱ���ͼ*/
   void BFSTraverse(int v); /*�Ӷ���v��ʼ������ȱ���ͼ*/
   void DFS(); /*������ȱ���ͼ*/
   void BFS(); /*������ȱ���ͼ*/
private:
    ElemType vertex[MaxSize]; /*���ͼ�ж��������*/
    int arc[MaxSize][MaxSize]; /*���ͼ�бߵ�����*/
    int vertexNum, arcNum; /*ͼ�Ķ������ͱ���*/
};
#endif
