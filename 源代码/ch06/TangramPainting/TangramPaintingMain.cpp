#include <iostream>
using namespace std;

/*���ɰ����*/
const int n = 7;
/*�ڽӾ���1��ʾ���ڣ�0��ʾ������*/
const int data[n][n] = {
    {0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 1, 1, 0, 0}
};
/*���ɰ����ɫ��0��ʾû��Ϳɫ*/
int color[n]= {0, 0, 0, 0, 0, 0, 0};
/*��¼Ϳɫ����������*/
static int total; 

/*���Ϳɫ����*/
void PrintColor() {
    for(int i = 0; i < n; i++) {
        cout<<color[i]<<" ";
    }
    total++;
    cout<<endl;
}

/*�ж�����Χ�����ɰ���ɫ�Ƿ���ͬ*/
int ColorSame(int s) {
    int flag = 0;
    for(int i = 0; i < s; i++) {
        /*�ж����ڵĿ���ɫ�Ƿ���ͬ*/
        if(data[i][s] == 1 && color[i] == color[s])
            flag = 1;
    }
    return flag;
}

/*�ݹ����Ϳɫ����*/
void Painting(int s) {
    /*s=0~6�����s=7˵���Ѿ�Ϳ��*/
    if(s == n)
        PrintColor();
    else {
        /*1��2��3��4����������ɫ*/
        for(int i = 1; i <= 4; i++) {
            color[s] = i;
            /*������ɰ�s�����ڵ����ɰ���ɫ��ͬ����ݹ�Ϳ���ɰ�s+1*/ 
            if(ColorSame(s) == 0)
                Painting(s + 1);
        }
    }
}

int main() {
    total = 0;
    Painting(0);
    cout<<"Ϳɫ��������Ϊ"<<total<<"�֣�"<<endl;
    return 0;
}

