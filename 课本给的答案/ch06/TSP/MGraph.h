#ifndef MGRAPH_H /*�����ظ�����ͷ�ļ�*/
#define MGRAPH_H

const int MaxSize = 10; /*ͼ����ඥ�����*/
const int MaxWeight = 1000; /*ͼ�б�Ȩֵ�����ֵ*/
int visited[MaxSize] = {0}; /*������ķ��ʱ�־*/
 
/*����ͼ�����ڽӾ���洢*/
template <class ElemType>
class MGraph{
public:
	MGraph(ElemType a[], int n, int e); /*���캯������������n������e���ߵ�����ͼ*/
   	int Min(int a[], int n); /*��������ĳ��û�з��ʹ��Ķ����Ȩֵ��С�ı�*/
    void TSP(int v); /*ʹ��̰���㷨���Ӷ���v�������������㶼����һ�飬�ص�����v�����·��*/
private:
    ElemType vertex[MaxSize]; /*ͼ�Ķ���*/
    int arc[MaxSize][MaxSize]; /*ͼ���ڽӾ���*/
    int vertexNum, arcNum; /*ͼ�Ķ������ͱ���*/
};
#endif
