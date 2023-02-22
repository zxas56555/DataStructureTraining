#ifndef MGRAPH_H /*�����ظ�����ͷ�ļ�*/
#define MGRAPH_H
const int MaxSize = 10; /*ͼ����ඥ�����*/

template <class ElemType>
class MGraph{
public:
   	MGraph(ElemType a[], int n, int e); /*���캯��*/
   	void SelectAddressByFloyd(); /*����Floyd�㷨Ѱַ*/
private:
    ElemType vertex[MaxSize];          
    int arc[MaxSize][MaxSize];         
    int vertexNum, arcNum;              
};
#endif
