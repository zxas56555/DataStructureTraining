#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int DataType;//
//顺序队列：类型和界面函数声明
struct SeqQueue {
    // 顺序队列类型定义
    int MAXNUM; // 队列中最大元素个数
    int f, r;//定义头结点front和尾结点rear
    DataType *q;
};
typedef struct SeqQueue *PSeqQueue; // 顺序队列类型的指针类型
//创建一个空队列
PSeqQueue createEmptyQueue_seq(int m) {
    PSeqQueue queue = (PSeqQueue)malloc(sizeof(struct SeqQueue));
    if (queue != NULL) {
        queue->q = (DataType*)malloc(sizeof(DataType) *m);
        if (queue->q) {
            queue->MAXNUM = m;
            queue->f = 0;
            queue->r = 0;
            return (queue);
        } else
            free(queue);
    }
    printf("Out of space!!\n"); // 存储分配失败
    return NULL;
}
//判断队列是否为空
int isEmptyQueue_seq(PSeqQueue queue) {
    return (queue->f == queue->r);
}
// 在队尾插入元素x，此队列队尾一个元素空出来
void enQueue_seq(PSeqQueue queue, DataType x) {
    if ((queue->r + 1) % queue->MAXNUM == queue->f)
        printf("Full queue.\n");
    else {
        queue->q[queue->r] = x;
        queue->r = (queue->r + 1) % queue->MAXNUM;
    }
}
// 删除队列头部元素
void deQueue_seq(PSeqQueue queue) {
    if (queue->f == queue->r)
        printf("Empty Queue.\n");
    else
        queue->f = (queue->f + 1) % queue->MAXNUM;
}
DataType frontQueue_seq(PSeqQueue queue) {
    if (queue->f == queue->r)
        printf("Empty Queue.\n");
    else
        return (queue->q[queue->f]);
}
//个体状态判断函数
int farmer(int location) {
    //判断农夫的位置
    return (0 != (location &0x08));
}
int wolf(int location) {
    //判断狼的位置
    return (0 != (location &0x04));
}
int cabbage(int location) {
    //判断白菜的位置
    return (0 != (location &0x02));
}
int goat(int location) {
    //判断羊的位置
    return (0 != (location &0x01));//
}
//安全状态的判断函数
// 若状态安全则返回true
int safe(int location) {
    // 羊吃白菜
    if ((goat(location) == cabbage(location)) && (goat(location) != farmer(location)))
        return 0;
    // 狼吃羊
    if ((goat(location) == wolf(location)) && (goat(location) != farmer(location)))
        return 0;
    return 1; // 其他状态是安全的
}
void bin_print(int num) {
    char tmp[4];
    int i;
    for (i = 0; i < 4; ++i) {
        tmp[i] = num & 0x01;
        num >>= 1;
    }
    for (i = 3; i >= 0; --i)
        putchar((tmp[i] == 0)?'0':'1');
    return;
}
int main() {
    int i, movers, location, newlocation;
    int route[16]; //用于记录已考虑的状态路径
    PSeqQueue moveTo; //用于记录可以安全到达的中间状态
    moveTo = createEmptyQueue_seq(20); //创建空队列
    enQueue_seq(moveTo, 0x00); //初始状态进队列,0x00入队
    for (i = 0; i < 16; i++)
        route[i] =  -1;
    //准备数组route初值
    route[0] = 0;
//该算法仅打印一种路径，起思想是dfs
    while (!isEmptyQueue_seq(moveTo) && (route[15] ==  - 1)) {
        location = frontQueue_seq(moveTo); //取队头状态为当前状态
        deQueue_seq(moveTo);//删除moveTo结点，moveTo结点出栈
        //考虑各种物品移动
        for (movers = 1; movers <= 8; movers <<= 1)
            //农夫与移动的物品在同一侧
            if ((0 != (location & 0x08)) == (0 != (location & movers))) { //判断农夫与移动的物品是否在同一侧
                newlocation = location ^ (0x08 | movers); //计算新状态，异或代表把船上的（0x08|movers）从一个岸移到另一个岸；（0x08|movers）代表船上有农夫和movers代表的东西（movers代表且仅代表一个东西）
                //新状态安全且未处理
                if (safe(newlocation) && (route[newlocation] ==  -1)) {
                    route[newlocation] = location; //记录新状态的前驱
                    enQueue_seq(moveTo, newlocation); //新状态入队
                }
            }
    }
    // 打印出路径
    if (route[15] !=  -1)
        //到达最终状态
    {
        printf("The reverse path is : \n");
        for (location = 15; location >= 0; location = route[location]) {
            printf("The location is : %2d, ", location);
            bin_print(location);
            putchar('\n');
            if (location == 0) {
                cout<<"是李鹏辉做的"<<endl;
                exit(0);
            }
        }
    } else
        printf("No solution.\n");
    cout<<"是李鹏辉做的"<<endl;
    return 0;
}
