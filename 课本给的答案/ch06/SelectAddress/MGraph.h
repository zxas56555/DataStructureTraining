#ifndef MGRAPH_H /*避免重复引用头文件*/
#define MGRAPH_H
const int MaxSize = 10; /*图中最多顶点个数*/

template <class ElemType>
class MGraph{
public:
   	MGraph(ElemType a[], int n, int e); /*构造函数*/
   	void SelectAddressByFloyd(); /*利用Floyd算法寻址*/
private:
    ElemType vertex[MaxSize];          
    int arc[MaxSize][MaxSize];         
    int vertexNum, arcNum;              
};
#endif
