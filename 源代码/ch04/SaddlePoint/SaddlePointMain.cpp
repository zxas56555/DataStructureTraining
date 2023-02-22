#include <iostream>
using namespace std;
#define MaxSize 100
/*初始化矩阵*/
void InitMatrix(int a[][MaxSize], int m, int n) {
    for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin>>a[i][j];
        }
	}
}
/*求矩阵的马鞍点并输出*/
void GetSaddlePoint(int a[][MaxSize], int m, int n) {
	/*flag用于标识矩阵是否存在马鞍点*/
	/*min用于记录每一行的最小元素，每一行可能有多个最小元素*/
	int i, j, k, min, flag; 
	for(i = 0; i < m; i++) {
		min = a[i][0];
        /*找出i行中的最小值*/
        for(j = 0; j < n; j++)
			if(a[i][j] < min) {
				min = a[i][j];
            }
        /*判断min是不是所在列的最大值*/
        for(j = 0; j < n; j++) {   
			if(a[i][j] == min) { /*找出i行中所有最小值*/
				for(k = 0; k < m; k++) /*对所有min进行列比较*/
					if(a[k][j] > min)  
						break;
                    if(k == m) { /*min为马鞍点*/
                        cout<<"该矩阵的马鞍点是：第"<<i<<"行，第"<<j<<"列，"<<a[i][j]<<endl;
                        flag = 1;
					}
			}
		}
	}
	if(flag == 0)
		cout<<"该矩阵没有马鞍点!"<<endl;
}
int main() {
    int a[MaxSize][MaxSize];
    int m, n;
    cout<<"请输入矩阵的行数："; /*输入矩阵的行数*/
    cin>>m;          
    cout<<"请输入矩阵的列数："; /*输入矩阵的列数*/
    cin>>n;
    cout<<"请输入矩阵："<<endl; 
    InitMatrix(a, m, n);
    GetSaddlePoint(a, m, n); 
	return 0;
}
