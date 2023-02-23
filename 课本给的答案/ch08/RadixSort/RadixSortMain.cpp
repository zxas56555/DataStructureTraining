#include <iostream>
#include <stdlib.h>
#define MaxSize 20
using namespace std;

/*����������ṹ*/
typedef struct Node {
    int data;
    Node *next;
}Node;


/*������buc��ĩβ���Ԫ��data*/ 
void AddNode(Node *buc, int data) {
    Node *p;
    /*�������һ�����*/
    for(p = buc; p->next != NULL; p = p->next)
        ;
    /*�����½�㣬�����½����뵽ԭ����ĩβ*/ 
    p->next = (Node *) malloc (sizeof(Node));
    p->next->data = data;
    p->next->next = NULL;
}

/*ɾ������buc�еĽ��pos*/ 
void DeleteNode(Node *buc, Node *pos) {
    Node *p;
    /*����pos���֮ǰ�Ľ��*/ 
    for(p = buc; p->next != pos; p = p->next)
        ;
    /*ɾ�����pos*/
    p->next = pos->next;
    free(pos);
}

void RadixSort(int a[], int n) {
    int i, j, tmp, pow = 10;
    Node bucket[10], q, *p;
    /*��ʼ��10��Ͱ*/
    for(i = 0; i < 10; i++) {
        bucket[i].next = NULL;
        bucket[i].data = 0;
    }
    /*����λ����*/
    for(i = 0; i < n; i++) {
    	tmp = a[i] % pow;
        AddNode(&bucket[tmp], a[i]);
	}
    pow *= 10;
    /*�ٰ�����8λ����*/
    for(j = 0; j < 8; j++) {
        for(i = 0; i < 10; i++) {
            for(p = bucket[i].next; p != NULL; p = q.next) {
                tmp = (p->data % pow) / (pow / 10); /*��ȡ��ǰ�Ƚ�λ�ϵ���*/
                q.data = p->data; /*q��������¼qָ��ṹ������*/
                q.next = p->next;
                if(tmp != i) { /*���δ�ŵ���ȷ��Ͱ��*/
                    DeleteNode(&bucket[i], p);
                    AddNode(&bucket[tmp], q.data);
                }
            }
        }
        pow *= 10;
    }
    i = 0;
    for(p = bucket[0].next; p != NULL; p = p->next)
        a[i++] = p->data;
}

void PrintArray(int a[], int n) {
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main() {
	int a[MaxSize] = {12, 998, 1234, 56, 9, 36, 87, 56780, 32, 90};
	int n = 10;
	cout<<"����֮ǰ��";
	PrintArray(a, n);
	RadixSort(a, n);
	cout<<"����֮��";
	PrintArray(a, n); 
	return 0;
}
