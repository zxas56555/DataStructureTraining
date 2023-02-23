#include <iostream>
using namespace std;
#include "BiTree.h" /*���ö������ඨ��ͷ�ļ�*/
#include "SeqStack.cpp" /*����˳��ջ��ʵ��Դ�ļ�*/

/*�������ʱʹ�õ�˳��ջ��Ԫ������*/
struct Element{
	BiNode *ptr;
	int flag;
};

BiNode *BiTree::Creat(BiNode *bt) {
	char ch;
	cout<<"�����봴��һ�ö������Ľ�����ݣ�"<<endl;
	cin>>ch;
	/*'#'����ն�����*/
    if(ch == '#') 
		return NULL;
    else { 
		bt = new BiNode; /*�����½��*/
        bt->data = ch;
        bt->lchild = Creat(bt->lchild); /*�ݹ鴴��������*/
        bt->rchild = Creat(bt->rchild); /*�ݹ鴴��������*/
    } 
    return bt;
}

void BiTree::Release(BiNode *bt) {
	/*���պ��������˳���ͷŶ�����*/
	if(bt != NULL) {                  
		Release(bt->lchild); /*�ͷ�������*/
		Release(bt->rchild); /*�ͷ�������*/
        delete bt;
	}  
}

/*ǰ��ǵݹ����*/
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

/*����ǵݹ����*/
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

/*����ǵݹ����*/
void BiTree::PostOrder(BiNode *bt) {
	SeqStack<Element> S;
	Element e;
	/*bt��Ϊ�ջ���ջ��Ϊ��*/
	while(bt != NULL || S.Empty() == 0) {
		while(bt != NULL) {
			e.ptr = bt;
			e.flag = 1;
			S.Push(e);
			bt = bt->lchild;
		}
		/*ջ��Ϊ�ղ���ջ����flagΪ2ʱ����ջ������*/
		while((S.Empty() == 0)&&(S.GetTop()).flag == 2) {
			e = S.Pop();
			cout<<e.ptr->data<<" ";
		}
		/*ջ��Ϊ�գ�����ջ����flagΪ1ʱ����ջ����flag����Ϊ2�����������Һ���*/
		if(S.Empty() == 0) {
			e = S.Pop();
			bt = e.ptr->rchild;
			e.flag = 2;
			S.Push(e);
		}
	}
}


