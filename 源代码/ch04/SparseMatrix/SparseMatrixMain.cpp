#include <iostream>  
#define MaxSize 100
using namespace std;

/*��Ԫ��*/
template <class ElemType>
struct Triple{
	ElemType e;
	int i, j;
};

/*��Ԫ��˳���*/
template <class ElemType>
struct SMatrix{
	Triple<ElemType> data[MaxSize + 1]; /*data[0]���ò���*/
	int m, n, t; /*���������������������Ԫ����*/
};

/*��Ԫ��˳���ĳ�ʼ��*/
template <class ElemType>
void CreateSMatrix(SMatrix<ElemType> &M) {
	cout<<"������ϡ����������m��"<<endl;
	cin>>M.m;
	cout<<"������ϡ����������n��"<<endl;
	cin>>M.n;
	cout<<"������ϡ�����ķ���Ԫ�صĸ���t��"<<endl;
	cin>>M.t;
	int k;
	for(k=1; k <= M.t; k++) {
		cout<<"�������"<<k<<"������Ԫ�����ڵ��У����ڵ��У�ֵ��"<<endl;
		cin>>M.data[k].i;
		cin>>M.data[k].j;
		cin>>M.data[k].e;
	}
}

/*��ӡ��Ԫ��˳���*/
template <class ElemType>
void PrintSMatrix(SMatrix<ElemType> M) {
	cout<<"ϡ��������Ԫ��˳���Ϊ��"<<endl;
	int k;
	for(k = 1; k <= M.t; k++) {
		cout<<M.data[k].i<<" "<<M.data[k].j<<" "<<M.data[k].e<<endl;
	}
}

/*ʹ����Ԫ��˳���洢ϡ�����ʱ����ͨ��ת�÷���*/
template <class ElemType>
void TransposeSMatrix(SMatrix<ElemType> M, SMatrix<ElemType> &T) {
	/*TΪM��ת�þ���*/
	T.m = M.n;
	T.n = M.m;
	T.t = M.t;
	if(T.t) {
		int q = 1;
		/*��M���е�˳�����ת��*/
			/*��M��ÿһ�б���һ����Ԫ��˳���*/
			for(int p = 1; p <= M.t; p++)
				if(M.data[p].j == col) {
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					q++;
				}
	}
}

/*ʹ����Ԫ��˳���洢ϡ�����ʱ������ת�÷���*/
template <class ElemType>
void FastTransposeSMatrix(SMatrix<ElemType> M, SMatrix<ElemType> &T) {
	T.m = M.n;
	T.n = M.m;
	T.t = M.t;
	int cnum[MaxSize]; /*ÿһ�з���Ԫ����*/ 
	int cpot[MaxSize]; /*ÿһ�е�һ������Ԫ����Ԫ��˳����е�λ��*/
	int col, t, p, q;
	if(T.t) {
		for(col = 1; col <= M.n; col++)
			cnum[col]=0; /*ÿһ�з���Ԫ������ʼ��Ϊ0*/
		for(t = 1; t <= M.t; t++)
			cnum[M.data[t].j]++;
		cpot[1] = 1;
		/*��һ�е�һ������Ԫ��λ�õ���
        ǰһ�еĵ�һ������Ԫ��λ�ü�ǰһ�еķ���Ԫ�ĸ���*/ 
		for(col = 2; col <= M.n; col++)
			cpot[col] = cpot[col-1] + cnum[col-1];
		for(p = 1; p <= M.t; p++) {
			col = M.data[p].j;
			q = cpot[col];
			T.data[q].i = M.data[p].j;
			T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e;
			cpot[col]++;
		}
	}
}

int main() {
	SMatrix<int> M,T;
	CreateSMatrix(M);
	PrintSMatrix(M);
	/*������ͨ��ת�÷���*/
	/*TransposeSMatrix(M,T);*/
	/*���ÿ���ת�÷���*/
	FastTransposeSMatrix(M,T);
	cout<<"ת�ú��";
	PrintSMatrix(T);
	return 0;
}
