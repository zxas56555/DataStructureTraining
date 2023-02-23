#include <iostream>
#include <stdlib.h>
#include <ctime>
#define MaxSize 20 /*散列表表长的最大值*/
using namespace std;

/*散列表的表长为m，散列函数为H(key) = key % p，线性探测处理冲突*/ 
/*查找关键码key，如果查找成功，则返回key的下标*/
/*如果查找失败，则返回0，并将key存入散列表的下标j处*/
int HashSearch(int ht[], int m, int key, int &j, int &count, int p) {
	int i;
	j = key % p;
	count = 1;
	if(ht[j] == key) /*比较1次，查找成功*/ 
		return j;
	else if(ht[j] == 0) { /*查找失败，把k插入散列表*/
		ht[j] = key;
		return 0;
	} 
	/*比较1次后没有找到，线性探测继续查找*/
	i = (j + 1) % m;
	/*在散列地址不空时循环遍历散列表一遍*/
	while(ht[i] != 0 && i != j) {
		count++;
		/*查找成功*/
		if(ht[i] == key) {
			j = i;
			return 1;
		}
		/*继续比较下一个位置*/
		else {
			i = (i + 1) % m;
		}
	}
	/*查找失败，并且散列表中没有空闲位置*/
	if(i == j) {
		cout<<"空间不足，溢出！";
		return 0;
	}
	/*因找到空闲位置退出循环，插入k*/
	else {
		ht[i] = key;
		j = i;
		return 0;
	}
} 

void PrintArray(int ht[], int m) {
	for(int i = 0; i < m; i++)
		cout<<ht[i]<<" ";
	cout<<endl;
}

int main() {	
	int s[MaxSize] = {26, 36, 41, 38, 44, 15, 68, 12, 06, 51, 25};
	int n = sizeof(s)/sizeof(int);
	int p = 13, m = 15;
	int ht[MaxSize] = {0};
	int key, i = 0, index = 0, count = 0;
	/*构造闭散列表*/
	for(i = 0; i < n; i++)
		HashSearch(ht, m, s[i], index, count, p); 
	/*输出散列表*/
	cout<<"闭散列表为："<<endl;
	PrintArray(ht, m);
	cout<<"请输入查找关键码(!=0)：";
	cin>>key;
	int result = HashSearch(ht, m, key, index, count, p);
	if(result != 0) {
		cout<<"查找成功！关键码"<<key<<"的下标为"<<index<<"！"<<endl;
		cout<<"共比较"<<count<<"次！" <<endl;
	}
	else {
		cout<<"查找失败，原散列表中没有关键码"<<key<<"！"<<endl;
		cout<<"插入关键码"<<key<<"后的新散列表为："<<endl;
		PrintArray(ht, m); 
		cout<<"新关键码"<<key<<"在散列表的下标"<<index<<"处！"<<endl; 
	}
	return 0;
}
