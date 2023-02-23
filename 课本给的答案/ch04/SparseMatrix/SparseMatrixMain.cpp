#include <iostream>
#define MaxSize 100
using namespace std;

/*三元组*/
template <class ElemType>
struct Triple
{
	ElemType e;
	int i, j;
};

/*三元组顺序表*/
template <class ElemType>
struct SMatrix
{
	Triple<ElemType> data[MaxSize + 1]; /*data[0]空置不用*/
	int m, n, t;						/*矩阵的行数，列数，非零元个数*/
};

/*三元组顺序表的初始化*/
template <class ElemType>
void CreateSMatrix(SMatrix<ElemType> &M)
{
	cout << "请输入稀疏矩阵的行数m：" << endl;
	cin >> M.m;
	cout << "请输入稀疏矩阵的列数n：" << endl;
	cin >> M.n;
	cout << "请输入稀疏矩阵的非零元素的个数t：" << endl;
	cin >> M.t;
	int k;
	for (k = 1; k <= M.t; k++)
	{
		cout << "请输入第" << k << "个非零元素所在的行，所在的列，值：" << endl;
		cin >> M.data[k].i;
		cin >> M.data[k].j;
		cin >> M.data[k].e;
	}
}

/*打印三元组顺序表*/
template <class ElemType>
void PrintSMatrix(SMatrix<ElemType> M)
{
	cout << "稀疏矩阵的三元组顺序表为：" << endl;
	int k;
	for (k = 1; k <= M.t; k++)
	{
		cout << M.data[k].i << " " << M.data[k].j << " " << M.data[k].e << endl;
	}
}

/*使用三元组顺序表存储稀疏矩阵时，普通的转置方法*/
template <class ElemType>
void TransposeSMatrix(SMatrix<ElemType> M, SMatrix<ElemType> &T)
{
	/*T为M的转置矩阵*/
	T.m = M.n;
	T.n = M.m;
	T.t = M.t;
	if (T.t)
	{
		int q = 1;
		/*按M的列的顺序进行转置*/
		for (int col = 1; col <= M.n; col++)
			/*对M的每一列遍历一遍三元组顺序表*/
			for (int p = 1; p <= M.t; p++)
				if (M.data[p].j == col)
				{
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					q++;
				}
	}
}

/*使用三元组顺序表存储稀疏矩阵时，快速转置方法*/
template <class ElemType>
void FastTransposeSMatrix(SMatrix<ElemType> M, SMatrix<ElemType> &T)
{
	T.m = M.n;
	T.n = M.m;
	T.t = M.t;
	int cnum[MaxSize]; /*每一列非零元个数*/
	int cpot[MaxSize]; /*每一列第一个非零元在三元组顺序表中的位置*/
	int col, t, p, q;
	if (T.t)
	{
		for (col = 1; col <= M.n; col++)
			cnum[col] = 0; /*每一列非零元个数初始化为0*/
		for (t = 1; t <= M.t; t++)
			cnum[M.data[t].j]++;
		cpot[1] = 1;
		/*后一列第一个非零元的位置等于
		前一列的第一个非零元的位置加前一列的非零元的个数*/
		for (col = 2; col <= M.n; col++)
			cpot[col] = cpot[col - 1] + cnum[col - 1];
		for (p = 1; p <= M.t; p++)
		{
			col = M.data[p].j;
			q = cpot[col];
			T.data[q].i = M.data[p].j;
			T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e;
			cpot[col]++;
		}
	}
}

int main()
{
	SMatrix<int> M, T;
	CreateSMatrix(M);
	PrintSMatrix(M);
	/*调用普通的转置方法*/
	/*TransposeSMatrix(M,T);*/
	/*调用快速转置方法*/
	FastTransposeSMatrix(M, T);
	cout << "转置后的";
	PrintSMatrix(T);
	return 0;
}
