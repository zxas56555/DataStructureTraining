#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
#define N 10000
typedef int Status;                   // Status 相当于 int
typedef int TElemType;               //TElemType 相当于 int
typedef struct BiTNode{
	TElemType data;                   //结点数据域
	struct BiTNode *lchild,*rchild;   //左右孩子指针
}BiTNode,*BiTree;
Status SearchBST(BiTree T,int key,BiTree f,BiTree *p)    //二叉排序树的查找
{
    if(!T)                 //查找不成功
    {
        *p = f;
        return 0;
    }
    else if(T->data == key)    //查找成功
    {
        *p = T;
        return 1;
    }
    else if (key < T->data)
    {
        return SearchBST(T->lchild, key, T, p);  //在左子树继续查找
    }
    else
    {
        return SearchBST(T->rchild, key, T, p);  //在右子树继续查找
    }
}
Status InsertBST (BiTree *T,int key)   //二叉排序树的插入
{
    BiTree p, s;
    if(!SearchBST(*T, key, NULL, &p))  //查找二叉排序树中是否已经存在key值
    {
        s = new BiTNode;
        s->data = key;
        s->lchild = s->rchild = NULL;
        if(!p)                          //若二叉排序树为空，则插入根节点
        {
            *T = s;
        }
        else if(key < p->data)
            p->lchild = s;
        else
            p->rchild = s;
    	return 1;
	}
    else
    	return 0;
}
Status Delete(BiTree *p)       //二叉排序树的删除
{
    BiTree q,s;
    if( (*p) -> rchild==NULL)      //无右，以左子树替换
    {
        q=*p;
		*p=(*p)->lchild;
        free(q);
    }
    else if((*p)->lchild==NULL)     //无左
    {
        q=*p;
        *p=(*p)->rchild;
        free(q);
    }
    else
    {
        q=*p;
        s=(*p)->lchild;     //左一下
        while(s->rchild)    //右到底
        {
            q=s;
            s=s->rchild;
        }
        (*p)->data=s->data;     //前驱替换删除节点
        if(q!=*p)
            q->rchild=s->lchild;
        else
            q->lchild=s->lchild;
        free(s);
    }
    return 1;
}
Status DeleteBST(BiTree *T,int key)
{
    if(!*T)       //不存在与key相等的元素
    	return 0;
	else
	{
        if(key==(*T)->data)
            return Delete(T);
        else if(key<(*T)->data)
            return DeleteBST(&(*T)->lchild,key);
        else
            return DeleteBST(&(*T)->rchild,key);
    }
}
Status InOrderTraverse(BiTree T)    //递归中序遍历
{
    if(T==NULL) return 1;
    else{
	     InOrderTraverse(T->lchild); //中序遍历左子树
	     cout << T->data << " ";            //访问根结点
	     InOrderTraverse(T->rchild); //中序遍历右子树
	    }
}
int main()
{
	int i,num;
    BiTree T=NULL;
	int a[N];
	int x;
	cout << "请输入要建立二叉排序树的个数:" ;
	int n;
	cin >> n;
	cout << endl << "请输入" << n << "个数字：" <<  endl;
	for(int i = 0; i < n ; i++)
	{
		scanf("%d",&a[i]);
	}
	cout << endl;

    for(i = 0;i < n;i ++)
    {
        InsertBST(&T,a[i]);
    }
	cout << "遍历二叉树：";
	InOrderTraverse(T); cout << endl << endl;
	cout << "请输入你要插入的元素:";
	cin >> x;
	if(InsertBST(&T,x))
		cout << "插入元素成功！！！"<< endl;
	else
		cout << "插入元素失败，因为树中已经有目标元素！！" << endl;
	cout << "遍历二叉树：";
	InOrderTraverse(T); cout << endl << endl;
	cout << "请输入你要删除的元素：";
	cin >> x;
	if(DeleteBST(&T,x))
		cout << "删除元素成功！！！"<< endl;
	else
		cout << "删除元素失败，因为树中无目标元素！！" << endl;
	cout << "遍历二叉树：";
	InOrderTraverse(T); cout << endl << endl;
	cout<<"是李鹏辉做的"<<endl;
	return 0;
}
