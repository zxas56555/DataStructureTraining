#include <iostream>
#include "LinkList.cpp"
using namespace std;
int main() {
	int r[10] = {3,6,8,9,1,12,16,18,20,19};
    LinkList<int> L(r, 10);
    cout<<"ִ�в������ǰ�ĵ���������Ϊ��"<<endl;
    L.PrintList(); /*��ʾ�����������е�Ԫ��*/
    try{
		L.Insert(3, 0);
	}
    catch (char *str) {
        cout<<str<<endl;
	}
    cout<<"ִ�в��������ĵ���������Ϊ��"<<endl;
    L.PrintList(); /*��ʾ������������Ԫ��*/
    cout<<"ֵΪ18��Ԫ��λ��Ϊ:";
    cout<<L.Locate(18)<<endl; /*����Ԫ��18���������ڵ�������λ��*/
    int length = L.Length();
	cout<<"��ǰ������ı�Ϊ��"<<length<<endl;
    cout<<"ִ��ɾ������ǰ����Ϊ��"<<endl;
    L.PrintList(); /*��ʾ�����������е�Ԫ��*/
    try{
		L.Delete(8); /*ɾ����8��Ԫ�ؽ��*/
	}
    catch (char *str) {
		cout<<str<<endl;
	}
    cout<<"ִ��ɾ������������Ϊ��"<<endl;
    L.PrintList(); /*��ʾ������������Ԫ��*/
    cout<<"\n�˲��������������"<<endl;
    return 0;
}
