#include<iostream> 
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 7 //����ɢ�б��δ����ĳ���
#define NULLKEY -32768 
using namespace std;
typedef struct
{
	int *elem;  //����Ԫ�ش洢����ַ����̬��������
}HashTable;
int m = HASHSIZE;     //ɢ�б���ȫ�ֱ���
			   //��ʼ��ɢ�б�
int InitHashTable(HashTable *h)
{
	int i;
	h->elem = (int *)malloc(sizeof(int) * m);
	if (h->elem == NULL)
	{
		fprintf(stderr, "malloc() error.\n");
		return ERROR;
	}
	for (i = 0; i < m; i++)
	{
		h->elem[i] = NULLKEY;
	}
	return OK;
} 
//ɢ�к���
int Hash(int key)
{
	return key % m;    //����������
} 
//����ؼ��ֽ�ɢ�б�
void InsertHash(HashTable *h, int key)
{
	int addr = Hash(key);              //��ɢ�е�ַ
	int i;
	for (i = 1; h->elem[addr] != NULLKEY;i++) //�����Ϊ�գ����ͻ
	{
		addr = (addr + i) % m;         //���ŵ�ַ��������̽��
	}
	h->elem[addr] = key;                //ֱ���п�λ�����ؼ���
}
//ɢ�б���ҹؼ���
int  SearchHash(HashTable h, int key)
{
	int addr = Hash(key);                  //��ɢ�е�ַ
	int i;
	for (i = 1; h.elem[addr] != key;i++)     //�������ؼ��ֲ��ڳ������������б��У����ͻ
	{
		addr = (addr + i) % m;     //���ŵ�ַ��������̽��
		if (h.elem[addr] == NULLKEY || addr == Hash(key))
		{
			//���λ��Ϊ�ջ�ѭ����ԭ��
			printf("����ʧ��, %d ����Hash����.\n", key);
			return UNSUCCESS;
		}
	}
	printf("���ҳɹ���%d ��Hash��� %d ��λ��.\n", key, addr+1);
	return SUCCESS;
}
int main(int argc, char **argv)
{
	int i,j= 0;
	HashTable h;
	//��ʼ��Hash��
	InitHashTable(&h); 
	//δ��������֮ǰ����ӡHash��
	printf("\nδ��������֮ǰ��Hash��������Ϊ:\n");
	for (i = 0; i < HASHSIZE; i++)
	{
		printf("%d  ", h.elem[i]);
	}
	//��������
	printf("\n���ڲ������ݣ�������(A�������Ŷ).\n");
	while (scanf("%d", &i) == 1)
	{
		if (i == 'a')
		{
			break;
		}
		InsertHash(&h, i);
	}
	//��ӡ�������ݺ�Hash�������
	printf("�������ݺ�Hash�������Ϊ:\n");
	printf("ɢ�е�ַ��\t");
	for (i = 0; i < HASHSIZE; i++) {
		printf("%d\t", i);
	}
	printf("\nɢ�б�\t");
	for (i = 0; i < HASHSIZE; i++)
	{
		printf("%d\t", h.elem[i]);
	}
	printf("\n���ڽ��в�ѯ.\n");
	SearchHash(h, 22);
	SearchHash(h, 3);
	cout<<"������������"<<endl;
	system("pause");
	return 0;
}