#include<bits/stdc++.h>
#define  MAX 105
using namespace std;
// 邻接表
class ListDG {
private: // 内部类
    // 邻接表中表对应的链表的顶点
    class ENode {
    public:
        int ivex;           // 该边所指向的顶点的位置
        ENode *nextEdge;    // 指向下一条弧的指针
    };
    // 邻接表中表的顶点
    class VNode {
    public:
        char data;          // 顶点信息
        ENode *firstEdge;   // 指向第一条依附该顶点的弧
    };

private: // 私有成员
    int mVexNum;             // 图的顶点的数目
    int mEdgNum;             // 图的边的数目
    VNode mVexs[MAX];
public:
    // 创建邻接表对应的图(自己输入)
    ListDG();
    // 创建邻接表对应的图(用已提供的数据)
    ListDG(char vexs[], int vlen, char edges[][2], int elen);
    ~ListDG();
    // 深度优先搜索遍历图
    void DFS();
    // 广度优先搜索（类似于树的层次遍历）
    void BFS();
    // 打印邻接表图
    void print();
private:
    // 返回ch的位置
    int getPosition(char ch);
    // 深度优先搜索遍历图的递归实现
    void DFS(int i, int *visited);
    // 将node节点链接到list的最后
    void linkLast(ENode *list, ENode *node);
};
ListDG::ListDG() {
    char c1, c2;
    int v, e;
    int i, p1, p2;
    ENode *node1, *node2;
    cout<<"请输入有向图的顶点数和边数："<<endl;
    cin>>mVexNum>>mEdgNum;
    cout<<"初始化邻接表的顶点："<<endl;
    for(i=0; i<mVexNum; i++) {
        cout << "顶点(" << i << "): ";
        cin>>mVexs[i].data;
        mVexs[i].firstEdge = NULL;
    }
    // 初始化"邻接表"的边
    for(i=0; i<mEdgNum; i++) {
        // 读取边的起始顶点和结束顶点
        cout << "edge(" << i << "): ";
        cin>>c1>>c2;
        p1 = getPosition(c1);
        p2 = getPosition(c2);
        // 初始化node1
        node1 = new ENode();
        node1->ivex = p2;
        // 将node1链接到"p1所在链表的末尾"
        if(mVexs[p1].firstEdge == NULL)
            mVexs[p1].firstEdge = node1;
        else
            linkLast(mVexs[p1].firstEdge, node1);
    }
}
/*
 * 创建邻接表对应的图(用已提供的数据)
 */
ListDG::ListDG(char vexs[], int vlen, char edges[][2], int elen) {
    char c1, c2;
    int i, p1, p2;
    ENode *node1, *node2;
    // 初始化"顶点数"和"边数"
    mVexNum = vlen;
    mEdgNum = elen;
    // 初始化"邻接表"的顶点
    for(i=0; i<mVexNum; i++) {
        mVexs[i].data = vexs[i];
        mVexs[i].firstEdge = NULL;
    }
    // 初始化"邻接表"的边
    for(i=0; i<mEdgNum; i++) {
        // 读取边的起始顶点和结束顶点
        c1 = edges[i][0];
        c2 = edges[i][1];

        p1 = getPosition(c1);
        p2 = getPosition(c2);
        // 初始化node1
        node1 = new ENode();
        node1->ivex = p2;
        // 将node1链接到"p1所在链表的末尾"
        if(mVexs[p1].firstEdge == NULL)
            mVexs[p1].firstEdge = node1;
        else
            linkLast(mVexs[p1].firstEdge, node1);
    }
}
/*
 * 析构函数
 */
ListDG::~ListDG() {
}
/*
 * 将node节点链接到list的最后
 */
void ListDG::linkLast(ENode *list, ENode *node) {
    ENode *p = list;

    while(p->nextEdge)
        p = p->nextEdge;
    p->nextEdge = node;
}
/*
 * 返回ch的位置
 */
int ListDG::getPosition(char ch) {
    int i;
    for(i=0; i<mVexNum; i++)
        if(mVexs[i].data==ch)
            return i;
    return -1;
}
/*
 * 深度优先搜索遍历图的递归实现
 */
void ListDG::DFS(int i, int *visited) {
    ENode *node;

    visited[i] = 1;
    cout << mVexs[i].data << " ";
    node = mVexs[i].firstEdge;
    while (node != NULL) {
        if (!visited[node->ivex])
            DFS(node->ivex, visited);
        node = node->nextEdge;
    }
}
/*
 * 深度优先搜索遍历图
 */
void ListDG::DFS() {
    int i;
    int visited[MAX];       // 顶点访问标记

    // 初始化所有顶点都没有被访问
    for (i = 0; i < mVexNum; i++)
        visited[i] = 0;

    cout << "DFS: ";
    for (i = 0; i < mVexNum; i++) {
        if (!visited[i])
            DFS(i, visited);
    }
    cout << endl;
}
/*
 * 广度优先搜索（类似于树的层次遍历）
 */
void ListDG::BFS() {
    int head = 0;
    int rear = 0;
    int queue[MAX];     // 辅组队列
    int visited[MAX];   // 顶点访问标记
    int i, j, k;
    ENode *node;

    for (i = 0; i < mVexNum; i++)
        visited[i] = 0;

    cout << "BFS: ";
    for (i = 0; i < mVexNum; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            cout << mVexs[i].data << " ";
            queue[rear++] = i;  // 入队列
        }
        while (head != rear) {
            j = queue[head++];  // 出队列
            node = mVexs[j].firstEdge;
            while (node != NULL) {
                k = node->ivex;
                if (!visited[k]) {
                    visited[k] = 1;
                    cout << mVexs[k].data << " ";
                    queue[rear++] = k;
                }
                node = node->nextEdge;
            }
        }
    }
    cout << endl;
}
/*
 * 打印邻接表图
 */
void ListDG::print() {
    int i,j;
    ENode *node;

    cout << "List Graph:" << endl;
    for (i = 0; i < mVexNum; i++) {
        cout << i << "(" << mVexs[i].data << "): ";
        node = mVexs[i].firstEdge;
        while (node != NULL) {
            cout << node->ivex << "(" << mVexs[node->ivex].data << ") ";
            node = node->nextEdge;
        }
        cout << endl;
    }
}
int main() {
    ListDG* pG;
    pG = new ListDG();
    pG->print();   // 打印图
    pG->DFS();     // 深度优先遍历
    pG->BFS();     // 广度优先遍历
    cout<<"是李鹏辉做的"<<endl;
    return 0;
}
