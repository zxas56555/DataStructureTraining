#ifndef SEQLIST_H /*�����ظ�����ͷ�ļ�*/
#define SEQLIST_H
const int MaxSize = 100; /*˳�����������Ϊ100*/
template <class ElemType> /*����ģ����SeqList*/
class SeqList{
public:
	SeqList(); /*������˳���*/
	SeqList(ElemType a[], int n); /*����һ������Ϊn��˳���*/
	~SeqList(); /*��������*/
	int Length(); /*����˳���ı�*/
	ElemType Get(int i); /*��λ����*/
	ElemType Delete(int i); /*ɾ������*/
	void PrintList(); /*��������*/
private:
	ElemType data[MaxSize]; /*�������Ԫ�ص�����*/
	int length; /*˳���ĳ���*/
};
#endif
