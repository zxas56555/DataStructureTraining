#include <iostream>
using namespace std;

/*七巧板块数*/
const int n = 7;
/*邻接矩阵，1表示相邻，0表示不相邻*/
const int data[n][n] = {
    {0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 1, 1, 0, 0}
};
/*七巧板的颜色，0表示没有涂色*/
int color[n]= {0, 0, 0, 0, 0, 0, 0};
/*记录涂色方案的种数*/
static int total; 

/*输出涂色方案*/
void PrintColor() {
    for(int i = 0; i < n; i++) {
        cout<<color[i]<<" ";
    }
    total++;
    cout<<endl;
}

/*判断与周围的七巧板颜色是否相同*/
int ColorSame(int s) {
    int flag = 0;
    for(int i = 0; i < s; i++) {
        /*判断相邻的块颜色是否相同*/
        if(data[i][s] == 1 && color[i] == color[s])
            flag = 1;
    }
    return flag;
}

/*递归查找涂色方案*/
void Painting(int s) {
    /*s=0~6，如果s=7说明已经涂完*/
    if(s == n)
        PrintColor();
    else {
        /*1、2、3、4代表四种颜色*/
        for(int i = 1; i <= 4; i++) {
            color[s] = i;
            /*如果七巧板s和相邻的七巧板颜色不同，则递归涂七巧板s+1*/ 
            if(ColorSame(s) == 0)
                Painting(s + 1);
        }
    }
}

int main() {
    total = 0;
    Painting(0);
    cout<<"涂色方案种数为"<<total<<"种！"<<endl;
    return 0;
}

