#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
#define N 10000
typedef int Status;                   // Status �൱�� int
typedef int TElemType;               //TElemType �൱�� int
typedef struct BiTNode{
	TElemType data;                   //���������
	struct BiTNode *lchild,*rchild;   //���Һ���ָ��
}BiTNode,*BiTree;
Status SearchBST(BiTree T,int key,BiTree f,BiTree *p)    //�����������Ĳ���
{
    if(!T)                 //���Ҳ��ɹ�
    {
        *p = f;
        return 0;
    }
    else if(T->data == key)    //���ҳɹ�
    {
        *p = T;
        return 1;
    }
    else if (key < T->data)
    {
        return SearchBST(T->lchild, key, T, p);  //����������������
    }
    else
    {
        return SearchBST(T->rchild, key, T, p);  //����������������
    }
}
Status InsertBST (BiTree *T,int key)   //�����������Ĳ���
{
    BiTree p, s;
    if(!SearchBST(*T, key, NULL, &p))  //���Ҷ������������Ƿ��Ѿ�����keyֵ
    {
        s = new BiTNode;
        s->data = key;
        s->lchild = s->rchild = NULL;
        if(!p)                          //������������Ϊ�գ��������ڵ�
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
Status Delete(BiTree *p)       //������������ɾ��
{
    BiTree q,s;
    if( (*p) -> rchild==NULL)      //���ң����������滻
    {
        q=*p;
		*p=(*p)->lchild;
        free(q);
    }
    else if((*p)->lchild==NULL)     //����
    {
        q=*p;
        *p=(*p)->rchild;
        free(q);
    }
    else
    {
        q=*p;
        s=(*p)->lchild;     //��һ��
        while(s->rchild)    //�ҵ���
        {
            q=s;
            s=s->rchild;
        }
        (*p)->data=s->data;     //ǰ���滻ɾ���ڵ�
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
    if(!*T)       //��������key��ȵ�Ԫ��
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
Status InOrderTraverse(BiTree T)    //�ݹ��������
{
    if(T==NULL) return 1;
    else{
	     InOrderTraverse(T->lchild); //�������������
	     cout << T->data << " ";            //���ʸ����
	     InOrderTraverse(T->rchild); //�������������
	    }
}
int main()
{
	int i,num;
    BiTree T=NULL;
	int a[N];
	int x;
	cout << "������Ҫ���������������ĸ���:" ;
	int n;
	cin >> n;
	cout << endl << "������" << n << "�����֣�" <<  endl;
	for(int i = 0; i < n ; i++)
	{
		scanf("%d",&a[i]);
	}
	cout << endl;

    for(i = 0;i < n;i ++)
    {
        InsertBST(&T,a[i]);
    }
	cout << "������������";
	InOrderTraverse(T); cout << endl << endl;
	cout << "��������Ҫ�����Ԫ��:";
	cin >> x;
	if(InsertBST(&T,x))
		cout << "����Ԫ�سɹ�������"<< endl;
	else
		cout << "����Ԫ��ʧ�ܣ���Ϊ�����Ѿ���Ŀ��Ԫ�أ���" << endl;
	cout << "������������";
	InOrderTraverse(T); cout << endl << endl;
	cout << "��������Ҫɾ����Ԫ�أ�";
	cin >> x;
	if(DeleteBST(&T,x))
		cout << "ɾ��Ԫ�سɹ�������"<< endl;
	else
		cout << "ɾ��Ԫ��ʧ�ܣ���Ϊ������Ŀ��Ԫ�أ���" << endl;
	cout << "������������";
	InOrderTraverse(T); cout << endl << endl;
	cout<<"������������"<<endl;
	return 0;
}
