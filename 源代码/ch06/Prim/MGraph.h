#ifndef MGRAPH_H /*�����ظ�����ͷ�ļ�*/
#define MGRAPH_H
const int MaxSize = 10; /*ͼ����ඥ�����*/

/*����ͼ�����ڽӾ���洢*/
template <class ElemType>
class MGraph{
public:
   MGraph(ElemType a[], int n, int e); /*���캯������������n������e���ߵ�����ͼ*/
   void Print(); /*�������ͼ���ڽӾ���*/
   void Prim(); /*Prim�㷨*/
private:
    ElemType vertex[MaxSize]; /*���ͼ�ж��������*/
    int arc[MaxSize][MaxSize]; /*���ͼ�бߵ�����*/
    int vertexNum, arcNum; /*ͼ�Ķ������ͱ���*/
};
#endif
