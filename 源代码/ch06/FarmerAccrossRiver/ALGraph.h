#ifndef ALGRAPH_H /*�����ظ�����ͷ�ļ�*/
#define ALGRAPH_H
/*״̬��*/
class Status{
public:
	/*���캯��*/
	Status(int f, int w, int s, int c) {
		farmer = f;
		wolf = w;
		sheep = s;
		cabbage = c;
	}
	/*���״̬*/
	void PrintStatus() {
		cout<<"("<<farmer<<","<<wolf<<","<<sheep<<","<<cabbage<<")"<<endl;
	}
private:
	int farmer;
	int wolf;
	int sheep;
	int cabbage;
};
/*ũ����������ʮ����Ч״̬*/
Status s[] = {Status(0,0,0,0), Status(0,0,0,1), Status(0,0,1,0), Status(0,1,0,0), Status(0,1,0,1), Status(1,0,1,0), Status(1,0,1,1), Status(1,1,0,1), Status(1,1,1,0), Status(1,1,1,1)};

/*�ڽӱ�ı߽��*/ 
struct ArcNode{
	int adjvex;
	ArcNode *next;
};
/*������*/
template <class ElemType>
struct VertexNode{
	ElemType vertex;
	ArcNode *firstedge;
};
const int MaxSize = 10; /*ͼ����ඥ�����*/
int visited[MaxSize*2] = {0};
/*����ͼ�����ڽӱ�洢*/
template <class ElemType>
class ALGraph{
public:
	ALGraph(ElemType a[], int n, int e); /*���캯������������n������e���ߵ�����ͼ*/
	~ALGraph(); /*��������*/
	void PrintALGraph(); /*����ڽӱ�*/
	void Find(int x, int l, int visited[], int path[], int d); /*Ѱ�Ҷ���x������l�����м�·�������*/
private:
    VertexNode<ElemType> adjlist[MaxSize]; /*��Ŷ���������*/
    int vertexNum, arcNum; /*ͼ�Ķ������ͱ���*/
};
#endif
