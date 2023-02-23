#include <iostream>
#include <stdlib.h>
#define MaxSize 20
using namespace std;

/*定义链表结点结构*/
typedef struct Node {
    int data;
    Node *next;
}Node;


/*在链表buc的末尾添加元素data*/ 
void AddNode(Node *buc, int data) {
    Node *p;
    /*查找最后一个结点*/
    for(p = buc; p->next != NULL; p = p->next)
        ;
    /*申请新结点，并将新结点插入到原链表末尾*/ 
    p->next = (Node *) malloc (sizeof(Node));
    p->next->data = data;
    p->next->next = NULL;
}

/*删除链表buc中的结点pos*/ 
void DeleteNode(Node *buc, Node *pos) {
    Node *p;
    /*查找pos结点之前的结点*/ 
    for(p = buc; p->next != pos; p = p->next)
        ;
    /*删除结点pos*/
    p->next = pos->next;
    free(pos);
}

void RadixSort(int a[], int n) {
    int i, j, tmp, pow = 10;
    Node bucket[10], q, *p;
    /*初始化10个桶*/
    for(i = 0; i < 10; i++) {
        bucket[i].next = NULL;
        bucket[i].data = 0;
    }
    /*按个位分配*/
    for(i = 0; i < n; i++) {
    	tmp = a[i] % pow;
        AddNode(&bucket[tmp], a[i]);
	}
    pow *= 10;
    /*再按其它8位分配*/
    for(j = 0; j < 8; j++) {
        for(i = 0; i < 10; i++) {
            for(p = bucket[i].next; p != NULL; p = q.next) {
                tmp = (p->data % pow) / (pow / 10); /*获取当前比较位上的数*/
                q.data = p->data; /*q是用来记录q指向结构的数据*/
                q.next = p->next;
                if(tmp != i) { /*如果未放到正确的桶内*/
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
	cout<<"排序之前：";
	PrintArray(a, n);
	RadixSort(a, n);
	cout<<"排序之后：";
	PrintArray(a, n); 
	return 0;
}
