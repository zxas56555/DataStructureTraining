#include <iostream>
#include <limits>
#include<bits/stdc++.h>
using namespace std;
struct Node { //定义表结点
  int adjvex; //该边所指向的顶点的位置
  int weight;// 边的权值
  Node *next; //下一条边的指针
};
struct HeadNode{ // 定义头结点
    int nodeName; // 顶点信息
    int inDegree; // 入度
    int d; //表示当前情况下起始顶点至该顶点的最短路径,初始化为无穷大
    bool isKnown; //表示起始顶点至该顶点的最短路径是否已知,true表示已知，false表示未知
    int parent; //表示最短路径的上一个顶点
    Node *link; //指向第一条依附该顶点的边的指针
};
//G表示指向头结点数组的第一个结点的指针
//nodeNum表示结点个数
//arcNum表示边的个数
void createGraph(HeadNode *G, int nodeNum, int arcNum) {
  //初始化头结点
  for (int i = 0; i < nodeNum; i++) {
    G[i].nodeName = i+1; //位置0上面存储的是结点v1,依次类推
    G[i].inDegree = 0; //入度为0
    G[i].link = NULL;
  }
  for (int j = 0; j < arcNum; j++) {
    int begin, end, weight;
    cin >> begin >> end >> weight;
    // 创建新的结点插入链接表
    Node *node = new Node;
    node->adjvex = end - 1;
    node->weight = weight;
    ++G[end-1].inDegree; //入度加1
    //插入链接表的第一个位置
    node->next = G[begin-1].link;
    G[begin-1].link = node;
  }
}
//得到begin->end权重
int getWeight(HeadNode *G, int begin, int end) {
  Node *node = G[begin-1].link;
  while (node) {
    if (node->adjvex == end - 1) {
      return node->weight;
    }
    node = node->next;
  }
}
//从start开始，计算其到每一个顶点的最短路径
void Dijkstra(HeadNode *G, int nodeNum, int start) {
  //初始化所有结点
  for (int i = 0; i < nodeNum; i++) {
    G[i].d = INT_MAX; //到每一个顶点的距离初始化为无穷大
    G[i].isKnown = false; // 到每一个顶点的距离为未知数
  }
  G[start-1].d = 0; //到其本身的距离为0
  G[start-1].parent = -1; //表示该结点是起始结点
  while(true) {
   //==== 如果所有的结点的最短距离都已知, 那么就跳出循环
   int k;
   bool ok = true; //表示是否全部ok
   for (k = 0; k < nodeNum; k++) {
     //只要有一个顶点的最短路径未知,ok就设置为false
     if (!G[k].isKnown) {
       ok = false;
       break;
     }
   }
   if (ok) return;
   //==========================================
   //==== 搜索未知结点中d最小的,将其变为known
   //==== 这里其实可以用最小堆来实现
   int i;
   int minIndex = -1;
   for (i = 0; i < nodeNum; i++) {
     if (!G[i].isKnown) {
       if (minIndex == -1)
         minIndex = i;
       else if (G[minIndex].d > G[i].d)
         minIndex = i;
     }
   }
   //===========================================
     G[minIndex].isKnown = true; //将其加入最短路径已知的顶点集
     // 将以minIndex为起始顶点的所有的d更新
     Node *node = G[minIndex].link;
     while (node != NULL) {
       int begin = minIndex + 1;
       int end = node->adjvex + 1;
       int weight = getWeight(G, begin, end);
       if (G[minIndex].d + weight < G[end-1].d) {
         G[end-1].d = G[minIndex].d + weight;
         G[end-1].parent = minIndex; //记录最短路径的上一个结点
       }
       node = node->next;
     }
  }
}

//打印到end-1的最短路径
void printPath(HeadNode *G, int end) {
  if (G[end-1].parent == -1) {
    cout << "v" << end;
  } else if (end != 0) {
    printPath(G, G[end-1].parent + 1); // 因为这里的parent表示的是下标，从0开始，所以要加1
    cout << " -> v" << end;
  }
}
int main() {
  HeadNode *G;
  int nodeNum, arcNum;
  cout<<"请分别输入顶点数和边数："<<endl;
  cin >> nodeNum >> arcNum;
  cout<<"请输入对应的边和权值："<<endl;
  G = new HeadNode[nodeNum];
  createGraph(G, nodeNum, arcNum);
  Dijkstra(G, nodeNum, 1);
  cout << "打印从v1开始所有的最短路径" << endl;
  for (int k = 2; k <= nodeNum; k++) {
    cout << "v1到v" << k << "的最短路径为" << G[k-1].d << ": ";
    printPath(G, k);
    cout << endl;
  }
  cout<<"是李鹏辉做的"<<endl;
return 0;
}

