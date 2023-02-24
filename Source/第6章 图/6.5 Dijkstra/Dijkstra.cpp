#include <iostream>
#include <limits>
#include<bits/stdc++.h>
using namespace std;
struct Node { //�������
  int adjvex; //�ñ���ָ��Ķ����λ��
  int weight;// �ߵ�Ȩֵ
  Node *next; //��һ���ߵ�ָ��
};
struct HeadNode{ // ����ͷ���
    int nodeName; // ������Ϣ
    int inDegree; // ���
    int d; //��ʾ��ǰ�������ʼ�������ö�������·��,��ʼ��Ϊ�����
    bool isKnown; //��ʾ��ʼ�������ö�������·���Ƿ���֪,true��ʾ��֪��false��ʾδ֪
    int parent; //��ʾ���·������һ������
    Node *link; //ָ���һ�������ö���ıߵ�ָ��
};
//G��ʾָ��ͷ�������ĵ�һ������ָ��
//nodeNum��ʾ������
//arcNum��ʾ�ߵĸ���
void createGraph(HeadNode *G, int nodeNum, int arcNum) {
  //��ʼ��ͷ���
  for (int i = 0; i < nodeNum; i++) {
    G[i].nodeName = i+1; //λ��0����洢���ǽ��v1,��������
    G[i].inDegree = 0; //���Ϊ0
    G[i].link = NULL;
  }
  for (int j = 0; j < arcNum; j++) {
    int begin, end, weight;
    cin >> begin >> end >> weight;
    // �����µĽ��������ӱ�
    Node *node = new Node;
    node->adjvex = end - 1;
    node->weight = weight;
    ++G[end-1].inDegree; //��ȼ�1
    //�������ӱ�ĵ�һ��λ��
    node->next = G[begin-1].link;
    G[begin-1].link = node;
  }
}
//�õ�begin->endȨ��
int getWeight(HeadNode *G, int begin, int end) {
  Node *node = G[begin-1].link;
  while (node) {
    if (node->adjvex == end - 1) {
      return node->weight;
    }
    node = node->next;
  }
}
//��start��ʼ�������䵽ÿһ����������·��
void Dijkstra(HeadNode *G, int nodeNum, int start) {
  //��ʼ�����н��
  for (int i = 0; i < nodeNum; i++) {
    G[i].d = INT_MAX; //��ÿһ������ľ����ʼ��Ϊ�����
    G[i].isKnown = false; // ��ÿһ������ľ���Ϊδ֪��
  }
  G[start-1].d = 0; //���䱾��ľ���Ϊ0
  G[start-1].parent = -1; //��ʾ�ý������ʼ���
  while(true) {
   //==== ������еĽ�����̾��붼��֪, ��ô������ѭ��
   int k;
   bool ok = true; //��ʾ�Ƿ�ȫ��ok
   for (k = 0; k < nodeNum; k++) {
     //ֻҪ��һ����������·��δ֪,ok������Ϊfalse
     if (!G[k].isKnown) {
       ok = false;
       break;
     }
   }
   if (ok) return;
   //==========================================
   //==== ����δ֪�����d��С��,�����Ϊknown
   //==== ������ʵ��������С����ʵ��
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
     G[minIndex].isKnown = true; //����������·����֪�Ķ��㼯
     // ����minIndexΪ��ʼ��������е�d����
     Node *node = G[minIndex].link;
     while (node != NULL) {
       int begin = minIndex + 1;
       int end = node->adjvex + 1;
       int weight = getWeight(G, begin, end);
       if (G[minIndex].d + weight < G[end-1].d) {
         G[end-1].d = G[minIndex].d + weight;
         G[end-1].parent = minIndex; //��¼���·������һ�����
       }
       node = node->next;
     }
  }
}

//��ӡ��end-1�����·��
void printPath(HeadNode *G, int end) {
  if (G[end-1].parent == -1) {
    cout << "v" << end;
  } else if (end != 0) {
    printPath(G, G[end-1].parent + 1); // ��Ϊ�����parent��ʾ�����±꣬��0��ʼ������Ҫ��1
    cout << " -> v" << end;
  }
}
int main() {
  HeadNode *G;
  int nodeNum, arcNum;
  cout<<"��ֱ����붥�����ͱ�����"<<endl;
  cin >> nodeNum >> arcNum;
  cout<<"�������Ӧ�ıߺ�Ȩֵ��"<<endl;
  G = new HeadNode[nodeNum];
  createGraph(G, nodeNum, arcNum);
  Dijkstra(G, nodeNum, 1);
  cout << "��ӡ��v1��ʼ���е����·��" << endl;
  for (int k = 2; k <= nodeNum; k++) {
    cout << "v1��v" << k << "�����·��Ϊ" << G[k-1].d << ": ";
    printPath(G, k);
    cout << endl;
  }
  cout<<"������������"<<endl;
return 0;
}

