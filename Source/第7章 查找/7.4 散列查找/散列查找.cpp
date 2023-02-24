#include<iostream> 
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 7 //定义散列表表未数组的长度
#define NULLKEY -32768 
using namespace std;
typedef struct
{
	int *elem;  //数据元素存储基地址，动态分配数组
}HashTable;
int m = HASHSIZE;     //散列表长，全局变量
			   //初始化散列表
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
//散列函数
int Hash(int key)
{
	return key % m;    //除留余数法
} 
//插入关键字进散列表
void InsertHash(HashTable *h, int key)
{
	int addr = Hash(key);              //求散列地址
	int i;
	for (i = 1; h->elem[addr] != NULLKEY;i++) //如果不为空，则冲突
	{
		addr = (addr + i) % m;         //开放地址法的线性探测
	}
	h->elem[addr] = key;                //直到有空位后插入关键字
}
//散列表查找关键字
int  SearchHash(HashTable h, int key)
{
	int addr = Hash(key);                  //求散列地址
	int i;
	for (i = 1; h.elem[addr] != key;i++)     //如果所查关键字不在除留余数法的列表中，则冲突
	{
		addr = (addr + i) % m;     //开放地址法的线性探测
		if (h.elem[addr] == NULLKEY || addr == Hash(key))
		{
			//如果位置为空或循环回原点
			printf("查找失败, %d 不在Hash表中.\n", key);
			return UNSUCCESS;
		}
	}
	printf("查找成功，%d 在Hash表第 %d 个位置.\n", key, addr+1);
	return SUCCESS;
}
int main(int argc, char **argv)
{
	int i,j= 0;
	HashTable h;
	//初始化Hash表
	InitHashTable(&h); 
	//未插入数据之前，打印Hash表
	printf("\n未插入数据之前，Hash表中内容为:\n");
	for (i = 0; i < HASHSIZE; i++)
	{
		printf("%d  ", h.elem[i]);
	}
	//插入数据
	printf("\n现在插入数据，请输入(A代表结束哦).\n");
	while (scanf("%d", &i) == 1)
	{
		if (i == 'a')
		{
			break;
		}
		InsertHash(&h, i);
	}
	//打印插入数据后Hash表的内容
	printf("插入数据后Hash表的内容为:\n");
	printf("散列地址：\t");
	for (i = 0; i < HASHSIZE; i++) {
		printf("%d\t", i);
	}
	printf("\n散列表：\t");
	for (i = 0; i < HASHSIZE; i++)
	{
		printf("%d\t", h.elem[i]);
	}
	printf("\n现在进行查询.\n");
	SearchHash(h, 22);
	SearchHash(h, 3);
	cout<<"是李鹏辉做的"<<endl;
	system("pause");
	return 0;
}