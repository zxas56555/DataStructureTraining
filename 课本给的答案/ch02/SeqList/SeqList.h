#ifndef SEQLIST_H /*避免重复引用头文件*/
#define SEQLIST_H
const int MaxSize = 100; /*顺序表的最大容量为100*/
template <class ElemType> /*定义模板类SeqList*/
class SeqList{
public:
	SeqList(); /*建立空的顺序表*/
   	SeqList(ElemType a[ ], int n); /*建立一个长度为n的顺序表*/
   	~SeqList(); /*析构函数*/
   	int Length(); /*返回顺序表的表长*/
   	ElemType Get(int i); /*按位查找*/
   	int Locate(ElemType x); /*按值查找*/
   	void Insert(int i, ElemType x); /*插入操作*/
   	ElemType Delete(int i); /*删除操作*/
   	void PrintList(); /*遍历操作*/
private:
   	ElemType data[MaxSize]; /*存放数据元素的数组*/
   	int length; /*顺序表的长度*/
};
#endif
