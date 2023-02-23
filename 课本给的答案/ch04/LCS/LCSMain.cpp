#include <iostream>
#include <string.h>
#define MaxSize 50
using namespace std;
/*������������еĳ���*/
/*xΪ����Ϊm���ַ�����yΪ����Ϊn���ַ���*/
/*c[i][j]Ϊx[0...i-1]��y[0...j-1]������������еĳ���*/
void LCSLength(char *x, char *y, int m, int n, int c[][MaxSize], int b[][MaxSize]) {
    int i, j;
    /*c�ĵ�0����Ϊ0*/ 
    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    /*c�ĵ�0����Ϊ0*/
    for(j = 1; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
        	/*�ַ���ȣ�������Ϸ�*/
			/*��ָ�����Ϸ��ļ�ͷ���ñ�ʾ�������1����*/ 
            if(x[i-1] == y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
			}
			/*�ַ�����ȣ�c[i][j]=c[i-1][j]�������*/
			/*��ָ���󷽵ļ�ͷ���ñ�ʾ�������3����*/ 
            else if(c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 3;
            }
            /*�ַ�����ȣ�c[i][j]=c[i][j-1]������Ϸ�*/
			/*��ָ���Ϸ��ļ�ͷ���ñ�ʾ�������2����*/  
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = 2;
            }
        }
    }
}

/*��ӡ��������������*/ 
void PrintLCS(int b[][MaxSize], char *x, int i, int j) {
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 1) {
        PrintLCS(b, x, i-1, j-1);
        cout<<x[i-1]; 
    }
    else if(b[i][j] == 3)
        PrintLCS(b, x, i-1, j);
    else
        PrintLCS(b, x, i, j-1);
}

int main() {
    char X[MaxSize] = {"ABCBDAB"};
    char Y[MaxSize] = {"BDCABA"};
    int b[MaxSize][MaxSize];
    int c[MaxSize][MaxSize];
    int m,n;
    m = strlen(X);
    n = strlen(Y);
    LCSLength(X, Y, m, n, c, b);
    cout<<"�����ַ���Ϊ��"<<endl;
    cout<<X<<endl;
    cout<<Y<<endl;
    cout<<"�����������Ϊ��"; 
    PrintLCS(b, X, m, n);
    return 0;
}
