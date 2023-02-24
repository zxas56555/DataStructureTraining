#include <iostream>
using namespace std;
#include<bits/stdc++.h>
/*路线条数*/
const int n = 13;
/*路线*/
const string path[n] = {"AB", "AC", "AD", "BA", "BC", "BD", "DA", "DB", "DC", "EA", "EB", "EC", "ED"};
/*邻接矩阵表示各路线之间的关系，1表示路线不能同时通行，0表示路线可以同时通行*/
const int data[n][n] = {
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
    {1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0},
    {1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
/*路线对应的交通灯颜色，0表示没有对应颜色*/
int color[n] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
/*记录交通灯方案的种数*/
static int total;

/*输出交通灯颜色方案*/
void PrintColor() {
    for(int i = 0; i < n; i++) {
        cout<<path[i]<<" ";
        cout<<color[i]<<" ";
    }
    total++;
    if(total == 10) {
        cout<<endl;
        cout<<"是李鹏辉做的"<<endl;
        exit(0);
    }
    cout<<endl;
}

/*判断与不能同时通行的路线的颜色是否相同*/
int ColorSame(int s) {
    int flag = 0;
    for(int i = 0; i < s; i++) {
        if(data[i][s] == 1 && color[i] == color[s])
            flag = 1;
    }
    return flag;
}

/*递归查找交通灯方案*/
void Painting(int s) {
    /*s = 0~12，如果s = 13说明已经涂完*/
    if(s == n)
        PrintColor();
    else {
        /*1、2、3、4代表四种颜色*/
        for(int i = 1; i <= 4; i++) {
            color[s] = i;
            /*如果第s条路线的交通灯颜色符合要求，则递归处理第s+1条*/
            if(ColorSame(s) == 0)
                Painting(s + 1);
        }
    }
}

int main() {
    total = 0;
    Painting(0);
    return 0;
}
