#include <bits/stdc++.h>

using namespace std;


void Merge( int A[], int TmpA[], int L, int R, int RightEnd ){ /* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ���������� */
    int LeftEnd, NumElements, Tmp;
    int i;
	LeftEnd = R - 1; /* ����յ�λ�� */
    Tmp = L;         /* �������е���ʼλ�� */
    NumElements = RightEnd - L + 1;
	while( L <= LeftEnd && R <= RightEnd ) {
        if ( A[L] <= A[R] )
            TmpA[Tmp++] = A[L++]; /* �����Ԫ�ظ��Ƶ�TmpA */
        else
            TmpA[Tmp++] = A[R++]; /* ���ұ�Ԫ�ظ��Ƶ�TmpA */
    }
	while( L <= LeftEnd )
        TmpA[Tmp++] = A[L++]; /* ֱ�Ӹ������ʣ�µ� */
    while( R <= RightEnd )
        TmpA[Tmp++] = A[R++]; /* ֱ�Ӹ����ұ�ʣ�µ� */
    for( i = 0; i < NumElements; i++, RightEnd -- )
        A[RightEnd] = TmpA[RightEnd];   /*�������TmpA[]���ƻ�A[] */
}
/* length = ��ǰ�������еĳ���*/
void Merge_pass( int A[], int TmpA[], int N, int length ){ /* �����鲢������������ */
    int i, j;
    for ( i=0; i <= N-2*length; i += 2*length )
        Merge( A, TmpA, i, i+length, i+2*length-1 );
    if ( i+length < N ) /* �鲢���2������*/
        Merge( A, TmpA, i, i+length, N-1);

}
void Merge_Sort( int A[], int N ){
    int length;
    int *TmpA;
	length = 1; /* ��ʼ�������г���*/
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
    else printf( "�ռ䲻��" );
}
int main(){
	int i,N; 
	cout<<"���������ݸ�����"; 
	cin>>N; 
	int a[N]; 
    cout<<"�������ݣ�";
	for(i=0;i<N;i++)
		cin>>a[i]; 
    Merge_Sort(a,N);
    cout<<"������ݣ�";
    for(int i = 0;i<N;i++)
        cout<<a[i]<<" ";
    cout << endl;
	cout << "������������" << endl; 
    return 0;
}

