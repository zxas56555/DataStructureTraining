#include <iostream>
using namespace std;
#include "BiTree.h" /*引用二叉树类定义头文件*/
#include "SeqStack.cpp" /*引用顺序栈类实现源文件*/

/*后序遍历时使用的顺序栈的元素类型*/
struct Element{
	BiNode *ptr;
	int flag;
};

BiNode *BiTree::Creat(BiNode *bt) {
	char ch;
	cout<<"请输入创建一棵二叉树的结点数据："<<endl;
	cin>>ch;
	/*'#'代表空二叉树*/
    if(ch == '#') 
		return NULL;
    else { 
		bt = new BiNode; /*生成新结点*/
        bt->data = ch;
        bt->lchild = Creat(bt->lchild); /*递归创建左子树*/
        bt->rchild = Creat(bt->rchild); /*递归创建右子树*/
    } 
    return bt;
}

void BiTree::Release(BiNode *bt) {
	/*按照后序遍历的顺序释放二叉树*/
	if(bt != NULL) {                  
		Release(bt->lchild); /*释放左子树*/
		Release(bt->rchild); /*释放右子树*/
        delete bt;
	}  
}

/*前序非递归遍历*/
void BiTree::PreOrder(BiNode *bt) {
	SeqStack<BiNode *> S;
	while(bt != NULL||S.Empty() != 1) {
		while(bt != NULL) {
			cout<<bt->data<<" ";
			S.Push(bt);
			bt = bt->lchild;
		}
		if(S.Empty() != 1) {
			bt = S.Pop();
			bt = bt->rchild;
		}
	}
}

/*中序非递归遍历*/
void BiTree::InOrder(BiNode *bt) {
	SeqStack<BiNode *> S;
	while(bt != NULL || S.Empty() != 1) {
		while(bt != NULL) {
			S.Push(bt);
			bt = bt->lchild;
		}
		if(S.Empty() != 1) {
			bt = S.Pop();
			cout<<bt->data<<" ";
			bt = bt->rchild;
		}
	}
}

/*后序非递归遍历*/
void BiTree::PostOrder(BiNode *bt) {
	SeqStack<Element> S;
	Element e;
	/*bt不为空或者栈不为空*/
	while(bt != NULL || S.Empty() == 0) {
		while(bt != NULL) {
			e.ptr = bt;
			e.flag = 1;
			S.Push(e);
			bt = bt->lchild;
		}
		/*栈不为空并且栈顶的flag为2时，出栈并访问*/
		while((S.Empty() == 0)&&(S.GetTop()).flag == 2) {
			e = S.Pop();
			cout<<e.ptr->data<<" ";
		}
		/*栈不为空，并且栈顶的flag为1时，将栈顶的flag更改为2，并访问其右孩子*/
		if(S.Empty() == 0) {
			e = S.Pop();
			bt = e.ptr->rchild;
			e.flag = 2;
			S.Push(e);
		}
	}
}


