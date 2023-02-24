#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int DataType;//
//˳����У����ͺͽ��溯������
struct SeqQueue {
    // ˳��������Ͷ���
    int MAXNUM; // ���������Ԫ�ظ���
    int f, r;//����ͷ���front��β���rear
    DataType *q;
};
typedef struct SeqQueue *PSeqQueue; // ˳��������͵�ָ������
//����һ���ն���
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
    printf("Out of space!!\n"); // �洢����ʧ��
    return NULL;
}
//�ж϶����Ƿ�Ϊ��
int isEmptyQueue_seq(PSeqQueue queue) {
    return (queue->f == queue->r);
}
// �ڶ�β����Ԫ��x���˶��ж�βһ��Ԫ�ؿճ���
void enQueue_seq(PSeqQueue queue, DataType x) {
    if ((queue->r + 1) % queue->MAXNUM == queue->f)
        printf("Full queue.\n");
    else {
        queue->q[queue->r] = x;
        queue->r = (queue->r + 1) % queue->MAXNUM;
    }
}
// ɾ������ͷ��Ԫ��
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
//����״̬�жϺ���
int farmer(int location) {
    //�ж�ũ���λ��
    return (0 != (location &0x08));
}
int wolf(int location) {
    //�ж��ǵ�λ��
    return (0 != (location &0x04));
}
int cabbage(int location) {
    //�жϰײ˵�λ��
    return (0 != (location &0x02));
}
int goat(int location) {
    //�ж����λ��
    return (0 != (location &0x01));//
}
//��ȫ״̬���жϺ���
// ��״̬��ȫ�򷵻�true
int safe(int location) {
    // ��԰ײ�
    if ((goat(location) == cabbage(location)) && (goat(location) != farmer(location)))
        return 0;
    // �ǳ���
    if ((goat(location) == wolf(location)) && (goat(location) != farmer(location)))
        return 0;
    return 1; // ����״̬�ǰ�ȫ��
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
    int route[16]; //���ڼ�¼�ѿ��ǵ�״̬·��
    PSeqQueue moveTo; //���ڼ�¼���԰�ȫ������м�״̬
    moveTo = createEmptyQueue_seq(20); //�����ն���
    enQueue_seq(moveTo, 0x00); //��ʼ״̬������,0x00���
    for (i = 0; i < 16; i++)
        route[i] =  -1;
    //׼������route��ֵ
    route[0] = 0;
//���㷨����ӡһ��·������˼����dfs
    while (!isEmptyQueue_seq(moveTo) && (route[15] ==  - 1)) {
        location = frontQueue_seq(moveTo); //ȡ��ͷ״̬Ϊ��ǰ״̬
        deQueue_seq(moveTo);//ɾ��moveTo��㣬moveTo����ջ
        //���Ǹ�����Ʒ�ƶ�
        for (movers = 1; movers <= 8; movers <<= 1)
            //ũ�����ƶ�����Ʒ��ͬһ��
            if ((0 != (location & 0x08)) == (0 != (location & movers))) { //�ж�ũ�����ƶ�����Ʒ�Ƿ���ͬһ��
                newlocation = location ^ (0x08 | movers); //������״̬��������Ѵ��ϵģ�0x08|movers����һ�����Ƶ���һ��������0x08|movers����������ũ���movers����Ķ�����movers�����ҽ�����һ��������
                //��״̬��ȫ��δ����
                if (safe(newlocation) && (route[newlocation] ==  -1)) {
                    route[newlocation] = location; //��¼��״̬��ǰ��
                    enQueue_seq(moveTo, newlocation); //��״̬���
                }
            }
    }
    // ��ӡ��·��
    if (route[15] !=  -1)
        //��������״̬
    {
        printf("The reverse path is : \n");
        for (location = 15; location >= 0; location = route[location]) {
            printf("The location is : %2d, ", location);
            bin_print(location);
            putchar('\n');
            if (location == 0) {
                cout<<"������������"<<endl;
                exit(0);
            }
        }
    } else
        printf("No solution.\n");
    cout<<"������������"<<endl;
    return 0;
}
