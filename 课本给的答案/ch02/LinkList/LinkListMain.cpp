#include <iostream>
using namespace std;
#include "LinkList.cpp"
int main() {
	int r[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    LinkList<int> L(r, 10);
    cout<<"ִ�в������ǰ�ĵ���������Ϊ��"<<endl;
    L.PrintList(); /*��ʾ�����������е�Ԫ��*/
    try{
		L.Insert(7, 12);
	}
    catch (char *str) {
        cout<<str<<endl;
	}
    cout<<"ִ�в��������ĵ���������Ϊ��"<<endl;
    L.PrintList(); /*��ʾ������������Ԫ��*/
    cout<<"ֵΪ15��Ԫ��λ��Ϊ:";
    cout<<L.Locate(15)<<endl; /*����Ԫ��15���������ڵ�������λ��*/
    int length = L.Length();
	cout<<"��ǰ������ı�Ϊ��"<<length<<endl;
    cout<<"ִ��ɾ������ǰ����Ϊ��"<<endl;     
    L.PrintList(); /*��ʾ�����������е�Ԫ��*/
    try{
		L.Delete(6); /*ɾ����6��Ԫ�ؽ��*/
	}
    catch (char *str) {
		cout<<str<<endl;
	}
    cout<<"ִ��ɾ������������Ϊ��"<<endl; 
    L.PrintList(); /*��ʾ������������Ԫ��*/
    return 0;
}
