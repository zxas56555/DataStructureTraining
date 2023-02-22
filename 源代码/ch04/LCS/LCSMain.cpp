#include <iostream>
#include <string.h>
#define MaxSize 50
using namespace std;
/*求最长公共子序列的长度*/
/*x为长度为m的字符串，y为长度为n的字符串*/
/*c[i][j]为x[0...i-1]和y[0...j-1]的最长公共子序列的长度*/
void LCSLength(char *x, char *y, int m, int n, int c[][MaxSize], int b[][MaxSize]) {
    int i, j;
    /*c的第0列置为0*/ 
    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    /*c的第0行置为0*/
    for(j = 1; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
        	/*字符相等，标记左上方*/
			/*因指向左上方的箭头不好表示，因此用1代替*/ 
            if(x[i-1] == y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
			}
			/*字符不相等，c[i][j]=c[i-1][j]，标记左方*/
			/*因指向左方的箭头不好表示，因此用3代替*/ 
            else if(c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 3;
            }
            /*字符不相等，c[i][j]=c[i][j-1]，标记上方*/
			/*因指向上方的箭头不好表示，因此用2代替*/  
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = 2;
            }
        }
    }
}

/*打印输出最长公共子序列*/ 
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
    cout<<"两个字符串为："<<endl;
    cout<<X<<endl;
    cout<<Y<<endl;
    cout<<"最长公共子序列为："; 
    PrintLCS(b, X, m, n);
    return 0;
}
