#include <bits/stdc++.h>

using namespace std;


void Merge( int A[], int TmpA[], int L, int R, int RightEnd ){ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
    int LeftEnd, NumElements, Tmp;
    int i;
	LeftEnd = R - 1; /* 左边终点位置 */
    Tmp = L;         /* 有序序列的起始位置 */
    NumElements = RightEnd - L + 1;
	while( L <= LeftEnd && R <= RightEnd ) {
        if ( A[L] <= A[R] )
            TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
        else
            TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
    }
	while( L <= LeftEnd )
        TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
    while( R <= RightEnd )
        TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */
    for( i = 0; i < NumElements; i++, RightEnd -- )
        A[RightEnd] = TmpA[RightEnd];   /*将有序的TmpA[]复制回A[] */
}
/* length = 当前有序子列的长度*/
void Merge_pass( int A[], int TmpA[], int N, int length ){ /* 两两归并相邻有序子列 */
    int i, j;
    for ( i=0; i <= N-2*length; i += 2*length )
        Merge( A, TmpA, i, i+length, i+2*length-1 );
    if ( i+length < N ) /* 归并最后2个子列*/
        Merge( A, TmpA, i, i+length, N-1);

}
void Merge_Sort( int A[], int N ){
    int length;
    int *TmpA;
	length = 1; /* 初始化子序列长度*/
    TmpA = (int*)malloc( N * sizeof( int ) );
    if ( TmpA != NULL ) {
        while( length < N ) {
            Merge_pass( A, TmpA, N, length );
            length *= 2;
            //Merge_pass( TmpA, A, N, length );
            //length *= 2;
        }
        free( TmpA );
    }
    else printf( "空间不足" );
}
int main(){
	int i,N; 
	cout<<"请输入数据个数："; 
	cin>>N; 
	int a[N]; 
    cout<<"输入数据：";
	for(i=0;i<N;i++)
		cin>>a[i]; 
    Merge_Sort(a,N);
    cout<<"输出数据：";
    for(int i = 0;i<N;i++)
        cout<<a[i]<<" ";
    cout << endl;
	cout << "是李树臻做的" << endl; 
    return 0;
}

